
#include <SPI.h>
//#include "RF24.h"
//#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>



RF24 radio(7,10); // CE, CNS
byte address[6] = "10000";
int pckg[4];

Servo Xservo;  // create servo object to control a servo
Servo Yservo; 

int Xval;    // variable to read the value from the analog pin
int Yval;   // variable to read the value from the analog pin
int SWval;  // variable to read the value from the switch pin
const int ledpin=2; // pin that sends voltage to LED

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  
  Xservo.attach(3);  // attaches the servo on pin 3 to the servo object
  Yservo.attach(2);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  if (radio.available()) {
    radio.read(&pckg, sizeof(pckg));
    
    Xval=pckg[0];
    Yval=pckg[1];
    SWval=pckg[2];

    Xservo.write(Xval);
    Yservo.write(Yval);
    if (SWval == 1)  {
      digitalWrite(ledpin, LOW);
    } else {
      digitalWrite(ledpin, HIGH);
    }
    Serial.println(Xval);
    Serial.println(Yval);
    Serial.println(SWval);
  }
}

