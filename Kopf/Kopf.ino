#include <Servo.h>
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
  Serial.begin(500000);//Seriel Baud-rate 

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
  Serial.println("Power");//Debuging information
  delay(1000);
}

void loop() {
 if (Serial.available()){
    if (Serial.read() == 'M') { //R = Right; L = Left; M = Middle
      //Serial.println("R_erkannt");
      //delay(1);
      while(!Serial.available());
      char b = Serial.read();
      //delay(1);
      if (b == 'h') { //h = hand/head; s = shoulder; t = torso;
        while(!Serial.available());
        char b = Serial.read();
        attach_detach_Servos(true);
        if (b == 'a') { //everything
          //Serial.println("gesamt");
          a = Serial.parseInt();


          

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
          Serial.write("A:");
          Serial.println(a);

        }
        else if (b == 'b') { //Servo1
          Serial.println("b");
          a = Serial.parseInt();
          serv1 = a;
        }
        else if (b == 'c') { //Servo2
          Serial.println("c");
          a = Serial.parseInt();
          serv2 = a;
        }
        else if (b == 'd') { //Servo3
          Serial.println("d");
          a = Serial.parseInt();
          servo3.write(a);
        }
        else if (b == 'e') { //Servo4
          Serial.println("e");
          a = Serial.parseInt();
          servo4.write(a);
        }
        else if (b == 'f') { //Servo5
          Serial.println("f");
          a = Serial.parseInt();
          servo5.write(a);
        }
        else if (b == 'g') { //Servo6
          Serial.println("g");
          a = Serial.parseInt();
          servo6.write(a);
        }
        Kopf(serv1,serv2);
        Time = millis();
      }
    }
  }
  /*if(Time + 10000 <= millis() && servo1.attached() == true){
    attach_detach_Servos(false);
  }
  */
  
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
  Serial.print(a);
}
