# Digital Portable Oscilloscope

This project is a Digital Portable Oscilloscope built using the ESP32 microcontroller and a TFT display to visualize waveforms. The oscilloscope includes a push button to pause and resume the waveform display.

## Features
- Real-time waveform display on the TFT screen.
- Pause/resume functionality with a push button.
- Portable design powered by ESP32.

## Components
- ESP32 microcontroller
- TFT Display (ST7789)
- Push Button
- Signal Probes
- Resistors, capacitors, and other passive components

## Circuit Connections
- TFT Display connected to ESP32 pins for communication and control.
- Push Button for pausing/resuming waveform display.
- Signal Input to ESP32's ADC pin.

## Software Setup
- Open the `DigitalPortableOscilloscope.ino` file in the Arduino IDE.
- Install required libraries: `Adafruit_GFX`, `Adafruit_ST7789`, and `BluetoothSerial`.

## Usage
1. Upload the code to your ESP32.
2. Connect the signal source to the input pin.
3. Use the push button to pause/resume the waveform display.

## Dependencies
This project requires the following libraries:
- Adafruit_GFX: For graphics on the TFT display.
- Adafruit_ST7789: For interfacing with the ST7789 TFT display.
- BluetoothSerial: For Bluetooth communication with the ESP32.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
