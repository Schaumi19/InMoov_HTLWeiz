

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

int jRPM1 = 0;
int jRPM2 = 0;

int sRPM1 = 0;
int sRPM2 = 0;

int rRPM1 = 0;
int rRPM2 = 0;

int count = 0;
int lastcount = 0;
int maxSpeed = 100000;

float U;

int RPM1;
float I1;

int RPM2;
float I2;

void setup() {

  pinMode(VJoystick, INPUT);
  pinMode(HJoystick, INPUT);
  pinMode(Sel, INPUT_PULLUP);

  // Setup Serial port to display data
  Serial.begin(9600);

  // Setup UART port (für VESC)
  Serial1.begin(115200);
  Serial2.begin(115200);

  // UART (für HMI(Controll Box))
  Serial3.begin(9600);

}

int Joystick() {
  if (digitalRead(Sel) == LOW) {
    
    JOYactiv = true;
    
    Serial.println(analogRead(VJoystick) - 512);
    
    if(jRPM1 < analogRead(VJoystick) - 512){      
      if(jRPM1 > 0)
        jRPM1 -= 150;

      if(jRPM1 < 0)
        jRPM1 -= 50;
      
      if(jRPM2 > 0)
        jRPM2 -= 150;

      if(jRPM2 < 0)
        jRPM2 -= 50;
    }

    if(jRPM1 > analogRead(VJoystick) - 512){
      if(jRPM1 < 0)
        jRPM1 += 150;

      if(jRPM1 > 0)
        jRPM1 += 50;
      
      if(jRPM2 < 0)
        jRPM2 += 150;

      if(jRPM2 > 0)
        jRPM2 += 50;
    }
    
    jRPM1 += ((analogRead(HJoystick) - 512) / 4);      
    jRPM2 -= ((analogRead(HJoystick) - 512) / 4);
    
  }
  
  else if (JOYactiv)
  {
    jRPM1 = 0;
    jRPM2 = 0;
    JOYactiv = false;
  }

  else{
    return false;
  }
}

void SerialStr() {

  if(Serial.read() == 'm'){
    
    char b = Serial.read();
    Serial.println(b);

    if(b == 'f'){
      jRPM1 = -700;
      jRPM2 = -700;
    }

    else if(b == 'b'){
      jRPM1 = 700;
      jRPM2 = 700;
    }

    else if(b == 's'){
      jRPM1 = 0;
      jRPM2 = 0;
    }

    else if(b == 'l'){
      if(Serial.read() == 'b'){
        jRPM1 = 0;
        jRPM2 = 800;
      }
      
      else{  
        jRPM1 = 0;
        jRPM2 = -800;
      }
    }

    else if(b == 'r'){
      if(Serial.read() == 'b'){
        jRPM1 = 800;
        jRPM2 = 0;
      }
      
      else{  
        jRPM1 = -800;
        jRPM2 = 0;
      }
    }
    
    else{
      jRPM1 = Serial.parseInt() * -1;
      jRPM2 = Serial.parseInt() * -1;
    }
    
  }
  
}

void VESC_Comm() {
  UART.setSerialPort(&Serial1);

  //Serial.println("VESC1");
  if ( UART.getVescValues() ) {

    rRPM1 = UART.data.rpm;
    U = UART.data.inpVoltage;
    RPM1 = UART.data.rpm;
    I1 = UART.data.avgInputCurrent;

/*
    Serial.print("V: ");
    Serial.print(U);
    Serial.print(" RPM1: ");
    Serial.print(RPM1 / 7);
    Serial.print(" I1: ");
    Serial.print(I1);
*/

    Serial3.print('p');
    Serial3.print(U);
    Serial3.print('\n');
    Serial3.print(RPM1 / 7);
    Serial3.print('\n');
    Serial3.print(I1);
    Serial3.print('\n');

  }
  else
  {
    Serial.println("Failed to get data!");
  }

  if(jRPM1 > maxSpeed && jRPM1 > 0)
    UART.setRPM(maxSpeed); //links

  else if(jRPM1 < maxSpeed - maxSpeed - maxSpeed && jRPM1 < 0)
    UART.setRPM(maxSpeed - maxSpeed - maxSpeed);
  
  else{
    UART.setRPM(jRPM1);
  }
  
  if(jRPM1 == 0 && UART.data.rpm != 0)
    UART.setBrakeCurrent(15.0f);
    
  UART.setSerialPort(&Serial2);

  //Serial.println("VESC2");
  if ( UART.getVescValues() ) {

    rRPM2 = UART.data.rpm;
    RPM2 = UART.data.rpm;
    I2 = UART.data.avgInputCurrent;

/*
    Serial.print(" RPM2: ");
    Serial.print(RPM2 / 7);
    Serial.print(" I2: ");
    Serial.println(I2);
*/

    Serial3.print(RPM2 / 7);
    Serial3.print('\n');
    Serial3.print(I2);
    Serial3.print('\n');

  }
  else
  {
    Serial.println("Failed to get data!");
  }
  
  if(jRPM2 > maxSpeed && jRPM2 > 0)
    UART.setRPM(maxSpeed); //links

  else if(jRPM2 < maxSpeed - maxSpeed - maxSpeed && jRPM2 < 0)
    UART.setRPM(maxSpeed - maxSpeed - maxSpeed);
  
  else{
    UART.setRPM(jRPM2);
  }
  
  if(jRPM2 == 0 && UART.data.rpm != 0)
    UART.setBrakeCurrent(15.0f);
}

void loop() {
  if(Joystick());
  else{
    SerialStr();
  }
  VESC_Comm();
}
