#include <SPI.h>
//#include "RF24.h" 
//#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h>

RF24 radio(7, 8); // CE, CNS
byte address[6] = "10000";

int X = A1;  // analog pin used to connect the X potentiometer
int Xval;    // variable to read the value from the analog pin
int Y = A0;  // analog pin used to connect the Y potentiometer
int Yval;   // variable to read the value from the analog pin


const int SW = 4;       // digital pin used to read switch value
int SWval;  // variable to read the value from the switch pin

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
  
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
}

void loop() {
  Yval = analogRead(Y);         
  Yval = map(Yval, 0, 1023, 115, 65);  
  Xval = analogRead(X);           
  Xval = map(Xval, 0, 1023, -255, 255);      

//  if (Yval > 100 && Xval > 180){
//    Xval = 180;
//  } else if (Yval > 100 && Xval < -180){
//    Xval = -180;
//  } else if (Yval < 80 && Xval > 180){
//    Xval = 180;
//  } else if (Yval < 80 && Xval < -180){
//    Xval = -180;
//  }
    
  int pckg[] = {Xval, Yval};
  radio.write(&pckg, sizeof(pckg));
  delay(10);
 
  Serial.println(pckg[0]);
  Serial.println(pckg[1]);
  
  
}


