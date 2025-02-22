Digital Portable Oscilloscope
This project is a Digital Portable Oscilloscope, built using an ESP32 microcontroller and a TFT display to visualize waveforms. The oscilloscope is designed to be portable and features a push button that allows users to pause the waveform display for better inspection of the signal.

Features
Real-time waveform display: Visualize different types of waveforms in real time on the TFT screen.
Push button to pause output: Control the display of the waveform with a button to pause or resume.
Portable: Compact and mobile for easy field use or lab experiments.
ESP32 powered: Using the power of ESP32 to manage signal processing and control.
Components
Here is a list of the key components used in this project:

ESP32 Microcontroller (e.g., ESP32 DevKit V1)
TFT Display (for waveform visualization)
Push Button (to pause/resume waveform output)
Oscilloscope probes (to capture signals)
Resistors, capacitors, and other passive components
Power supply (USB or battery power)
Circuit Connections
Pin Connections for ESP32
TFT Display: Connect the display to the ESP32 as follows:

TFT_CS (Chip Select) -> GPIO 15
TFT_RST (Reset) -> GPIO 4
TFT_DC (Data/Command) -> GPIO 2
TFT_CLK (Clock) -> GPIO 14
TFT_MISO (Master In Slave Out) -> GPIO 12
TFT_MOSI (Master Out Slave In) -> GPIO 13
VCC -> 3.3V power pin
GND -> Ground
Push Button: Connect the push button to a digital input pin:

Push Button -> GPIO 16 (configured as input)
Signal Input: Connect the signal probes to an analog input pin:

Signal Input -> GPIO 34 (Analog input)
Power: Provide power to the ESP32 via the USB or a battery.
