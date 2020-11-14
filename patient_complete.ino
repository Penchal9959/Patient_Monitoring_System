#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3);
#include <LiquidCrystal.h> // includes the LiquidCrystal Library
LiquidCrystal lcd(9 , 8, 4, 5, 6, 7);
#include "MAX30100_PulseOximeter.h"
const int buzzer = 12;
 
#define REPORTING_PERIOD_MS     1
//void ultra();
void SendMessage();
void SendMessage1();
void SendMessage2();


int ThermistorPin = 0;
int Vo;
float R1 = 4000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
//int x;
 //int x =10;
PulseOximeter pox;
uint32_t tsLastReport = 0;
void(* resetFunc) (void) = 0;
 
void onBeatDetected()
{
    Serial.println("Beat!");
}
 
void setup()
{
    Serial.begin(115200);
    lcd.begin(16,2);
    mySerial.begin(9600);  
    Serial.print("Initializing pulse oximeter..");
 
    // Initialize the PulseOximeter instance
    // Failures are generally due to an improper I2C wiring, missing power supply
    // or wrong target chip
    if (!pox.begin()) {
        Serial.println("FAILED");
        for(;;);
    } else {
        Serial.println("SUCCESS");
    }
     pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
    // Register a callback for the beat detection
    pox.setOnBeatDetectedCallback(onBeatDetected);

}
 
void loop()
{
    
    
    pox.update();
    Vo = analogRead(ThermistorPin);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    Tc = T - 273.15;
    Tf = (Tc * 9.0)/ 5.0 + 32.0;
     
    if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
        lcd.setCursor(0,0);
        lcd.print("Hrt:");
        lcd.setCursor(4,0);
        lcd.print(pox.getHeartRate());
        lcd.setCursor(8,0);
        lcd.print("bpm");
        lcd.setCursor(0,1);
        lcd.print("SpO2:");
        lcd.setCursor(5,1);
        lcd.print(pox.getSpO2());
        lcd.setCursor(7,1);
        lcd.print("%");
        lcd.setCursor(9,1);
        lcd.print("T:");
        lcd.setCursor(11,1);
        lcd.print(Tf);
        lcd.setCursor(15,1);
        lcd.print("F");
        tsLastReport = millis();
 
    } 

 if (Tf >= 98)
    {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      SendMessage();
      //delay(1000);
      
    }
    else{
        digitalWrite(buzzer, LOW);
    }
 if (pox.getHeartRate() >= 80)
    {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      SendMessage1();
      
    }
    else{
      digitalWrite(buzzer, LOW);
    }

  if (pox.getSpO2() >= 95)
    {
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
      delay(1000);
      SendMessage2();
      
    }
    else{
      digitalWrite(buzzer, LOW);
    }
 }
void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919959832810\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.print("Temperature: ");
  mySerial.println(Tf);
  mySerial.print("F");
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);

while(1)
  {
    if (true) 
    {
      resetFunc();
    }
  }
}
void SendMessage1()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919959832810\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.print("HeartRate: ");
  mySerial.println(pox.getHeartRate());
  mySerial.print("bpm");
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
while(1)
  {
    if (true) 
    {
      resetFunc();
    }
  }
}
void SendMessage2()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+919959832810\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.print("SpO2: ");
  mySerial.println(pox.getSpO2());
  mySerial.print(" %");
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
while(1)
  {
    if (true) 
    {
      resetFunc();
    }
  }
}
