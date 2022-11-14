#include <Adafruit_NeoPixel.h>
#include <stdio.h>
#include <stdint.h>

#define LED_PIN 3
#define LED_COUNT 138

#define ACP_B1 2
#define ACP_B2 0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

bool USB_Serial_connected = false;
enum modes {off, rainbowing, colorWipeing};
modes RGBmode = off;
bool waiting = false;
unsigned long waitStartTime = 0;
int i,j;
int wait = 0;
uint32_t color;

void setup() {

  Serial.begin(115200);

  //strip.begin();
  strip.show();
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)
  wait = 0;
  rainbow();
}


void loop() {
  if(!USB_Serial_connected)
  {
    if(Serial){
      USB_Serial_connected = true;
      Serial.write(ACP_B1); //Send Identifikation if new connection
      Serial.write(ACP_B2);
    }
  }else if (!Serial)
  {
    USB_Serial_connected = false;
  }

  if(USB_Serial_connected){
    SerialStr();
  }
  else
    RGBmode = off;
  
  switch (RGBmode)
  {
  case off:
    color = strip.Color(0,  0,  0);
    colorWipe();
    break;
  
  case rainbowing:
    rainbow();
    break;
  case colorWipeing:
    colorWipe();
  default:
    break;
  }
  
}

void SerialStr() {                // Get data from Main Serial(or USB)
  if(Serial.available())
  {
    if(Serial.read() == ';')
    {
      int modeAndWait = Serial.parseInt(); //Bit 0 is used for mode selection 0=colorwipe 1=rainbow
      if(modeAndWait & 1)
        RGBmode = rainbowing;
      else
        RGBmode = colorWipeing;
      wait = modeAndWait >> 1;
      Serial.readStringUntil(',');
      color = Serial.parseInt();
      //Debugging
      Serial.print("mode: ");
      Serial.print(RGBmode);
      Serial.print("Wait: ");
      Serial.print(wait);
      Serial.print("Color: ");
      Serial.println(color);
      
    }
  }
}

bool unblockingDelay(){
  if(wait = 0)
    return true;
  if(waiting){
    if(millis() >= waitStartTime+wait){
      waiting = false;
      return true;
    }else
      return false;
  }else{
    waitStartTime = millis();
    waiting = true;
  }
  return false;
}

void colorWipe() {
  if(!waiting)
    i = 0;
  for(; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    if(!unblockingDelay())
      return;
  }
}

void rainbow() {
  if(!waiting)
    j=0;
  for(; j<256; j++) {
    if(!waiting)
      i=0;
    for(; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i*1+j) & 255));
    }
    strip.show();
    if(!unblockingDelay())
      return;
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } 
  else if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } 
  else {
    WheelPos -= 170;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

