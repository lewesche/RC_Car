
#include <SPI.h>
//#include "RF24.h"
//#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>



RF24 radio(7,10); // CE, CNS
byte address[6] = "10000";
int pckg[3];

Servo RServo;  // create servo object to control a servo
Servo LServo; 

int Xval;    // variable to read the value from the analog pin
int Yval;   // variable to read the value from the analog pin
int DRV_IN1 = 5;
int DRV_IN2 = 6;

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  
  RServo.attach(3);  // attaches the servo on pin 3 to the servo object
  LServo.attach(2);

  pinMode(DRV_IN1, OUTPUT);
  pinMode(DRV_IN2, OUTPUT);
  
}

void loop() {
  if (radio.available()) {
    radio.read(&pckg, sizeof(pckg));
    
    Xval=pckg[0];
    Yval=pckg[1];

    RServo.write(Xval);
    LServo.write(Xval);

    if (Yval > 0){
      digitalWrite(DRV_IN1, LOW);
      analogWrite(DRV_IN2, Yval);   
    }

    if (Yval < 0){
      digitalWrite(DRV_IN2, LOW);
      analogWrite(DRV_IN1, abs(Yval));
    }

    Serial.println(Xval);
    Serial.println(Yval);
  }
}

