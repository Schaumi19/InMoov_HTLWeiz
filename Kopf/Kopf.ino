#include <Servo.h>

#define ACP_B1 4
#define ACP_B2 2

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

int a;
int Speed, serv1,serv2;
unsigned long Time;

void setup() {
  Serial.begin(115200);//Seriel Baud-rate 
  Serial.write(ACP_B1);
  Serial.write(ACP_B2);

  attach_detach_Servos(true); //attach Servos
  a = 70;//Standard Servo setting


  Kopf(a,a);
  delay(400);
  servo3.write(a);
  delay(400);
  servo4.write(a);
  delay(400);
  servo5.write(a);
  delay(400);
  servo6.write(a);
  delay(1000);
}

void loop() {
  
  attach_detach_Servos(true);
  char b = Serial.read();
  if (b == 0) { //everything
    //Serial.println("gesamt");
    a = Serial.read();
    serv1 = a;
    serv2 = a;
    //delay(200);
    servo3.write(a);
    //delay(200);
    servo4.write(a);
    //delay(200);
    servo5.write(a);
    //delay(200);
    servo6.write(a);

  }
  else if (b == 1) { //Servo1
    a = Serial.read();
    serv1 = a;
  }
  else if (b == 2) { //Servo2
    a = Serial.read();
    serv2 = a;
  }
  else if (b == 3) { //Servo3
    a = Serial.read();
    servo1.write(a);
  }
  else if (b == 4) { //Servo4
    a = Serial.read();
    servo2.write(a);
  }
  else if (b == 5) { //Servo5
    a = Serial.read();
    servo5.write(a);
  }
  else if (b == 6) { //Servo6
    a = Serial.read();
    servo6.write(a);
  }
  Kopf(serv1,serv2);
  Time = millis();
  /*if(Time + 10000 <= millis() && servo1.attached() == true){
    attach_detach_Servos(false);
  }
  */

  Serial.write(",");
  Serial.write(255);
  Serial.write(105);
  Serial.write(2);
  Serial.write(0);
  Serial.write(3);
  Serial.write(0);
  Serial.write(4);
  Serial.write(0);
  Serial.write(5);
  Serial.write(0);
  Serial.write(6);
  Serial.write(0);
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
  if(a == true){
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
