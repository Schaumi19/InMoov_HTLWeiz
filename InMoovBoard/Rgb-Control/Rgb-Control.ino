#include <Adafruit_NeoPixel.h>
#include <stdio.h>
#include <stdint.h>

#define LED_PIN 3
#define LED_COUNT 138

#define ACP_B1 2
#define ACP_B2 0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int RGBON;
unsigned int rspeed;
unsigned int reps=0;  // Max. Wert ist 65535
char incomingByte;

void setup() {
  Serial.begin(115200);
  Serial.println(ACP_B1);
  Serial.println(ACP_B2);

  //strip.begin();
  strip.show();
  strip.setBrightness(255); // Set BRIGHTNESS to about 1/5 (max = 255)

  rainbow(1, 10);
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

void staticColor(int r, int g, int b){
  colorWipe(strip.Color(r,  g,  b), 50);
}

void rainbow(int wait, unsigned int repetitions){
  uint16_t i, j;
  byte *c;

  for(j = 0; j < repetitions * 256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      c=Wheel(((i * 256 / strip.numPixels()) + j) & 255);
      strip.setPixelColor(i, *c, *(c+1), *(c+2));
    }
    strip.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment

    if(RGBON = 0){
      break;
      RGBON = 1;
    }
  }
}

byte * Wheel(byte WheelPos) {
  static byte c[3];

  if(WheelPos < 85) {
   c[0]=WheelPos * 3;
   c[1]=255 - WheelPos * 3;
   c[2]=0;
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   c[0]=255 - WheelPos * 3;
   c[1]=0;
   c[2]=WheelPos * 3;
  } else {
   WheelPos -= 170;
   c[0]=0;
   c[1]=WheelPos * 3;
   c[2]=255 - WheelPos * 3;
  }
  return c;
}

void loop() {
  if (Serial.available()){
    if (Serial.read() == 'R') { //R = Right|RGB; L = Left; M = Middle
      //Serial.println("R_erkannt");
      //delay(1);
      while(!Serial.available());
      char b = Serial.read();
      //delay(1);
      if (b == 'G'){
        while(!Serial.available());
        char b = Serial.read();
        if (b == 'B'){
          while(!Serial.available());
          char b = Serial.read();
          if (b == 'R'){
            while(!Serial.available());
            rainbow(rspeed, reps);
          }
          if (b == 'E'){
            while(!Serial.available());
            while(1) {            // force into a loop until 'n' is received
             incomingByte = Serial.read();
             if (incomingByte == '\n') break;
             if (incomingByte == -1) continue;
             reps *= 10;
             reps = ((incomingByte - 48) + reps);
            }
          }
          else if (b == 'T'){
            staticColor(0,  255,  0);
          }
          else if (b == 'S'){
            while(1) {            // force into a loop until 'n' is received
             incomingByte = Serial.read();
             if (incomingByte == '\n') break;
             if (incomingByte == -1) continue;
             rspeed *= 10;
             rspeed = ((incomingByte - 48) + rspeed);
            }
          }
          else if (b == 'B'){
            while(!Serial.available());
            unsigned int brightness = 0;
            while(1) {            // force into a loop until 'n' is received
              incomingByte = Serial.read();
              if (incomingByte == '\n') break;
              if (incomingByte == -1) continue;
              brightness *= 10;
              brightness = ((incomingByte - 48) + brightness);
            }
            if(brightness > 255){
              brightness = 255;
            }
            strip.setBrightness(brightness);
          }
        }
      }
    }
  }
}
