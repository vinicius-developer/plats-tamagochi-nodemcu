#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void setupDisplay();

void showBitmap(char* mood);

void selectBitmap(long isRaining, int soil, float humidity);