// #include "AktuatorParameter.h"
#include "Motor.h"
#include "Pinout.h"
#include <Wire.h>
#include <EEPROM.h>

// general stuff:
const long Baudrate = 115200;

Motor Motors[4];
bool SerConnected = false;
byte ACP_B1 = 0; // 3 = Left hand side, 4 = Middle, 5 = Right hand side       different Code:(1 = BoardMotorController, 2 = RGB)
byte ACP_B2 = 3; // 0 = not Used (if 1st Byte is 1 or 2), 1 = Hand, 2 = Head, 3 = Actuator (since there is max one per side)

int x = 2; // left 0, middle 1, right 2
int i2cAddress = 4;

bool ConfigMode = false;

bool NotConfigured = true;

/* selectedBoard:
    2 - linke Schulter
    4 - rechte Schulter
    5 - Torso
*/

void setup()
{
  Serial.begin(115200);
  pinMode(Pin_errorLed, OUTPUT);

  if (i2cAddress == 2)
    ACP_B1 = 3;
  else if (i2cAddress == 4)
    ACP_B1 = 5;
  else if (i2cAddress == 5)
    ACP_B1 = 4;

  EEPROM.get(1, NotConfigured);
  if (!NotConfigured)
  {
    LoadMotorParams();
  }
  else
  {
    while (!Serial.available())
      ;
    if (Serial.read() == '!')
      SerialReadConfig();
  }

  for (int i = 0; i < 4; i++)
  {
    Motors[i].SetPins(Pin_pot[i], Pin_motorPWM[i], Pin_motorA[i], Pin_motorB[i]);
    Motors[i].Init();
  }

  Wire.begin(i2cAddress);
  Wire.onReceive(i2cReceiveEvent);
}

void loop()
{
  if (!SerConnected && Serial)
  {
    Serial.write(ACP_B1); // for Actuator identification
    Serial.write(ACP_B2);
    SerConnected = true;
    delay(500);
  }
  readSerial();

  for (int i = 0; i < 4; i++)
  {
    if (ConfigMode)
    {
      Motors[i].ManualMotorControl(0,0);
    }
    else
    {
      Motors[i].Update(i);
    }
  }

  digitalWrite(Pin_errorLed, LookForErrors());
}

// Reading in a string from Serial and computing it
void readSerial()
{
  if (Serial.available() >= 4)
  {
    char nextChar = Serial.read();
    if (nextChar == ';')
    {
      byte _AkIndex = Serial.parseInt();
      Serial.readStringUntil(',');
      byte _angle = Serial.parseInt();
      if (_AkIndex <= 4)
      {
        receiveEvent(_AkIndex, _angle);
      }
      else
      {
        // External Actuator controller
        byte _ExternalI2CAddress = _AkIndex / 10;
        _AkIndex = _AkIndex % 10;

        if (_ExternalI2CAddress != 0 && _ExternalI2CAddress <= 7 && _AkIndex <= 6)
        {
          if (_ExternalI2CAddress == i2cAddress)
          {
            receiveEvent(_AkIndex, _angle);
          }
          i2cSendAsMaster(_ExternalI2CAddress, _AkIndex, _angle);
        }
        // Else Error Actuator Index out of Range
      }
    }
    else if (nextChar == '?')
    {
      Serial.print("Sending:");
      Serial.write("|");
      for (byte i = 0; i < 4; i++)
      {
        byte MotorParamBytes[12];
        MotorParamBytes[0] = Motors[i].motorParameter.used * 1;
        MotorParamBytes[0] += Motors[i].motorParameter.reverse_output * 2;
        MotorParamBytes[0] += Motors[i].motorParameter.reverse_input * 4;
        MotorParamBytes[0] += Motors[i].motorParameter.useAngularSpeed * 8;
        MotorParamBytes[1] = Motors[i].motorParameter.min_angle;
        MotorParamBytes[2] = Motors[i].motorParameter.max_angle;
        MotorParamBytes[3] = Motors[i].motorParameter.min_pot & 255;
        MotorParamBytes[4] = Motors[i].motorParameter.min_pot >> 8;
        MotorParamBytes[5] = Motors[i].motorParameter.max_pot & 255;
        MotorParamBytes[6] = Motors[i].motorParameter.max_pot >> 8;
        MotorParamBytes[7] = Motors[i].motorParameter.continuousMovement;
        MotorParamBytes[8] = Motors[i].motorParameter.goalDeadzone;
        MotorParamBytes[9] = Motors[i].motorParameter.maxSpeed;
        MotorParamBytes[10] = Motors[i].motorParameter.errorMinDiff;
        MotorParamBytes[11] = Motors[i].motorParameter.errorMinAngularSpeed;
        for (int x = 0; x < 12; x++)
        {
          Serial.write(MotorParamBytes[x]);
        }
      }
    }
    else if (nextChar == '!')
    {
      SerialReadConfig();
    }else if (nextChar == 'C')
    {
      ConfigMode = true;
    }
    
  }
  else
  {
    // Serial.print("no Serial data available");
  }
}

void i2cSendAsMaster(byte externalI2CAddress, byte akIndex, byte angle)
{
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

void i2cReceiveEvent(int howMany)
{
  if (howMany == 2)
  { // If two bytes were received
    byte _aktuatorID = Wire.read();
    byte _angle = Wire.read();
    receiveEvent(_aktuatorID, _angle);
  }
}

void receiveEvent(byte aktuatorID, byte angle)
{
  if (aktuatorID == 0)
  { // Set all Aktuators to the same Value
    for (byte i = 0; i < 4; i++)
    {
      Motors[i].SetAngle(angle);
    }
  }
  else if (aktuatorID <= 4)
  {
    Motors[aktuatorID - 1].SetAngle(angle);
  }
}

bool LookForErrors()
{
  for (int i = 0; i < 4; i++)
  {
    if (Motors[i].Error_Value || Motors[i].Error_OutOfRange || Motors[i].Error_Time || Motors[i].Error_Dir)
      return true;
  }
  return false;
}

// Reading ConfigData from Serial and computing it
void SerialReadConfig()
{
  while (Serial.available() < 48)
    ;
  // Serial.println("StartConfig");
  for (byte i = 0; i < 4; i++)
  {
    byte firstByte = Serial.read();
    Motors[i].motorParameter.used = firstByte & 1;
    Motors[i].motorParameter.reverse_output = firstByte & 2;
    Motors[i].motorParameter.reverse_input = firstByte & 4;
    Motors[i].motorParameter.useAngularSpeed = firstByte & 8;
    Motors[i].motorParameter.min_angle = Serial.read();
    Motors[i].motorParameter.max_angle = Serial.read();
    Motors[i].motorParameter.min_pot = Serial.read() << 8;
    Motors[i].motorParameter.min_pot += Serial.read();
    Motors[i].motorParameter.max_pot = Serial.read() << 8;
    Motors[i].motorParameter.max_pot += Serial.read();
    Motors[i].motorParameter.continuousMovement = Serial.read();
    Motors[i].motorParameter.goalDeadzone = Serial.read();
    Motors[i].motorParameter.maxSpeed = Serial.read();
    Motors[i].motorParameter.errorMinDiff = Serial.read();
    Motors[i].motorParameter.errorMinAngularSpeed = Serial.read();
  }
  // SaveMotorParams();
}

void SaveMotorParams()
{
  MotorParameter pararr[4];
  for (size_t i = 0; i < 4; i++)
  {
    memcpy(&pararr[i], &Motors[i].motorParameter, sizeof(pararr[i]));
  }
  EEPROM.put(2, pararr);
  EEPROM.put(1, 0);
}

void LoadMotorParams()
{
  MotorParameter pararr[4];
  EEPROM.get(2, pararr);
  for (size_t i = 0; i < 4; i++)
  {
    memcpy(&Motors[i].motorParameter, &pararr[i], sizeof(Motors[i].motorParameter));
  }
}