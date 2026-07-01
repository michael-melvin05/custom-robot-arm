# Version 2 - Design Notes

## Overview

Version 2 focused on improving the overall mechanical design while significantly expanding the robot's capabilities. This revision introduced a third degree of freedom, consolidated the electrical system, and replaced the original button-based control system with computer-controlled motion.

---

## Mechanical

### Design Changes

- Reduced the overall size of the base.
- Reduced the size of the platform supporting the second joint.
- Changed the arm on the second stepper to allow room for an additional servo.
- Added a third servo to create a 3-DOF robotic arm.

### Design Reasoning

The original design demonstrated the concept successfully, but I felt the base and upper platform occupied more space than necessary. This redesign focused on making the robot more compact while maintaining stability. Adding a third degree of freedom also expanded the arm's workspace and provided a better platform for future robotics development.

### Design Concerns 

The base is too small to fit a stepper driver. 

---

## Electrical

### Design Changes

- Integrated a dedicated battery pack capable of powering all three motors.
- Consolidated the control system to a single Arduino.

### Design Reasoning

The original design required two separate Arduinos because I did not have a reliable power source capable of driving multiple motors simultaneously. The addition of the battery pack simplified the wiring and made the overall system much easier to manage.

### Design Concerns 

The driver for the second stepper motor will need to be placed internally to avoid the tangling of wires as the base stepper rotates.

---

## Software

### Features Added

- Computer-to-Arduino serial communication.
- Individual joint control.
- Adjustable joint speed.
- Adjustable movement increments.
- Software-based homing routine using step counting.

### Design Reasoning

This version shifted the project away from manual push-button control and toward software-driven robotic control. Implementing position tracking and homing established the foundation needed for future features such as forward kinematics, inverse kinematics, and ROS integration.

### Design Concerns 

Each motor moves one at a time, which I do not like, I want to implement a way for the robot to go to pre-programmed positions while moving all motors simulataneously. I think messing with the inverse and forward kinematics will help me solve this in a cool way. 

---

## Next Goals

- Export the robot to a URDF.
- Implement forward kinematics.
- Implement inverse kinematics.
- Integrate with ROS2.
