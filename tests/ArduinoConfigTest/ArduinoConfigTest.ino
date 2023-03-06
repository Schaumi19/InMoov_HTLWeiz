// general stuff:
const long Baudrate = 115200;

bool ConfigMode = false;

bool MControl[4] = {false, false, false, false};
bool MControlDir[4] = {false, false, false, false};

struct MotorParameter
{
    bool used;
    byte min_angle;
    byte max_angle;
    unsigned int min_pot;
    unsigned int max_pot;
    bool reverse_output;
    bool reverse_input;
    byte continuousMovement = 0;
    byte goalDeadzone = 6;

    byte maxSpeed = 255;
    bool useAngularSpeed = false;

    //error Detection Settings
    byte errorMinDiff = 2;
    byte errorMinAngularSpeed = 20; // °/s
};

class Motor
{
private:
    /* data */
public:
    MotorParameter motorParameter;
};

Motor Motors[4];


void setup() {
  Serial.begin(Baudrate);
}

void loop() {
  readSerial();
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
      if (ConfigMode)
      {
        if (_AkIndex < 4 && _angle <= 2)
        {
          MControl[_AkIndex] = _angle;
          if (_angle)
            MControlDir[_AkIndex] = _angle - 1;
        }
      }
      if (_AkIndex <= 4)
      {
        //receiveEvent(_AkIndex, _angle);
      }
      else
      {
        // External Actuator controller
        byte _ExternalI2CAddress = _AkIndex / 10;
        _AkIndex = _AkIndex % 10;

        if (_ExternalI2CAddress != 0 && _ExternalI2CAddress <= 7 && _AkIndex <= 6)
        {
        /*
          if (_ExternalI2CAddress == i2cAddress)
          {
            receiveEvent(_AkIndex, _angle);
          }
          i2cSendAsMaster(_ExternalI2CAddress, _AkIndex, _angle);
          */
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
    }
    else if (nextChar == 'C')
    {
      ConfigMode = true;
    }
    else if (nextChar == 'P')
    {
    /*
      Serial.write("P");
      for (byte i = 0; i < 4; i++)
      {
        byte MotorParamBytes[2];
        uint16_t currentPotValue = analogRead(Pin_pot[i]);
        MotorParamBytes[0] = currentPotValue & 255;
        MotorParamBytes[1] = currentPotValue >> 8;
        for (int x = 0; x < 2; x++)
        {
          Serial.write(MotorParamBytes[x]);
        }
      }
        */
    }
  }
  else
  {
    // Serial.print("no Serial data available");
  }
}



// Reading ConfigData from Serial and computing it
void SerialReadConfig()
{
  while (Serial.available() < 52);
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
    byte Extra = Serial.read();
/*
    Serial.print("Motor ");
    Serial.print(i);
    Serial.print(" used: ");
    Serial.print(Motors[i].motorParameter.used);
    Serial.print(" reverse_output: ");
    Serial.print(Motors[i].motorParameter.reverse_output);
    Serial.print(" reverse_input: ");
    Serial.print(Motors[i].motorParameter.reverse_input);
    Serial.print(" useAngularSpeed: ");
    Serial.print(Motors[i].motorParameter.useAngularSpeed);
    Serial.print(" min_angle: ");
    Serial.print(Motors[i].motorParameter.min_angle);
    Serial.print(" max_angle: ");
    Serial.print(Motors[i].motorParameter.max_angle);
    Serial.print(" min_pot: ");
    Serial.print(Motors[i].motorParameter.min_pot);
    Serial.print(" max_pot: ");
    Serial.print(Motors[i].motorParameter.max_pot);
    Serial.print(" continuousMovement: ");
    Serial.print(Motors[i].motorParameter.continuousMovement);
    Serial.print(" goalDeadzone: ");
    Serial.print(Motors[i].motorParameter.goalDeadzone);
    Serial.print(" maxSpeed: ");
    Serial.print(Motors[i].motorParameter.maxSpeed);
    Serial.print(" errorMinDiff: ");
    Serial.print(Motors[i].motorParameter.errorMinDiff);
    Serial.print(" errorMinAngularSpeed: ");
    Serial.print(Motors[i].motorParameter.errorMinAngularSpeed);
    Serial.print(" Extra: ");
    Serial.print(Extra);
    */

  }
  //SaveMotorParams();
}