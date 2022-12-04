// Wire Peripheral Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI Peripheral device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void setup()
{
  Wire.begin(4);                // join i2c bus with address #4
  //Wire.onReceive(receiveEvent); // register event
  Serial.begin(115200);           // start serial for output
  Serial.print("Test");
}

void loop()
{
  delay(1000);
  Wire.beginTransmission(2); // transmit to device #4
  Wire.write("x is ");        // sends five bytes
  Wire.write(5);              // sends one byte  
  Wire.endTransmission();    // stop transmitting
  Serial.println("End");
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  Serial.println(x);         // print the integer
}
