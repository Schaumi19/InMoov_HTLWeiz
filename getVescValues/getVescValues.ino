

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

bool JOYactiv = false; 

int RPM1 = 0;
int RPM2 = 0;

int sRPM1 = 0;
int sRPM2 = 0;

int rRPM1 = 0;
int rRPM2 = 0;

int count = 0;
int lastcount = 0;

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

}

void loop() {
  if(count > lastcount + 100){
    Serial3.print(count);
    lastcount += 100;
  } else if(lastcount > count){
    lastcount = 0;
  }
  count ++;
  
  Joystick();
  VESC_Comm();
}


void Joystick(){
    if(digitalRead(Sel) == LOW){

      JOYactiv = true;

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
    else if(JOYactiv)
    {
      RPM1 = 0;
      RPM2 = 0;
      JOYactiv = false;
    }
}


void VESC_Comm(){
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
  UART.setRPM(RPM2); //0 - 9000
}
