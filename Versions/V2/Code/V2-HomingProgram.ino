#include <Servo.h>
#include <Stepper.h>

Servo wrist; 

const int stepsPerRevolution = 2048;

Stepper J1(stepsPerRevolution, 8, 10, 9, 11); 
Stepper J2(stepsPerRevolution, 4, 3, 5, 6);

int stepSpeed = 15; 
int steps = 100;

int servPos = 0;

long J2pos = 0;
long J1pos = 0; 

void setup() {

  wrist.attach(2);
  
  J1.setSpeed(stepSpeed); 
  J2.setSpeed(stepSpeed);

  Serial.begin(9600);

  wrist.write(servPos); 

}

void loop() { 
  
  if (Serial.available()) {

    char cmd = Serial.read();

    

    if (cmd == 'd') {
      J2.step(steps);   
      J2pos += steps; 
      Serial.print("Joint 2 Position: ");
      Serial.println(J2pos); 
    }

    if (cmd == 'a') {
      J2.step(-steps);
      J2pos -= steps;      
      Serial.print("Joint 2 Position: ");
      Serial.println(J2pos); 
    }

    if (cmd == 'h') {

      J2.step(-J2pos);
      J2pos = 0;
      Serial.println("Joint 2 home"); 


    }
        if (cmd == 'q') {
      J1.step(steps);   
      J1pos += steps; 
      Serial.print("Joint 1 Position: ");
      Serial.println(J1pos); 
    }

    if (cmd == 'e') {
      J1.step(-steps);
      J1pos -= steps;      
      Serial.print("Joint 1 Position: ");
      Serial.println(J1pos); 
    }

    if (cmd == 'y') {

      J1.step(-J1pos);
      J1pos = 0;
      Serial.println("Joint 1 home"); 


    }

    if (cmd == 'z') {

      servPos += 10; 
      wrist.write(servPos);
      Serial.print("Joint 3 Position: ");
      Serial.println(servPos);
      

    }
    if (cmd == 'c') {

      servPos -= 10; 
      wrist.write(servPos);
      Serial.print("Joint 3 Position: ");
      Serial.println(servPos);

    }
    if (cmd == 'b') {
 
      wrist.write(0);
      Serial.println("Joint 3 Home");

    }
    if (cmd == 's') {

      Serial.print("Current speed: ");
      Serial.println(stepSpeed);

      Serial.println("Input New Speed");

       while (Serial.available() == 0) {
  }
      
      stepSpeed = Serial.parseInt();

      J1.setSpeed(stepSpeed);
      J2.setSpeed(stepSpeed);

      Serial.print("New speed: ");
      Serial.println(stepSpeed); 

    }
     if (cmd == 'x') {

      Serial.print("Current step: ");
      Serial.println(steps);

      Serial.println("Input New Step");

       while (Serial.available() == 0) {
  }
      
      steps = Serial.parseInt();

      J1.setSpeed(steps);
      J2.setSpeed(steps);

      Serial.print("New step: ");
      Serial.println(steps); 

    }
  } 

}
