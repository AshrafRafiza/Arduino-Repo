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
  servo1.write(posS1i); //set the servo position to 0 degrees
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    // read incoming byte;
    incomingByte =  Serial.read();
    // say what you got;
    Serial.print("I received: ");
    Serial.print(incomingByte, DEC);

    switch(incomingByte){
      case 97:
        if(posS1 > 180){
          posS1 = 170;
        }
        posS1 += 10;
        servo1.write(posS1);
        currentPosS1 = servo1.read();
        Serial.print("S1 Current position: ");
        Serial.println(currentPosS1);
        break;

      case 100:
        if(posS1 < 0){
          posS1 = 10;
        }
        posS1 -= 10;
        servo1.write(posS1);
        currentPosS1 = servo1.read();
        Serial.print("S1 Current position: ");
        Serial.println(currentPosS1);
        break;
    }
    Serial.print("S1 Current position requested: ");
    Serial.println(posS1);
    incomingByte = 0;
  }
}
