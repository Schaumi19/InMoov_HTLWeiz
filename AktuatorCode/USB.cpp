class USB
{
private:
    bool SerConnected = false;

public:
    USB();
    ~USB();
    void update(int ACP_B1, int ACP_B2){
        if(!SerConnected && Serial){
            Serial.write(ACP_B1); //for Actuator identification
            Serial.write(ACP_B2);
            SerConnected = true;
        }
        readSerial();
    };
};

USB::USB()
{
    // Setting up the serial
    Serial.begin(115200);
}


USB::~USB()
{
}

// Reading in a string from Serial and computing it
void readSerial(){
  if(Serial.available() >= 4){
    #ifdef Debug_Serial
    Serial.print("Reading");
    #endif
    if(Serial.read() == ';'){
      #ifdef Debug_Serial
      Serial.print("SymFound");
      #endif
      byte _AkIndex = Serial.parseInt();
      Serial.readStringUntil(',');
      byte _angle = Serial.parseInt();
      #ifdef Debug_Serial
      Serial.print(' ' +String(_AkIndex)+ ':' +String(_angle) + ' ');
      #endif
      if (_AkIndex == 0){    //All Aktuators to the same Value
        for (byte i = 0; i < 4; i++){
            goalAngle[i] = AngleInputLimiter(_angle,i);
        }
      }
      else if (_AkIndex <= 4){
          goalAngle[_AkIndex-1] = AngleInputLimiter(_angle,_AkIndex-1);
      }
      else{
        //External Actuator controller
        byte ExternalI2CAddress = _AkIndex / 10;
        _AkIndex = _AkIndex % 10;

        if(ExternalI2CAddress != 0 && ExternalI2CAddress <= 7 && _AkIndex <= 4){
          
        }
        //Else Error Actuator Index out of Range
      }
    }
  }else{
    //Serial.print("no Serial data avalible");
  }
}