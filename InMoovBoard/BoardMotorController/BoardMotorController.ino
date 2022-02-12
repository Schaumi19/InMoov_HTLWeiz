/*

  Author: Manuel Schaumberger / Thomas Baumkircher

  Library Author: SolidGeek

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
  Serial.begin(115200);

  // Setup UART port (für VESC)
  Serial1.begin(115200);
  Serial2.begin(115200);

  // UART (für HMI(Controll Box))
  Serial3.begin(9600);

  //while(!Serial.available())
    //Serial.write("6");
    
  //UART.setSerialPort(&Serial1);
    //UART.setBrakeCurrent(30);
}

int Joystick() {
  if (digitalRead(Sel) == LOW) {      //if the Joystick button isn't pressed you can't control
    
    JOYactiv = true;
    
    //Serial.println(analogRead(VJoystick) - 512);

    if(((analogRead(VJoystick) - 512) > 20) || ((analogRead(VJoystick) - 512) < -20)){
      int tempRPM = -(analogRead(VJoystick) - 512)*2.5;
      jRPM1 = tempRPM + ((analogRead(HJoystick) - 512));
      jRPM2 = tempRPM - ((analogRead(HJoystick) - 512));
    }else{
      jRPM1 = 0;
      jRPM2 = 0;
    }
    
    //jRPM1 = 800;
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

void SerialStr() {                // Get data from Main Serial(or USB)
                                  // Data: Motor speeds

  if(Serial.read() == 'm')
  {
    jRPM1 = Serial.parseInt();
    Serial3.readStringUntil(',');
    jRPM2 = Serial.parseInt();
  }
}


void BLEStr() {                   // Get data from HMI(Display) 
  int dataBLE = Serial3.read();
  Serial.write(dataBLE);                             // Data: BLE Motor speeds + later Mode(Race,Transprt,InMoov)
  if(dataBLE == 'm')
  {
    jRPM1 = Serial3.parseInt();
    Serial3.readStringUntil(',');
    jRPM2 = Serial3.parseInt();
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
    //Serial.println("Failed to get data!");
  }
  /*
  if(jRPM1 > maxSpeed && jRPM1 > 0)
    UART.setRPM(maxSpeed); //links

  else if(jRPM1 < maxSpeed - maxSpeed - maxSpeed && jRPM1 < 0)
    UART.setRPM(maxSpeed - maxSpeed - maxSpeed);
  
  else{
    
  }
  */
  UART.setRPM(jRPM1);
  
  //if(jRPM1 == 0 && UART.data.rpm != 0)
    //UART.setBrakeCurrent(15.0f);
    
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
    //Serial.println("Failed to get data!");
  }
  
  /*
  if(jRPM2 > maxSpeed && jRPM2 > 0)
    UART.setRPM(maxSpeed); //links

  else if(jRPM2 < maxSpeed - maxSpeed - maxSpeed && jRPM2 < 0)
    UART.setRPM(maxSpeed - maxSpeed - maxSpeed);
  
  else{
  }
  */
  
  UART.setRPM(jRPM2);
  
  //if(jRPM2 == 0 && UART.data.rpm != 0)
    //UART.setBrakeCurrent(15.0f);
}

void loop() {
  if(!Joystick());
  {
    SerialStr();
    BLEStr();
  }
  VESC_Comm();
}
