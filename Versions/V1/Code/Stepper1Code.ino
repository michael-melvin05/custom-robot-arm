#include <Stepper.h>

const int stepsPerRevolution = 2048;


Stepper stepperMotor(stepsPerRevolution, 8, 10, 9, 11);


const int cwButton = 4;
const int ccwButton = 7;

void setup() {
  stepperMotor.setSpeed(16);

  pinMode(cwButton, INPUT_PULLUP);
  pinMode(ccwButton, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Motor 1 Ready");
}

void loop() {
  if (digitalRead(cwButton) == LOW) {
    stepperMotor.step(1);
  }

  if (digitalRead(ccwButton) == LOW) {
    stepperMotor.step(-1);
  }
}
