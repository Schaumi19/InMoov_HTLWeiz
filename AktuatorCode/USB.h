
bool SerConnected = false;

void init(){
      Serial.begin(115200);
}

void update(){
        if(!SerConnected && Serial){
            Serial.write(ACP_B1); //for Actuator identification
            Serial.write(ACP_B2);
            SerConnected = true;
        }
        readSerial();
    };

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
      if (_AkIndex <= 4){
          ReceiveEvent(_AkIndex, _angle);
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