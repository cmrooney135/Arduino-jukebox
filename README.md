# Renovated Arduino Jukebox

This project modernizes a classic jukebox radio into a fully functional music player using an Arduino Uno microcontroller. It features an interactive song selection mechanism, vibrant LEDs, and high-quality audio playback.

<img src="jukebox_sticker.png" alt="Jukebox Design" width="300" height="300">



## Features

- **LCD Display**: Shows song titles, artists, albums, and years.
- **Rotary Encoder**: Allows users to scroll through a song list and select a song.
- **Song Playback**: Plays 36 songs stored on an SD card in WAV format.
- **Audio System**: Uses an LM386 audio amplifier and the original jukebox speaker for high-quality sound.
- **On/Off and Volume Control**: Integrated into a single knob from the original jukebox.

## Components

- Arduino Uno (2 units)
- 128 GB microSD card with reader module
- Rotary encoder
- LCD display
- LM386 audio amplifier chip
- Speaker from the original jukebox
- LEDs for visual effects
- B10K potentiometer for power and volume control

## Getting Started

### Prerequisites

- Arduino IDE installed on your computer.
- Libraries required:
  - `SD.h`
  - `TMRpcm.h`
  - `Wire.h`
  - `LiquidCrystal_I2C.h`
  - `RotaryEncoder.h`

### Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/cmrooney135/Arduino-jukebox.git
   ```
2. Open the provided `.ino` files in the Arduino IDE.
3. Install the required libraries via the Arduino Library Manager.
4. Upload the host sender code to one Arduino and the proxy reader code to the other.

### Wiring Diagram

#### Host Board (LCD & Rotary Encoder):
- **Rotary Encoder**:
  - Pin A to A2
  - Pin B to A3
  - Button to D7
- **LCD Display**:
  - SDA to A4
  - SCL to A5
  - VCC to 5V
  - GND to GND

#### Proxy Board (SD Card & Audio System):
- **SD Card Reader**:
  - CS to D10
  - SCK to D13
  - MOSI to D11
  - MISO to D12
  - VCC to 5V
  - GND to GND
- **Audio Output**:
  - Speaker to D9
- **Power/Volume Control**:
  - Potentiometer between battery and Vin.

### Usage

1. Load the songs onto the SD card in a folder named `songs`.
2. Ensure the SD card is formatted as FAT32 and the songs are converted to WAV format with these specs:
   - 8-bit resolution
   - 16000 Hz sampling rate
   - Mono channel
3. Power on the device and use the rotary encoder to navigate and select songs.
4. Enjoy music playback through the speaker.

## Challenges and Solutions

- **Memory Constraints**: Resolved by using two Arduinos connected via I2C communication.
- **Audio Quality**: Enhanced with an LM386 audio amplifier and bypass/coupling capacitors.
- **Library Conflicts**: Switched from OLED to LCD display for better compatibility.
- **Connectivity Issues**: Improved soldering on proto-board for reliability.

## Future Improvements

- Expand song library with external storage.
- Add more interactive lighting effects.
- Implement dynamic volume control via software.
- Integrate Bluetooth for wireless playback.
