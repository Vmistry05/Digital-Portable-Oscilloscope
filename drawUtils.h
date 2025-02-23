#ifndef DRAWUTILS_H
#define DRAWUTILS_H

#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>

void drawFullScreenGUI(Adafruit_ST7789 &tft, int screenWidth, int screenHeight, int midY);
void drawGrid(Adafruit_ST7789 &tft, int screenWidth, int screenHeight);

#endif
