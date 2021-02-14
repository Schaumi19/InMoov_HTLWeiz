

/*
 
  Author: Manuel Schaumberger
  
  Library Author:  SolidGeek
  
*/

#include <VescUart.h>


const byte Sel = 2;
const byte VJoystick = 1;
const byte HJoystick = 0;

/** Initiate VescUart class */
VescUart UART;

bool activ = false;

int RPM1 = 0;
int RPM2 = 0;

int sRPM1 = 0;
int sRPM2 = 0;

int rRPM1 = 0;
int rRPM2 = 0;

int Current;

void setup() {

  pinMode(VJoystick, INPUT);
  pinMode(HJoystick, INPUT);
  pinMode(Sel, INPUT_PULLUP);
  
  // Setup Serial port to display data
  Serial.begin(115200);

  // Setup UART port (für VESC) 
  Serial1.begin(115200);
  Serial2.begin(115200);

  // UART (für HMI(Controll Box))
  Serial3.begin(9600);
  
  while (!Serial) {;}


}

void loop() {

if (Serial.available() > 0) {
    Current = Serial.parseInt();
    Serial.print("Current: ");
    Serial.println(Current);
    SetVESCCurrent(Current);
  }



if(digitalRead(Sel) == LOW){

  activ = true;

  RPM1 = 18 * (analogRead(VJoystick)-514) ;
  RPM2 = 18 * (analogRead(VJoystick)-514);
  //Serial.println(sRPM1);

  if(abs(RPM1) < 100){
    RPM1 = 0;
  }
  if(abs(RPM2) < 100){
    RPM2 = 0;
  }
 }
 else{
  RPM1 = 0;
  RPM2 = 0;
 }


  
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

  if(activ){
      UART.setRPM(RPM1); //0 - 9000

  }


  
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
  if(activ){
      UART.setRPM(RPM2); //0 - 9000
      activ = false;
  }


 //delay(500);

  //Serial.println();

}

void SetVESCCurrent(byte current){
  UART.setSerialPort(&Serial1);
  //UART.setMaxCurrent(current);
  UART.setSerialPort(&Serial2);
  //UART.setMaxCurrent(current);
}
