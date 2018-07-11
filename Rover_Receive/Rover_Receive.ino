#include <SPI.h>
//#include "RF24.h"
//#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>



RF24 radio(7,8);             // CE, CNS
byte address[6] = "10000";    // radio adress
int pckg[3];                  // variable to read radio package data

Servo servo;                 // create servo object to control a servo

int Xval;                     // variable to read the value from the analog pin
int Yval;                     // variable to read the value from the analog pin

int M_IN1 = 9;               // directional motor output
int M_IN2 = 6;              // directional motor output
int M_PWM = 10;                // Motor PWM

int S_IN1 = 3;                // Servo directional input
int S_IN2 = 4;                // Servo directional input
int S_PWM = 5;                // Servo PWM

int battPin = A0;             // analog pin used to connect to battery (voltage divider)
int battRead;                 // variable to read the value from battPin
float battVoltage;            // battery voltage
//int ledPin = A5;               // pin that sends voltage to battery indicating LED


void setup() {
  Serial.begin(115200);     
  radio.begin();            
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  
  servo.attach(2);  // attaches the servo on pin 2 to the servo object

  pinMode(M_IN1, OUTPUT);
  pinMode(M_IN2, OUTPUT);
  pinMode(M_PWM, OUTPUT);

  pinMode(S_IN1, OUTPUT);
  pinMode(S_IN2, OUTPUT);
  pinMode(S_PWM, OUTPUT);

  digitalWrite(S_IN1, HIGH);
  digitalWrite(S_IN2, LOW);
  analogWrite(S_PWM, 107);
    
  pinMode(battPin, INPUT);
  //pinMode(ledPin, OUTPUT);
}

void loop() {
  //battRead = analogRead(battPin);
  //battVoltage = (5.*2.47/1023.)*(float)battRead;  //5 nominal input voltage, voltage divider gain 3
  //if (battVoltage < 10.5){
  //  digitalWrite(ledPin, LOW);
  //} else {
  //  digitalWrite(ledPin, LOW);
  //}
  
  if (radio.available()) {
    radio.read(&pckg, sizeof(pckg));
    
    Xval=pckg[0];
    Yval=pckg[1];

    servo.write(Yval);

    if (Xval > 0){
      digitalWrite(M_IN1, LOW);
      digitalWrite(M_IN2, HIGH);
      analogWrite(M_PWM, Xval);   
    }
  
    if (Xval < 0){
      digitalWrite(M_IN1, HIGH);
      digitalWrite(M_IN2, LOW);
      analogWrite(M_PWM, abs(Xval));
    }
  
    Serial.println(battVoltage);
    Serial.println(Xval);
    Serial.println(Yval);
  } //else {
    //Serial.println("Can't Find Radio");
  //}
  delay(10);
}

