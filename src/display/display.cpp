#include <SPI.h>
#include <Wire.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//images
#include <faceHappy.h>
#include <faceFine.h>
#include <faceSad.h>
#include <faceThirst.h>

// #define PAGE_BUTTON D3

/* Object named display, of the class Adafruit_SSD1306 */
Adafruit_SSD1306 display(128, 64, &Wire);

// uint8_t s = 0, m = 0, h = 0;

char *lastMood = "happy";
bool page = 1;

struct displayData
{
  int temperature;
  int humidity;
  int soil;
};

struct displayData lastDisplayData;

void setupDisplay()
{
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); /* Initialize display with address 0x3C */
  display.clearDisplay();                    /* Clear display */
  display.setTextSize(1);                    /* Select font size of text. Increases with size of argument. */
  display.setTextColor(WHITE);               /* Color of text*/
}

void drawStr(uint8_t x, uint8_t y, char *str)
{
  display.setCursor(x, y); /* Set x,y coordinates */
  display.println(str);
}

void showBitmap(char *mood)
{
  lastMood = mood;

  display.clearDisplay();
  Serial.print(F("Mostrando bitmap: "));
  Serial.println(mood);

  if (mood == "happy")
  {
    display.drawBitmap(0, 0, happyBMP, 128, 64, WHITE);
  }
  else if (mood == "fine")
  {
    display.drawBitmap(0, 0, fineBMP, 128, 64, WHITE);
  }
  else if (mood == "sad")
  {
    display.drawBitmap(0, 0, sadBMP, 128, 64, WHITE);
  }
  else if (mood == "thirst")
  {
    display.drawBitmap(0, 0, thirstBMP, 128, 64, WHITE);
  }

  display.display();
}

void selectBitmap(long isRaining, int soil, float humidity)
{

  if (soil < 5)
  {
    showBitmap("thirst");
  }
  else if (soil < 30 && humidity < 30)
  {
    showBitmap("sad");
  }
  else if (isRaining == 0)
  {
    showBitmap("happy");
  }
  else
  {
    showBitmap("fine");
  }
}

