#include <Servo.h>

const int ACP_B1 = 4;
const int ACP_B2 = 2;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int serv1,serv2;

void setup() {
  Serial.begin(115200);//Seriel Baud-rate
  while(!Serial);
  Serial.write(ACP_B1);
  Serial.write(ACP_B2);

  delay(500);

  attach_detach_Servos(true); //attach Servos
  byte _angle = 70;//Standard Servo setting

  Kopf(_angle,_angle);
  delay(400);
  servo3.write(_angle);
  delay(400);
  servo4.write(_angle);
  delay(400);
  servo5.write(_angle);
  delay(400);
  servo6.write(_angle);
  delay(500);
}

void loop() {
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

      switch (_AkIndex)
      {
      case 0: //everything
        serv1 = _angle;
        serv2 = _angle;
        servo1.write(_angle);
        servo2.write(_angle);
        servo5.write(_angle);
        servo6.write(_angle);
        break;
      case 1://Servo1
        serv1 = _angle;
        break;
      case 2://Servo2
        serv2 = _angle;
        break;
      case 3://Servo3
        servo1.write(_angle);
        break;
      case 4://Servo4
        servo2.write(_angle);
        break;
      case 5://Servo5
        servo5.write(_angle);
        break;
      case 6://Servo6
        servo6.write(_angle);
      default:
        break;
      }
      Kopf(serv1,serv2);   
    }
  } 
}

void Kopf(int a,int c){
  int d = 0;
  d = c - 90;
  int ser1 = a + d;
  if(ser1 < 0){
    d = ser1;
    ser1 = 0;
  }
  if(ser1 > 180){
    d = ser1 - 180;
    ser1 = 180;
  }
  int ser2 = a - d;

  servo3.write(ser1);
  servo4.write(180 - ser2);
}

void attach_detach_Servos(bool a){
  if(a){
    servo1.attach(7);
    servo2.attach(8);
    servo3.attach(9);
    servo4.attach(10);
    servo5.attach(11);
    servo6.attach(12);
  }
  else{
    servo1.detach();
    servo2.detach();
    servo3.detach();
    servo4.detach();
    servo5.detach();
    servo6.detach();
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
}
