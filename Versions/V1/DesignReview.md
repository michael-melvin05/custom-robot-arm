# Version 1 - Design Review

## Overview

Version 1 was my first attempt at designing and building a robotic arm. I kept it to 2 DOF so I could focus on getting the mechanical design, electronics, and basic motor control working before making the system more complicated.

## Mechanical

- Started with a large base to make the arm stable and give myself plenty of room for electronics.
- After building it, I realized the base was much larger than it needed to be and had a lot of unused space.
- The overall design worked as a first prototype, but the next version needed to be smaller and package the components better.

## Electrical

- Used two Arduinos, with each Arduino controlling one servo.
- Each servo had its own power source because I did not have a good 6V supply that could reliably power both at the same time.
- This worked for testing, but resulted in a lot of unnecessary wiring and components.
- For the next version I wanted one controller and a better way to distribute power to all of the motors.

## Software

- Controlled both joints manually using four push buttons for clockwise and counterclockwise movement.
- The code was very simple and was mainly used to make sure the motors and mechanical design worked.
- There was no position tracking or homing, so the robot did not know the position of either joint.
- Adding more joints would make physical button control impractical, so the next version would need computer-based control.
