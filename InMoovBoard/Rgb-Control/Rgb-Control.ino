#include <Adafruit_NeoPixel.h>
#include <Wire.h>

#define LED_PIN 3
#define LED_COUNT 138

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

enum modes
{
  off,
  rainbowing,
  colorWipeing
};
modes RGBmode = rainbowing;
uint32_t color;
unsigned int rainbowCounter = 0;
unsigned int rainbowWait = 0;
unsigned long nextRainbow = 0;
byte colorWipeWait = 0;

const byte i2cAddress = 8;

void setup()
{
  Serial.begin(115200);
  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceive);

  strip.begin();
  strip.show();
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  rainbow();
  Serial.println("Setup");
}

void loop()
{
  readSerial();
  switch (RGBmode)
  {
  case off:
    Serial.println("Off");
    color = strip.Color(0, 0, 0);
    colorWipe();

    break;

  case rainbowing:
    if (millis() >= nextRainbow)
    {
      rainbow();
      nextRainbow = millis() + rainbowWait;
    }
    break;
  case colorWipeing:
    colorWipe();
  default:
    break;
  }
}

// Receiving a message as Slave
void i2cReceive(int howMany)
{
  switch (howMany)
  {
  case 1:
    RGBmode = rainbowing;
    rainbowWait = Wire.read();
    break;
  case 4:
    RGBmode = colorWipeing;
    byte r = Wire.read();
    byte g = Wire.read();
    byte b = Wire.read();
    color = strip.Color(r, g, b);
    colorWipeWait = Wire.read();
    break;
  case 0:
    RGBmode = off;
    break;
  default:
    break;
  }
}

void readSerial()
{
  Serial.println("ReadSerial");
  if (Serial.available())
  {
    if (Serial.read() == 'S')
    {
      Serial.println("Start");
      while (!Serial.available())
        ;
      
      char inChar = Serial.read();
      switch (inChar)
      {
      case 'R':
        Serial.println("Rainbow");
        RGBmode = rainbowing;
        while (!Serial.available())
        ;
        rainbowWait = Serial.parseInt();
        Serial.print("Rainbow: ");
        Serial.println(rainbowWait);
        break;
      case 'C':
        Serial.println("ColorWipe");
        RGBmode = colorWipeing;
        while (Serial.available()<4)
        ;
        byte r = Serial.read();
        Serial.read();
        byte g = Serial.read();
        Serial.read();
        byte b = Serial.read();
        Serial.read();
        color = strip.Color(r, g, b);
        colorWipeWait = Serial.parseInt();
        Serial.print("ColorWipe: ");
        Serial.println(colorWipeWait);
        break;
      case 'O':
        Serial.println("Off");
        RGBmode = off;
        break;
      default:
       Serial.println("Off");
        RGBmode = off;
        break;
      }
      while (!Serial.available())
        ;
    }
  }
}

void colorWipe()
{
  Serial.println("ColorWipe");
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, color);
    strip.show();
  }
}

void rainbow()
{
  Serial.println("Rain");
  if (rainbowCounter >= 255)
    rainbowCounter = 0;
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, Wheel((i * 1 + rainbowCounter) & 255));
  }
  strip.show();
  rainbowCounter++;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
  if (WheelPos < 85)
  {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  else if (WheelPos < 170)
  {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  else
  {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
