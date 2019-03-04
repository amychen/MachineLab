#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

Servo myservo;
int pos = 0;

void setup() {
  Serial.begin(9600);           

  AFMS.begin();
  
  myMotor->setSpeed(10);  
  myservo.attach(10);
}

void loop() {
  for (pos = 70; pos >= 20; pos -= 3) { 
    myservo.write(pos);             
    delay(50);                   
  }
  myMotor->step(50, FORWARD, SINGLE); 
  for (pos = 20; pos <= 70; pos += 3) { 
    myservo.write(pos);             
    delay(50);  
  }
    
}
