#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include "drawUtils.h"

// Draw the full screen GUI with grid and axis lines
void drawFullScreenGUI(Adafruit_ST7789 &tft, int screenWidth, int screenHeight, int midY) {
    tft.fillScreen(ST77XX_BLACK);
    drawGrid(tft, screenWidth, screenHeight);  // Call drawGrid from the same file
    tft.drawFastHLine(0, midY, screenWidth, ST77XX_WHITE);
    tft.drawFastVLine(screenWidth / 2, 0, screenHeight, ST77XX_WHITE);
    tft.setTextColor(ST77XX_WHITE);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.print("Time (ms)");
    tft.setCursor(10, screenHeight - 30);
    tft.print("Voltage (V)");
}

// Draw grid lines on the display
void drawGrid(Adafruit_ST7789 &tft, int screenWidth, int screenHeight) {
    int columnSpacing = screenWidth / 8;
    for (int i = 1; i < 8; i++) {
        int x = i * columnSpacing;
        tft.drawFastVLine(x, 0, screenHeight, ST77XX_BLUE);
    }

    int rowSpacing = screenHeight / 10;
    for (int i = 1; i < 10; i++) {
        int y = i * rowSpacing;
        tft.drawFastHLine(0, y, screenWidth, ST77XX_BLUE);
    }
}
