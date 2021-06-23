#include <TFT_eSPI.h>
#include <SPI.h>
#include <Button2.h>
#include "bmp.h"
#include <SoftwareSerial.h>
#include <stdlib.h>
#include "BluetoothSerial.h"


#ifndef TFT_DISPOFF
#define TFT_DISPOFF 0x28
#endif

#ifndef TFT_SLPIN
#define TFT_SLPIN   0x10
#endif

#define TFT_MOSI            19
#define TFT_SCLK            18
#define TFT_CS              5
#define TFT_DC              16
#define TFT_RST             23

#define TFT_BL          4  // Display backlight control pin
#define ADC_EN          14
#define ADC_PIN         34

#define BUTTON_3		38

const float scope = 0.518f; // Hier den Durchmesser eintragen           einheit?

const int SoftSerialRX = 21;
const int SoftSerialTX = 22;

SoftwareSerial portOne(21, 22);
BluetoothSerial SerialBT;

String MSG = "";
bool newstuff = false;

TFT_eSPI tft = TFT_eSPI(135, 240); // Invoke custom library

struct MotorData {
  float U;
  int RPM1;
  int RPM2;
  float I1;
  float I2;
  float oU;
  int oRPM1;
  int oRPM2;
  float oI1;
  float oI2;
};

MotorData motordata;


String Mode = "InMoov";
long LastModeTime = 0;



void ChangeMode(){
	
		if(Mode == "InMoov"){
		  Mode = "Tp";
      tft.fillScreen(TFT_BLACK);
      tft.setRotation(3);
    }
		else if(Mode == "Tp"){
		  Mode = "Race";
      tft.fillScreen(TFT_BLACK);
      tft.setRotation(1);
    }
    else if(Mode == "Race"){
      Mode = "InMoov";
      tft.fillScreen(TFT_BLACK); 
      tft.setRotation(3);
    }
}

void setup()
{
    SerialBT.begin("InMoov");     // BLE Name
    //SerialBT.setPin("Schaumi");   // BLE PW

  
    pinMode(BUTTON_3, INPUT_PULLUP);
    Serial.begin(115200);
    portOne.begin(9600);
    
    Serial.println("Start");
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE);
    tft.setCursor(0, 0);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(1);

    if (TFT_BL > 0) { // TFT_BL has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
         pinMode(TFT_BL, OUTPUT); // Set backlight pin to output mode
         digitalWrite(TFT_BL, TFT_BACKLIGHT_ON); // Turn backlight on. TFT_BACKLIGHT_ON has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
    }

    tft.setSwapBytes(true);
    tft.pushImage(0, 0,  240, 135, ttgo);
    delay(2000);
    tft.pushImage(0, 0,  240, 135, Arduino);
    delay(2000);
    tft.pushImage(0, 0,  240, 135, InMoov);
    //espDelay(2000);
    delay(2000);
    tft.fillScreen(TFT_BLACK);


    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(2);
   
    tft.setRotation(3);
   
}


void loop()
{
  if (SerialBT.available()) {
    portOne.write(SerialBT.read());
  }

  
	if (digitalRead(BUTTON_3) == LOW && LastModeTime <= millis()){
		Serial.println("ChangeMode");
		ChangeMode();
		LastModeTime = millis() + 500;
	}


  portOne.listen();
  if (portOne.available() > 0)
    newstuff = true;

  while (portOne.available() > 0 && newstuff == true) {

    if(portOne.read() == 'p'){
      
      motordata.U = portOne.parseFloat();
      motordata.RPM1 = portOne.parseInt();
      motordata.I1 = portOne.parseFloat();
      motordata.RPM2 = portOne.parseInt();
      motordata.I2 = portOne.parseFloat();
      
    }

  }

  newstuff = false;

  tft.setTextColor(TFT_BLACK, TFT_BLACK);
  if(motordata.U != motordata.oU){
    tft.drawString("Voltage: " + String(motordata.oU), tft.width() - tft.width() / 5, tft.height() / 6);
    motordata.oU = motordata.U;
  }
  if(((scope * ((motordata.RPM1 + motordata.RPM2) / 2)) / 60) != ((scope * ((motordata.oRPM1 + motordata.oRPM2) / 2)) / 60)){
    tft.drawString("Speed: " + String(scope * (((motordata.oRPM1 + motordata.oRPM2) / 2) / 60)), tft.width() / 5, tft.height() / 2);
  }
  if(motordata.RPM1 != motordata.oRPM1){
    tft.drawString("RPM1: " + String(motordata.oRPM1), tft.width() / 5, tft.height() / 3);
    motordata.oRPM1 = motordata.RPM1;
  }
  if(motordata.I1 != motordata.oI1){
    tft.drawString("Current1: " + String(motordata.oI1), tft.width() / 5, (tft.height() / 3) * 2);
    motordata.oI1 = motordata.I1 / 10;
  }
  if(motordata.RPM2 != motordata.oRPM2){
    tft.drawString("RPM2: " + String(motordata.oRPM2), tft.width() - tft.width() / 5, tft.height() / 3);
    motordata.oRPM2 = motordata.RPM2;
  }
  if(motordata.I2 != motordata.oI2){
    tft.drawString("Current2: " + String(motordata.oI2), tft.width() - tft.width() / 5, (tft.height() / 3) * 2);
    motordata.oI2 = motordata.I2 / 10;
  }
  
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString(Mode , tft.width() / 5, tft.height() / 6);
  tft.drawString("Voltage: " + String(motordata.U), tft.width() - tft.width() / 5, tft.height() / 6);
  tft.drawString("RPM 1: " + String(motordata.RPM1), tft.width() / 5, tft.height() / 3);
  tft.drawString(" 2: " + String(motordata.RPM2), tft.width() - tft.width() / 5, tft.height() / 3);
  tft.drawString("Speed: " + String((scope * ((motordata.RPM1 + motordata.RPM2) / 2)) / 60), tft.width() / 5  , tft.height() / 2);
  tft.drawString("I1: " + String(motordata.I1), tft.width() / 5, (tft.height() / 3) * 2);
  tft.drawString(" I2: " + String(motordata.I2), tft.width() - tft.width() / 5, (tft.height() / 3) * 2);
  
}
