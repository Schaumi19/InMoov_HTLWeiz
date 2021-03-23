#include <TFT_eSPI.h>
#include <SPI.h>
//#include "WiFi.h"
//#include <Wire.h>
#include <Button2.h>
//#include "esp_adc_cal.h"
#include "bmp.h"
#include <SoftwareSerial.h>

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
#define BUTTON_1        35
#define BUTTON_2        0
#define BUTTON_3		    38

const int SoftSerialRX = 21;
const int SoftSerialTX = 22;

SoftwareSerial portOne(SoftSerialRX, SoftSerialTX);

String MSG = "";

TFT_eSPI tft = TFT_eSPI(135, 240); // Invoke custom library
Button2 btn1(BUTTON_1);
Button2 btn2(BUTTON_2);

struct MotorData {
  float U;
  int RPM1;
  int RPM2;
  float I1;
  float I2;
};

MotorData motordata;


char buff[512];
int vref = 1100;
int btnCick = false;
int Mode = 0;
long LastModeTime = 0;

//! Long time delay, it is recommended to use shallow sleep, which can effectively reduce the current consumption
void espDelay(int ms)
{   
    esp_sleep_enable_timer_wakeup(ms * 1000);
    esp_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH,ESP_PD_OPTION_ON);
    esp_light_sleep_start();
}

/*void showVoltage()
{
    static uint64_t timeStamp = 0;
    if (millis() - timeStamp > 1000) {
        timeStamp = millis();
        uint16_t v = analogRead(ADC_PIN);
        float battery_voltage = ((float)v / 4095.0) * 2.0 * 3.3 * (vref / 1000.0);
        String voltage = "Voltage :" + String(battery_voltage) + "V";
        Serial.println(voltage);
        tft.fillScreen(TFT_BLACK);
        tft.setTextDatum(MC_DATUM);
        tft.drawString(voltage,  tft.width() / 2, tft.height() / 2 );
    }
}

void button_init()
{
    btn1.setLongClickHandler([](Button2 & b) {
        btnCick = false;
        int r = digitalRead(TFT_BL);
        tft.fillScreen(TFT_BLACK);
        tft.setTextColor(TFT_GREEN, TFT_BLACK);
        tft.setTextDatum(MC_DATUM);
        tft.drawString("Press again to wake up",  tft.width() / 2, tft.height() / 2 );
        espDelay(6000);
        digitalWrite(TFT_BL, !r);

        tft.writecommand(TFT_DISPOFF);
        tft.writecommand(TFT_SLPIN);
        esp_sleep_enable_ext1_wakeup(GPIO_SEL_35, ESP_EXT1_WAKEUP_ALL_LOW);
        esp_deep_sleep_start();
    });
    btn1.setPressedHandler([](Button2 & b) {
        Serial.println("Detect Voltage..");
        btnCick = true;
    });
	

    btn2.setPressedHandler([](Button2 & b) {
        btnCick = false;
        Serial.println("btn press wifi scan");
        wifi_scan();
    });
}
*/

void ChangeMode(){
	switch(Mode){
		case 0 :
		Mode = 1;
		tft.drawString("Transport", tft.width() / 5, tft.height() / 6);
		break;
		case 1 :
		Mode = 2;
		tft.drawString("  Race    ", tft.width() / 5, tft.height() / 6);
		break;
		case 2 :
		Mode = 0;
		tft.drawString(" InMoov     ", tft.width() / 5, tft.height() / 6);
		break;
	}
}
/*
void button_loop()
{
    btn1.loop();
    btn2.loop();
}

void wifi_scan()
{
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(1.5);

    tft.drawString("Scan Network", tft.width() / 2, tft.height() / 2);

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    int16_t n = WiFi.scanNetworks();
    tft.fillScreen(TFT_BLACK);
    if (n == 0) {
        tft.drawString("no networks found", tft.width() / 2, tft.height() / 2);
    } else {
        tft.setTextDatum(TL_DATUM);
        tft.setCursor(0, 0);
        Serial.printf("Found %d net\n", n);
        for (int i = 0; i < n; ++i) {
            sprintf(buff,
                    "[%d]:%s(%d)",
                    i + 1,
                    WiFi.SSID(i).c_str(),
                    WiFi.RSSI(i));
            tft.println(buff);
        }
    }
    WiFi.mode(WIFI_OFF);
}
*/
void setup()
{
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
    //espDelay(3000);
    //delay(3000);
    tft.fillScreen(TFT_BLACK);


    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(MC_DATUM);
    tft.setTextSize(2);


    tft.drawString("InMoov", tft.width() / 5, tft.height() / 6);
    tft.drawString("Voltage", tft.width() - tft.width() / 5, tft.height() / 6);
    tft.drawString("RPM1", tft.width() / 5, tft.height() / 3);
    tft.drawString("RPM2", tft.width() - tft.width() / 5, tft.height() / 3);
    tft.drawString("Speed", tft.width() / 2, tft.height() / 2);
    tft.drawString("Current1", tft.width() / 5, (tft.height() / 3) * 2);
    tft.drawString("Current2", tft.width() - tft.width() / 5, (tft.height() / 3) * 2);
   
    //tft.setRotation(0);
    /*
    int i = 5;
    while (i--) {
        tft.fillScreen(TFT_RED);
        espDelay(1000);
        tft.fillScreen(TFT_BLUE);
        espDelay(1000);
        tft.fillScreen(TFT_GREEN);
        espDelay(1000);
    }

    //button_init();

    
    esp_adc_cal_characteristics_t adc_chars;
    esp_adc_cal_value_t val_type = esp_adc_cal_characterize((adc_unit_t)ADC_UNIT_1, (adc_atten_t)ADC1_CHANNEL_6, (adc_bits_width_t)ADC_WIDTH_BIT_12, 1100, &adc_chars);
    //Check type of calibration value used to characterize ADC
    if (val_type == ESP_ADC_CAL_VAL_EFUSE_VREF) {
        Serial.printf("eFuse Vref:%u mV", adc_chars.vref);
        vref = adc_chars.vref;
    } else if (val_type == ESP_ADC_CAL_VAL_EFUSE_TP) {
        Serial.printf("Two Point --> coeff_a:%umV coeff_b:%umV\n", adc_chars.coeff_a, adc_chars.coeff_b);
    } else {
        Serial.println("Default Vref: 1100mV");
    }
    
   Wire.begin(9);
   Wire.onReceive(receiveEvent);
   */
}

/*
void receiveEvent(int bytes) {

  motordata.U = (float)Wire.read()/10;
  motordata.RPM1 = Wire.read();
  motordata.RPM2 = Wire.read();
  motordata.I1 = (float)Wire.read()/10;
  motordata.I2 = (float)Wire.read()/10;
  
  tft.drawString((String)motordata.U, tft.width() - tft.width() / 5, tft.height() / 6);
  tft.drawString((String)motordata.RPM1, tft.width() / 5, tft.height() / 3);
  tft.drawString((String)motordata.RPM2, tft.width() - tft.width() / 5, tft.height() / 3);
  tft.drawString("Speed", tft.width() / 2, tft.height() / 2);
  tft.drawString((String)motordata.I1, tft.width() / 5, (tft.height() / 3) * 2);
  tft.drawString((String)motordata.I2, tft.width() - tft.width() / 5, (tft.height() / 3) * 2);
  
  Serial.println(motordata.U);
  Serial.println(motordata.RPM1);
  Serial.println(motordata.RPM2);
  Serial.println(motordata.I1);
  Serial.println(motordata.I2);
}
*/

void loop()
{
  /*
    if (btnCick) {
        showVoltage();
    }
    
    button_loop();
    */
	if (digitalRead(BUTTON_3) == LOW && LastModeTime <= millis()){
		Serial.println("ChangeMode");
		ChangeMode();
		LastModeTime = millis() + 500;
	}

  portOne.listen();
  while (portOne.available() > 0) {
    MSG += portOne.read();
  }
  tft.drawString(MSG, tft.width() / 5, tft.height() / 3);

 
}
