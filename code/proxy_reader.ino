//recieves index from carol and plays song at that respective index 
#include <Wire.h>
#include <avr/pgmspace.h> // Required for PROGMEM
#include "music_data.h"   // Include the header file
#include "TMRpcm.h"
#include "SPI.h"
#include <Arduino.h>

#define SD_ChipSelectPin 10



TMRpcm tmrpcm;

void getStringFromProgmem(const char* progmemStr, char* buffer, size_t bufferSize) {
    strncpy_P(buffer, progmemStr, bufferSize);
    buffer[bufferSize - 1] = '\0'; // Null-terminate the string
}

 
// Helper function to print song information
String getFileName(uint8_t songIndex) {
    if (songIndex >= musicLibrarySize) {
        Serial.println("Invalid song index!");
        return;
    }
    // Read the Song struct from PROGMEM
    Song song;
    memcpy_P(&song, &musicLibrary[songIndex], sizeof(Song));
 
    // Buffers to hold strings
    char nameBuffer[50];
    char albumBuffer[50];
    char artistBuffer[50];
 
    // Retrieve strings from PROGMEM
    getStringFromProgmem(song.name, nameBuffer, sizeof(nameBuffer));
    getStringFromProgmem(song.album, albumBuffer, sizeof(albumBuffer));
    getStringFromProgmem(song.artist, artistBuffer, sizeof(artistBuffer));
    
    String songDetails = String(nameBuffer) + "--" + String(albumBuffer) + "--" + String(artistBuffer) + "--" + String(song.year) + ".wav";
    //Serial.println("Song details : " + songDetails);
    return songDetails;
}

String getFilePathFromSongsFolder(int index) {
  File songsFolder = SD.open("/songs");
  if (!songsFolder || !songsFolder.isDirectory()) {
    Serial.println("Directory 'songs' not found or is not a folder!");
    return ""; // Return an empty string
  }
 
  int currentIndex = 0;
  while (true) {
    File entry = songsFolder.openNextFile();
    if (!entry) {
      // No more files
      Serial.println("Index out of range: No file at the specified index.");
      songsFolder.close();
      return ""; // Return an empty string
    }
 
    if (!entry.isDirectory()) { // Skip directories
      if (currentIndex == index) {
        String filePath = "/songs/"; // Base path
        filePath += entry.name();   // Append file name
        entry.close();
        songsFolder.close();
        return filePath; // Return the full file path
      }
      currentIndex++;
    }
    entry.close();
  }
}

void playMusic(String fileName)
{
  if(!tmrpcm.isPlaying())
  {
    tmrpcm.play(fileName.c_str());
  }
}

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  tmrpcm.speakerPin=9;
  if(!SD.begin(SD_ChipSelectPin))
    {
      Serial.println("SD fail");
      return;
    }
}

void loop()
{
  delay(100);
}


void receiveEvent(int howMany)
{
  if (howMany > -1) { // Ensure it processes even if index 0 is received
    uint8_t receivedByte = Wire.read(); // Read the byte as an unsigned integer
    Serial.print("Received byte: ");
    Serial.println(receivedByte); // Print the received value
    String fileName = getFilePathFromSongsFolder(receivedByte);
        playMusic(fileName);
        Serial.print("Playing song: ");
        Serial.println(fileName);

  } else {
    Serial.println("No data received or invalid index."); // Debug message for invalid cases
  }
}
