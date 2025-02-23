#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <math.h>
#include "BluetoothSerial.h"
#include "drawUtils.h"  // Include the header for drawing functions

#define TFT_CS     14   
#define TFT_RST    15   
#define TFT_DC     32   
#define TFT_SCK    18  
#define TFT_MOSI   23  
#define ADC_PIN    4   // ADC input from signal source
#define BUTTON_PIN 5   // Push button to pause/resume

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);
BluetoothSerial SerialBT;

const int screenWidth = 240;
const int screenHeight = 320;
const int midY = screenHeight / 2;  // Center Y position (0V)

int prevY[screenWidth];  // Store previous Y values for clearing
bool isPaused = false;

void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP32_Scope"); // Bluetooth device name
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    tft.init(240, 320);
    tft.setRotation(0);

    drawFullScreenGUI(tft, screenWidth, screenHeight, midY);  // Call the function from drawUtils.cpp
    memset(prevY, midY, sizeof(prevY)); // Initialize previous Y positions
}

void loop() {
    static int x = 0;

    if (digitalRead(BUTTON_PIN) == LOW) {  // Detect button press
        delay(200); // Debounce delay
        isPaused = !isPaused;
    }

    if (!isPaused) {
        int adcValue = analogRead(ADC_PIN);
        float voltage = adcValue * (3.3 / 4095.0);

        Serial.print("ADC: "); Serial.print(adcValue);
        Serial.print(" | Voltage: "); Serial.println(voltage);
        SerialBT.print("ADC: "); SerialBT.print(adcValue);
        SerialBT.print(" | Voltage: "); SerialBT.println(voltage);

        int y = map(adcValue, 0, 4095, screenHeight / 2, 0);
        tft.drawPixel(x, prevY[x], ST77XX_BLACK);
        tft.drawPixel(x, y, ST77XX_GREEN);
        prevY[x] = y;

        x++;
        if (x >= screenWidth) {  
            x = 0;
        }
    }
}
