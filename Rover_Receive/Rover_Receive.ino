
#include <SPI.h>
//#include "RF24.h"
//#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>



RF24 radio(7,10);             // CE, CNS
byte address[6] = "10000";    // radio adress
int pckg[3];                  // variable to read radio package data

Servo RServo;                 // create servo object to control a servo
Servo LServo;                 // create right servo object

int Xval;                     // variable to read the value from the analog pin
int Yval;                     // variable to read the value from the analog pin
int DRV_IN1 = 5;              // output pin 1 for motor PWM
int DRV_IN2 = 6;              // output pin 2 for motor PWM
int battPin = A0;             // analog pin used to connect to battery (voltage divider)
int battRead;                 // variable to read the value from battPin
float battVoltage;            // battery voltage
int ledPin = 4;               // pin that sends voltage to battery indicating LED


void setup() {
  Serial.begin(115200);     
  radio.begin();            
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  
  RServo.attach(3);  // attaches the servo on pin 3 to the servo object
  LServo.attach(2);  // attaches the servo on pin 2 to the servo object

  pinMode(DRV_IN1, OUTPUT);
  pinMode(DRV_IN2, OUTPUT);
  pinMode(battPin, INPUT);
}

void loop() {
  battRead = analogRead(battPin);
  battVoltage = (5.*3./1023.)*battPin;  //5 nominal input voltage, voltage divider gain 3
  if (battVoltage < 10.5){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  
  if (radio.available()) {
    radio.read(&pckg, sizeof(pckg));
    
    Xval=pckg[0];
    Yval=pckg[1];

    RServo.write(Yval);
    LServo.write(Yval);

    if (Xval > 0){
      digitalWrite(DRV_IN1, LOW);
      analogWrite(DRV_IN2, Xval);   
    }

    if (Xval < 0){
      digitalWrite(DRV_IN2, LOW);
      analogWrite(DRV_IN1, abs(Xval));
    }
    Serial.println(battVoltage);
    Serial.println(Xval);
    Serial.println(Yval);
  } else {
    Serial.println("Can't Find Radio");
  }
  
}

