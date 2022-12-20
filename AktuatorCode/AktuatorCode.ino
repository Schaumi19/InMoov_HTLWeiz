#include "AktuatorParameter.h"
#include "Motor.h"
#include "Pinout.h"
#include <Wire.h>

Motor Motors[4];
int i2cAddress = 0;
bool SerConnected = false;

void setup(){
  if(ACP_B1 == 3)
      i2cAddress = 2;
  else if (ACP_B1 == 5)
      i2cAddress = 4;
  else if (ACP_B1 == 4)
      i2cAddress = 5;
  int x = 2;//selectedBoard
  
  for (int i = 0; i < 4; i++){
      Motors[i].SetParameter(i, aktuatorParameters[x].used[i],aktuatorParameters[x].min_angle[i], aktuatorParameters[x].max_angle[i], aktuatorParameters[x].min_pot[i], aktuatorParameters[x].max_pot[i], aktuatorParameters[x].reversed_output[i], aktuatorParameters[x].reversed_input[i], aktuatorParameters[x].ContinuousMovement[i], aktuatorParameters[x].goalDeadzone[i], aktuatorParameters[x].maxSpeed[i]);
      Motors[i].SetPins(Pin_pot[i],Pin_motorPWM[i],Pin_motorA[i],Pin_motorB[i]);
      Motors[i].Init();
      if(aktuatorParameters[x].maxAngularSpeed[i] > 0)
        Motors[i].UseAngularSpeed(aktuatorParameters[x].maxAngularSpeed[i]);
  }
  
  Serial.begin(115200);
  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceiveEvent);
  pinMode(Pin_errorLed, OUTPUT);
}

void loop(){
  if(!SerConnected && Serial){
      Serial.write(ACP_B1); //for Actuator identification
      Serial.write(ACP_B2);
      SerConnected = true;
      delay(500);
  }
  readSerial();
  for (int i = 0; i < 4; i++)
  {
    Motors[i].Update();
  }
  
  digitalWrite(Pin_errorLed, LookForErrors());
}

// Reading in a string from Serial and computing it
void readSerial(){
  if(Serial.available() >= 4){
    if(Serial.read() == ';'){
      byte _AkIndex = Serial.parseInt();
      Serial.readStringUntil(',');
      byte _angle = Serial.parseInt();
      if (_AkIndex <= 4){
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
    for (byte i = 0; i < 4; i++){
        Motors[i].SetAngle(angle);
    }
  }
  else if (aktuatorID <= 4){
      Motors[aktuatorID-1].SetAngle(angle);
  }
}

bool LookForErrors(){
    for (int i = 0; i < 4; i++)
    {
        if(Motors[i].Error_Value || Motors[i].Error_OutOfRange || Motors[i].Error_Time || Motors[i].Error_Dir)
          return true;
    }
  return false;
}