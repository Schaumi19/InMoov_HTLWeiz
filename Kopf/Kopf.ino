// Coded by Manuel Schaumberger and Thomas Baumkircher

#include <Servo.h>
#include "config.h"
#include <Wire.h>

Servo servos[6];

int i2cAddress = 6;
bool SerConnected = false;

int Pitch, Roll;

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
  Serial.begin(Baudrate);//Seriel Baud-rate 
  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceiveEvent);

  attach_detach_Servos(true); //attach all Servos

  for (int i = 0; i < 6; i++){
    servos[i].write(70);
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
        if(i >= 2)
          servos[i].write(angle);
        else{
          if(i == 0)
            Pitch = angle;
          else
            Roll = angle;
          PitchRoll();
        }
    }
  }
  else if (aktuatorID <= 6){
    int i = aktuatorID - 1;
    if(i >= 2)
      servos[i].write(angle);
    else{
      if(i == 0)
        Pitch = angle;
      else
        Roll = angle;
      PitchRoll();
    }
  }
}

void PitchRoll(){
  int d = Roll - 90;
  int ser[2];
  ser[0] = Pitch + d;
  ser[1] = 180 - (Pitch - d);
  for (int i = 0; i < 2; i++){
    if(ser[i]<0)
      ser[i] = 0;
    if(ser[i] > 180)
      ser[i] = 180;
  }
  servos[2].write(ser[0]);
  servos[3].write(ser[1]);
}