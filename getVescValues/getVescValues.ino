

/*
  Name:    getVescValues.ino
  Created: 19-08-2018
  Author:  SolidGeek
  Description:  This example is made using a Arduino Micro (Atmega32u4) that has a HardwareSerial port (Serial1) seperated from the Serial port. 
                A Arduino Nano or Uno that only has one Serial port will not be able to display the data returned.
*/

#include <VescUart.h>
//#include <Adafruit_NeoPixel.h>
//#include <avr/power.h>

#define Sel            2
#define VJoystick      1
#define HJoystick      0

//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, RGB_PIN, NEO_GRB + NEO_KHZ800);

/** Initiate VescUart class */
VescUart UART;

int delayval = 0;

int RPM1 = 0;
int RPM2 = 0;

int sRPM1 = 000;
int sRPM2 = 000;

int rRPM1 = 0;
int rRPM2 = 0;

void setup() {

  pinMode(VJoystick, INPUT);
  pinMode(Sel, INPUT_PULLUP);
  /** Setup Serial port to display data */
  Serial.begin(9600);

  /** Setup UART port (Serial1 on Atmega32u4) */
  Serial1.begin(115200);
  Serial2.begin(115200);
  
  while (!Serial) {;}

/*  pixels.begin();


  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(55,55,55)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,1)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayval); // Delay for a period of time (in milliseconds).
  }
  /** Define which ports to use as UART */
  UART.nunchuck.valueY = 127;
}

void loop() {
RPM1 = 0;
RPM2 = 0;
if(digitalRead(Sel) == LOW){
  //UART.setNunchuckValues();
  sRPM1 = 18 * (analogRead(VJoystick)-514) ;
  sRPM2 = 18 * (analogRead(VJoystick)-514);
  Serial.println(sRPM1);

  RPM1 = sRPM1;
  RPM2 = sRPM2;

  if(abs(RPM1) < 100){
    RPM1 = 0;
  }
  if(abs(RPM2) < 100){
    RPM2 = 0;
  }
 }

/*
if(sRPM1 > 0){
    if(((float)sRPM1+200)/sRPM2 < (float)rRPM1/rRPM2){
  RPM1 = rRPM2;
}
else{
  RPM1 = sRPM1;
}
} else{
    if(((float)sRPM1-200)/sRPM2 < (float)rRPM1/rRPM2){
  RPM1 = rRPM2;
}
else{
  RPM1 = sRPM1;
}
}
if(sRPM2 > 0){
  
if((float)sRPM1-200/sRPM2 > ((float)rRPM1)/rRPM2){
  RPM2 = rRPM1;
}
else{
  RPM2 = sRPM2;
}
}else{
  if((float)sRPM1+200/sRPM2 > ((float)rRPM1)/rRPM2){
  RPM2 = rRPM1;
}
else{
  RPM2 = sRPM2;
}
}

*/
  /** Call the function getVescValues() to acquire data from VESC */
  UART.setSerialPort(&Serial1);
  
  //Serial.println("VESC1");
  if ( UART.getVescValues() ) {
    Serial.print("RPM1: ");
    Serial.print(UART.data.rpm);
    rRPM1 = UART.data.rpm;
    //Serial.print(" ; ");
    /*
    Serial.print("V: ");
    Serial.println(UART.data.inpVoltage);
    Serial.print("I: ");
    Serial.println(UART.data.avgInputCurrent);
    */
    
  }
  else
  {
    Serial.println("Failed to get data!");
    
  }
  //UART.nunchuck.lowerButton = true;
  
  //UART.setNunchuckValues();
  
  UART.setRPM(RPM1); //0 - 9000


  
  UART.setSerialPort(&Serial2);
  
  //Serial.println("VESC2");
  if ( UART.getVescValues() ) {
    Serial.print("RPM2: ");
    Serial.println(UART.data.rpm);
    rRPM2 = UART.data.rpm;
    /*
    Serial.print("V: ");
    Serial.println(UART.data.inpVoltage);
    Serial.print("I: ");
    Serial.println(UART.data.avgInputCurrent);
    */
  }
  else
  {
    Serial.println("Failed to get data!");
    
  }
  //UART.nunchuck.lowerButton = true;
  //UART.setNunchuckValues();
  UART.setRPM(RPM2); //0 - 9000




  //Serial.println();


  
}
