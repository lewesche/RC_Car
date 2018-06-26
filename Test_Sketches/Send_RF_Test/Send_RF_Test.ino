#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

RF24 radio(7, 8); // CE, CNS
byte address[6] = "HansM";

void setup() {
  Serial.begin(115200);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  //radio.setDataRate(RF24_250KBPS);
  radio.stopListening();
}

void loop() {
  //const char text[] = "Hello World!";
  //radio.write(&text, sizeof(text));
  int num[] = {1, 2, 3};
  radio.write(&num, sizeof(num));
  delay(10);

  // Serial.println(text);
  Serial.println(num[0]);
  Serial.println(num[1]);
  Serial.println(num[2]);
}



