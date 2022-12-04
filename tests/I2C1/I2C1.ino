// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI Peripheral device
// Refer to the "Wire Peripheral Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire.begin(2); // join i2c bus (address optional for master)
  Wire.onReceive(receiveEvent);
  Serial.begin(115200);
  Serial.print("Test");
}

byte x = 0;

void loop()
{/*
  Wire.beginTransmission(4); // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(4);              // sends one byte  
  Wire.endTransmission();    // stop transmitting

  x++;*/
  delay(1000);
}

void receiveEvent(int howMany)
{
  Serial.println("rec");
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}
