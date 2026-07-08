#include <AccelStepper.h>
#include <Servo.h>

Servo wrist;

AccelStepper J1(AccelStepper::FULL4WIRE, 8, 10, 9, 11);
AccelStepper J2(AccelStepper::FULL4WIRE, 4, 3, 5, 6);

const int wristPin = 2;

int wristPos = 90;
int wristTarget = 90;

float maxSpeed = 500;
float acceleration = 200;

long J1_home = 0;
long J2_home = 0;
int wrist_home = 90;

void setup() {
  Serial.begin(9600);

  wrist.attach(wristPin);
  wrist.write(wristPos);

  J1.setMaxSpeed(maxSpeed);
  J1.setAcceleration(acceleration);

  J2.setMaxSpeed(maxSpeed);
  J2.setAcceleration(acceleration);

  Serial.println("Robot Arm V3 Ready");
}

void loop() {
  readSerialCommand();

  J1.run();
  J2.run();
  updateServoSmooth();
}

void readSerialCommand() {
  if (Serial.available()) {
    char cmd = Serial.read();

    if (cmd == '1') {
      moveToPose(500, 500, 20);
      Serial.println("Moving to Pose 1");
    }

    if (cmd == '2') {
      moveToPose(-500, -500, 160);
      Serial.println("Moving to Pose 2");
    }

    if (cmd == '3') {
      moveToPose(0, 0, 90);
      Serial.println("Moving to Pose 3");
    }

    if (cmd == 'h') {
      moveToPose(J1_home, J2_home, wrist_home);
      Serial.println("Returning to software home");
    }

    if (cmd == 's') {
      printStatus();
    }
  }
}

void moveToPose(long J1_target, long J2_target, int wrist_target) {
  J1.moveTo(J1_target);
  J2.moveTo(J2_target);

  wristTarget = constrain(wrist_target, 0, 180);
}

void updateServoSmooth() {
  static unsigned long lastServoUpdate = 0;

  if (millis() - lastServoUpdate >= 30) {
    lastServoUpdate = millis();

    if (wristPos < wristTarget) {
      wristPos++;
      wrist.write(wristPos);
    }

    else if (wristPos > wristTarget) {
      wristPos--;
      wrist.write(wristPos);
    }
  }
}

void printStatus() {
  Serial.print("J1 Position: ");
  Serial.println(J1.currentPosition());

  Serial.print("J2 Position: ");
  Serial.println(J2.currentPosition());

  Serial.print("Wrist Position: ");
  Serial.println(wristPos);
}
