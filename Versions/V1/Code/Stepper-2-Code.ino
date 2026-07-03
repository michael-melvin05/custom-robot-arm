#include <Stepper.h>

const int stepsPerRevolution = 2048;

Stepper stepperMotor(stepsPerRevolution, 4, 3, 5, 6);

const int cwButton = 5;
const int ccwButton = 6;

void setup() {
  stepperMotor.setSpeed(16);

  pinMode(cwButton, INPUT_PULLUP);
  pinMode(ccwButton, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Motor 2 Ready");
}

void loop() {
  if (digitalRead(cwButton) == LOW) {
    stepperMotor.step(1);
  }

  if (digitalRead(ccwButton) == LOW) {
    stepperMotor.step(-1);
  }
}
