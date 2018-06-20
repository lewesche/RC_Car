#include <SPI.h>
//#include "RF24.h"
//#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h>

RF24 radio(7, 10); // CE, CNS
byte address[6] = "10000";

int X = A0;  // analog pin used to connec t the potentiometer
int Xval;    // variable to read the value from the analog pin
int Y = A1;  // analog pin used to connect the potentiometer
int Yval;   // variable to read the value from the analog pin


const int SW = 4;       // digital pin used to read switch value
int SWval;  // variable to read the value from the switch pin

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
}

void loop() {
  Xval = analogRead(X);            // reads the value of the potentiometer (value between 0 and 1023) 
  Xval = map(Xval, 0, 1023, 50, 130);     // scale it to use it with the servo (value between 0 and 180) 
  Yval = analogRead(Y);            // reads the value of the potentiometer (value between 0 and 1023) 
  Yval = map(Yval, 0, 1023, -255, 255);     // scale it to use it with the servo (value between 0 and 180) 

  int pckg[] = {Xval, Yval};
  radio.write(&pckg, sizeof(pckg));
  delay(10);
 
  Serial.println(pckg[0]);
  Serial.println(pckg[1]);
  
  
}


