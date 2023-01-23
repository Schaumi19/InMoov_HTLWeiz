// Coded by Manuel Schaumberger and Thomas Baumkircher

#include <Servo.h>
#include "config.h"
#include <Wire.h>

Servo servos[6];

int a;
int Speed;
unsigned long Time;
int o = 0;
int i = 0;

int i2cAddress = 0;
bool SerConnected = false;

void attach_detach_Servos(bool a){
  if(a == true){
    for (int i = 0; i < 6; i++)
      servos[i].attach(i+7);
  }
  else{
    for (int i = 0; i < 6; i++){
      servos[i].detach();
      digitalWrite(7+i,LOW);
    }
  }
}

void setup() {
  if(ACP_B1 == 3)
    i2cAddress = 1;
  else if (ACP_B1 == 5)
    i2cAddress = 3;
  Serial.begin(Baudrate);//Seriel Baud-rate 
  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceiveEvent);

  attach_detach_Servos(true); //attach all Servos
  a = 180;//Standard Servo setting

  for (int i = 0; i < 6; i++){
    servos[i].write(a);
    delay(400);
  }
  delay(500);
}



void loop() {
  if(!SerConnected && Serial){
    Serial.write(ACP_B1); //for Actuator identification
    Serial.write(ACP_B2);
    SerConnected = true;
  }
  readSerial();
}

// Reading in a string from Serial and computing it
void readSerial(){
  if(Serial.available() >= 4){
    if(Serial.read() == ';'){
      byte _AkIndex = Serial.parseInt();
      Serial.readStringUntil(',');
      byte _angle = Serial.parseInt();
      if (_AkIndex <= 6){
          receiveEvent(_AkIndex, _angle);
      }
      else{
        //External Actuator controller
        byte _ExternalI2CAddress = _AkIndex / 10;
        _AkIndex = _AkIndex % 10;

        if(_ExternalI2CAddress != 0 && _ExternalI2CAddress <= 7 && _AkIndex <= 6){
          if(_ExternalI2CAddress == i2cAddress){
            receiveEvent(_AkIndex, _angle);
          }
          i2cSendAsMaster(_ExternalI2CAddress, _AkIndex, _angle);
        }
        //Else Error Actuator Index out of Range
      }
    }
  }else{
    //Serial.print("no Serial data available");
  }
}

void i2cSendAsMaster(byte externalI2CAddress, byte akIndex, byte angle){
  Wire.end();
  Wire.begin();
  Wire.beginTransmission(externalI2CAddress);
  Wire.write(akIndex);
  Wire.write(angle);
  Wire.endTransmission();
  Wire.end();
  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceiveEvent);
}

void i2cReceiveEvent(int howMany){
  if(howMany == 2){ //If two bytes were received
    byte _aktuatorID = Wire.read();
    byte _angle = Wire.read();
    receiveEvent(_aktuatorID,_angle);
  }
}

void receiveEvent(byte aktuatorID, byte angle){
  if (aktuatorID == 0){    //Set all Aktuators to the same Value
    for (byte i = 0; i < 6; i++){
        servos[i].write(angle);
    }
  }
  else if (aktuatorID <= 6){
      servos[aktuatorID-1].write(angle);
  }
}