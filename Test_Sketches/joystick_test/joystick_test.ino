
#include <Servo.h>

Servo Xservo;  // create servo object to control a servo
Servo Yservo; 

int X = A0;  // analog pin used to connect the potentiometer
int Xval;    // variable to read the value from the analog pin
int Y = A1;  // analog pin used to connect the potentiometer
int Yval;   // variable to read the value from the analog pin

const int SW = 7;       // digital pin used to read switch value
int SWval;  // variable to read the value from the switch pin
const int ledpin=2; // pin that sends voltage to LED

void setup()
{
  Xservo.attach(3);  // attaches the servo on pin 3 to the servo object
  Yservo.attach(5);
  pinMode(ledpin, OUTPUT);
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
}



void loop() 
{ 
  Xval = analogRead(X);            // reads the value of the potentiometer (value between 0 and 1023) 
  Xval = map(Xval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  Xservo.write(Xval);                  // sets the servo position according to the scaled value 
  
  Yval = analogRead(Y);            // reads the value of the potentiometer (value between 0 and 1023) 
  Yval = map(Yval, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180) 
  Yservo.write(Yval); 

  SWval=digitalRead(SW);                // reads the value of the switch (high/low)
  if (SWval == 1)  {
    digitalWrite(ledpin, LOW);
  } else {
    digitalWrite(ledpin, HIGH);
  }
  
  delay(5);                           // waits for the servo to get there 
} 



