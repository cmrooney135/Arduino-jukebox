//inputs from the rotary encoder then sends it to the OLED. sends the index of the song to emily 
#include <Wire.h>
#include <avr/pgmspace.h> // Required for PROGMEM
#include <Arduino.h>
#include <RotaryEncoder.h>
#include "music_data.h"
#include <LiquidCrystal_I2C.h>


#define PIN_IN1 A2
#define PIN_IN2 A3
#define BUTTON_PIN 7
byte dataToSend = -1;



RotaryEncoder encoder(PIN_IN1, PIN_IN2, RotaryEncoder::LatchMode::TWO03);
LiquidCrystal_I2C lcd(0x27, 16, 2);

 
// Helper function to read a string from PROGMEM
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

void setup() {
  Wire.begin(); 
  Serial.begin(9600);  // start serial for output
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up resistor
  lcd.init();
  //lcd.clear();
  lcd.backlight(); // Turn on the backlight
  lcd.setCursor(0, 0); // Set cursor to column 0, row 0
  lcd.print("Arduino Jukebox!"); // Print first line
  lcd.setCursor(0, 1); // Set cursor to column 0, row 1
  lcd.print("Scroll to Select"); // Print second line

}

void loop() {
  static int pos = 0;
  static bool lastButtonState = HIGH; // Initial button state (not pressed)

  encoder.tick();

  // Read and process rotary encoder position
  int newPos = encoder.getPosition();
  //Serial.println(newPos);
  if (newPos > 72) {
    newPos = 72;
  }
  if (newPos < 0) {
    newPos = 0;
  }

  // Adjust position to make it even if necessary
  if (newPos % 2 != 0) {
    newPos++;
  }
  if (pos != newPos) {
    //display.clearDisplay();
    // Calculate the index as position divided by 2
    int index = newPos / 2;

    // Print the index
    Serial.print("index: ");
    Serial.println(index);
    //add the code to print the stuff about the song here 
    String songDetails = getFileName(index);
    //Serial.println("file name : " + songDetails);

    int firstDelimiter = songDetails.indexOf("--");
    int secondDelimiter = songDetails.indexOf("--", firstDelimiter + 2);
    int thirdDelimiter = songDetails.indexOf("--", secondDelimiter + 2);

    String name = songDetails.substring(0, firstDelimiter); // Song name
    String album = songDetails.substring(firstDelimiter + 2, secondDelimiter); // Album name
    String artist = songDetails.substring(secondDelimiter + 2, thirdDelimiter); // Artist name
    String yearWithExtension = songDetails.substring(thirdDelimiter + 2); // Year with file extension (e.g., "2024.wav")

    // To remove the file extension (".wav") from the year part
    int fileExtensionIndex = yearWithExtension.indexOf(".wav");
    String year = yearWithExtension.substring(0, fileExtensionIndex);

    Serial.println("Song: " + name);
    Serial.println("Album: " + album);
    Serial.println("Artist: " + artist);
    Serial.println("Year: " + year);
    lcd.clear();
    lcd.setCursor(0, 0); // Set cursor to column 0, row 0
    lcd.print(name); // Print first line
    lcd.setCursor(0, 1); // Set cursor to column 0, row 1
    lcd.print(artist); // Print second line
    pos = newPos;
  }
  bool currentButtonState = digitalRead(BUTTON_PIN);
  if (lastButtonState == HIGH && currentButtonState == LOW) { // Button press detected
    String fileName = getFileName(pos/2);
    //usic(fileName);
    Serial.print("Button pressed at position: ");
    Serial.println(pos / 2); // Print the position when the button was pressed
    dataToSend = pos/2;
    Wire.beginTransmission(4); // transmit to device #4
     Wire.write(dataToSend);              // sends one byte
     Serial.print("Sent index ");
     Serial.println(dataToSend);
    Wire.endTransmission();    // stop transmitting
    Serial.println("Playing song : " + fileName);
    String songTitle = getSongName(dataToSend);
    //scroll if title is longer than 16 char 
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Now Playing: ");
    lcd.setCursor(0, 1);
    lcd.print(songTitle);


    delay(50); // Debounce delay
    

  }
  lastButtonState = currentButtonState;

  }
  

  String getSongName(int index){
    String songDetails = getFileName(index);

    int firstDelimiter = songDetails.indexOf("--");
    int secondDelimiter = songDetails.indexOf("--", firstDelimiter + 2);
    int thirdDelimiter = songDetails.indexOf("--", secondDelimiter + 2);

    String name = songDetails.substring(0, firstDelimiter); // Song name
    return name;

  }

  String getSongArtist(int index){
      String songDetails = getFileName(index);

      
      int firstDelimiter = songDetails.indexOf("--");
    int secondDelimiter = songDetails.indexOf("--", firstDelimiter + 2);
    int thirdDelimiter = songDetails.indexOf("--", secondDelimiter + 2);

    String artist = songDetails.substring(secondDelimiter + 2, thirdDelimiter); // Artist name
    return artist;
  }

  String getSongAlbum(int index){
    String songDetails = getFileName(index);

    int firstDelimiter = songDetails.indexOf("--");
    int secondDelimiter = songDetails.indexOf("--", firstDelimiter + 2);
    int thirdDelimiter = songDetails.indexOf("--", secondDelimiter + 2);

    String album = songDetails.substring(firstDelimiter + 2, secondDelimiter); // Album name
      return album;
  }

  String getSongYear(int index){
    String songDetails = getFileName(index);
    int firstDelimiter = songDetails.indexOf("--");
    int secondDelimiter = songDetails.indexOf("--", firstDelimiter + 2);
    int thirdDelimiter = songDetails.indexOf("--", secondDelimiter + 2);
    String yearWithExtension = songDetails.substring(thirdDelimiter + 2); // Year with file extension (e.g., "2024.wav")
    int fileExtensionIndex = yearWithExtension.indexOf(".wav");
    String year = yearWithExtension.substring(0, fileExtensionIndex);
    return year;
  }

  void scrollText(String text, int delayMs) {
  int displayWidth = 16;  // Width of the LCD in characters
  int textLength = text.length();

  if (textLength <= displayWidth) {
    // If the text fits within the display, show it without scrolling
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Now Playing: ");
    lcd.setCursor(0, 1);

    lcd.print(text);
    delay(2000); // Keep the text displayed for a while
  } else {
    // Scroll the text if it is longer than the display width
    for (int i = 0; i < textLength - displayWidth + 1; i++) {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print(text.substring(i, i + displayWidth)); // Display a substring of the text
      delay(delayMs);
    }
  }
}
