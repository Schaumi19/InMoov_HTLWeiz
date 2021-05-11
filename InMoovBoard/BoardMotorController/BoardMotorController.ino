

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
  Serial.begin(115200);

  // Setup UART port (für VESC)
  Serial1.begin(115200);
  Serial2.begin(115200);

  // UART (für HMI(Controll Box))
  Serial3.begin(9600);

}


void Joystick() {
  if (digitalRead(Sel) == LOW) {
    JOYactiv = true;

    size_t i = 0, timerlast = 0;
    while (i < (18 * (analogRead(VJoystick) - 514)))
    {
      if(millis() > timerlast + 10)
      {
        jRPM1++;
        jRPM2++;
        i++;
        timerlast = millis();
      }
    }

    if (abs(jRPM1) < 100) {
      jRPM1 = 0;
    }
    if (abs(jRPM2) < 100) {
      jRPM2 = 0;
    }
  }
  else if (JOYactiv)
  {
    jRPM1 = 0;
    jRPM2 = 0;
    JOYactiv = false;
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

    Serial.print("V: ");
    Serial.print(U);
    Serial.print(" RPM1: ");
    Serial.print(RPM1 / 7);
    Serial.print(" I1: ");
    Serial.print(I1);

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
  if(jRPM1 <= 321)
    UART.setRPM(jRPM1);
  else{
    UART.setRPM(321);
  }


  UART.setSerialPort(&Serial2);

  //Serial.println("VESC2");
  if ( UART.getVescValues() ) {

    rRPM2 = UART.data.rpm;
    RPM2 = UART.data.rpm;
    I2 = UART.data.avgInputCurrent;


    Serial.print(" RPM2: ");
    Serial.print(RPM2 / 7);
    Serial.print(" I2: ");
    Serial.println(I2);

    Serial3.print(RPM2 / 7);
    Serial3.print('\n');
    Serial3.print(I2);
    Serial3.print('\n');

  }
  else
  {
    Serial.println("Failed to get data!");

  }
  if(jRPM2 <= 321)
    UART.setRPM(jRPM2);
  else{
    UART.setRPM(321);
  }
}

void loop() {
  Joystick();
  VESC_Comm();
}
