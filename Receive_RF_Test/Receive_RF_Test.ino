
#include <SPI.h>
#include "RF24.h"
#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h>

RF24 radio(7,8); // CE, CNS
byte address[6] = "HansM";
int num[4];


void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openReadingPipe(1,address);
  radio.setPALevel(RF24_PA_LOW);
  //radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    //char text[32] = "";
    //radio.read(&text, sizeof(text));
    // Serial.println(text);
    radio.read(&num, sizeof(num));
    //Serial.println(num);
    Serial.println(num[0]);
    Serial.println(num[1]);
    Serial.println(num[2]);
  }
}



