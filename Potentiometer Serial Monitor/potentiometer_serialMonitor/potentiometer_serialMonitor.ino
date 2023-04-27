#include <Servo.h>

int posS1 = 0;
int posS1i = 0;
int incomingByte = 0;
int currentPosS1;

Servo servo1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Arduino code starting");

  servo1.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  delay(100);
}
