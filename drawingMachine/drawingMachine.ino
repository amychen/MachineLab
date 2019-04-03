#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include <Servo.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200, 2);

Servo myservo;
int buttonPin = 2, buttonState = 0;
int onOffSwitch = 3, onOffSwitchState = 0;

int servoPos = 45;
int mili = 0;
int poServoValue = 0;
int poStepperValue = 0;
int counter = 0;
int stepperSpeed = 10;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  
  myMotor->setSpeed(stepperSpeed);
  
  myservo.attach(10);
  myservo.write(servoPos);

  pinMode(buttonPin, INPUT);
  pinMode(onOffSwitch, INPUT);
}

void loop() {
  onOffSwitchState = digitalRead(onOffSwitch);
  mili = millis();

  if (onOffSwitchState == 0) {
    buttonState = digitalRead(buttonPin);
    
    if (mili % 2 == 0) {
      poServoValue = analogRead(A1);
      poStepperValue = analogRead(A2);
    }

    servoPos = map(poServoValue, 0, 1023, 100, 0);
    stepperSpeed = map(poStepperValue, 0, 1023, 5, 100);
    myMotor->setSpeed(stepperSpeed);

    if (buttonState == 1) {
      
      myservo.write(servoPos);
      counter = map(poStepperValue, 0, 1023, 30, 180);
      
      if (counter > 0) {
  //      if (buttonState == 0) {
          myMotor->step(1, FORWARD, SINGLE);
  //      } else {
  //        myMotor->step(1, BACKWARD, SINGLE);
  //      }
        counter--;
      }
    } else {
      for (int pos = 70; pos >= 20; pos -= 3) { 
        myservo.write(pos);             
        delay(50);                   
      }
      myMotor->step(50 + stepperSpeed % 10, FORWARD, SINGLE); 
      for (int pos = 20; pos <= 70; pos += 3) { 
        myservo.write(pos);             
        delay(50);  
      }
    }
  }
}
