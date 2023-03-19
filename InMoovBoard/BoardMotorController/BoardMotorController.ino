/*
  Author: Manuel Schaumberger / Thomas Baumkircher
  Library Author: SolidGeek
*/
#include <Wire.h>
#include <VescUart.h>
VescUart UART;

#define ACP_B1 1
#define ACP_B2 0
byte i2cAddress = 7;

// Time To Live (secs)
#define TTL 1

//Joystick Pinout
const byte Sel = 4;
const byte VJoystick = 3;
const byte HJoystick = 2;

int RPM1_soll = 0;
int RPM2_soll = 0;

float U, I1, I2;
int RPM1, RPM2;

unsigned long ttl_begin = 0;

bool USB_Serial_connected = false;

void setup() {

  pinMode(VJoystick, INPUT);
  pinMode(HJoystick, INPUT);
  pinMode(Sel, INPUT_PULLUP);

  // USB Serial port
  Serial.begin(115200);

  // Setup UART port (für VESC)
  Serial1.begin(115200);
  Serial2.begin(115200);

  // UART (für HMI(Controll Box)) and Bluetooth
  Serial3.begin(9600);

  // I2C
  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceive);
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

  //RPM1_soll = 0;
  //RPM2_soll = 0;

  if(Joystick()){ttl_begin = millis();}
  else if(SerialStr()){ttl_begin = millis();}
  else if(BLEStr()){ttl_begin = millis();}
  

  if((millis() - ttl_begin) >= (TTL * 1000))
  {
    RPM1_soll = 0;
    RPM2_soll = 0;
  }

  VESC_Comm();
}



bool Joystick() {
  // If the Joystick button isn't pressed you can't control
  if (digitalRead(Sel) == LOW) {
    Serial.print("Joy");
    if(((analogRead(VJoystick) - 512) > 20) || ((analogRead(VJoystick) - 512) < -20)){
    
      int tempRPM = -(analogRead(VJoystick) - 512);
      RPM1_soll = (tempRPM + ((analogRead(HJoystick) - 512)))*1.2;
      RPM2_soll = (tempRPM - ((analogRead(HJoystick) - 512)))*1.2;
      Serial.print(analogRead(VJoystick));
      Serial.print(" ");
      Serial.println(analogRead(HJoystick));
    }
    else
    {
      RPM1_soll = 0;
      RPM2_soll = 0;
    }
    return true;
  }
  return false;
}

// Receiving a message as Slave
void i2cReceive(int howMany)
{
  if (howMany == 2)
  { // If two bytes were received
    RPM1_soll = Wire.read();
    RPM2_soll = Wire.read();
    ttl_begin = millis();
  }
}

bool SerialStr() {                // Get data from Main Serial(or USB)
  if(Serial.available())
  {
    if(Serial.read() == ';')
    {
      RPM1_soll = -1 * Serial.parseInt();
      Serial.readStringUntil(',');
      RPM2_soll = -1 * Serial.parseInt();
      Serial.print(RPM1_soll);
      return true;
    }
  }
  return false;
}


bool BLEStr() {                   // Get data from HMI(Display) (Bluetooth)
  if (Serial3.available())
  {
    int dataBLE = Serial3.read();
    if(dataBLE == 'm')
    {
      RPM1_soll = Serial3.parseInt();
      Serial3.readStringUntil(',');
      RPM2_soll = Serial3.parseInt();
    }
    return true;
  }
  return false;
}

void VESC_Comm() {
  UART.setSerialPort(&Serial1);

  //Serial.println("VESC1");
  if ( UART.getVescValues() ) {
    U = UART.data.inpVoltage;
    RPM1 = UART.data.rpm;
    I1 = UART.data.avgInputCurrent;

  // Debug stuff
   
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
    Serial.println("Failed to get 1.data!");
  }
  
  
  UART.setRPM(RPM1_soll);



  UART.setSerialPort(&Serial2);

  if ( UART.getVescValues() ) {
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
    Serial.println("Failed to get 2.data!");
  }
  
  
  UART.setRPM(RPM2_soll);
}


