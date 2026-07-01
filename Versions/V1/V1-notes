# Version 1 - Design Notes

## Overview

Version 1 was my initial proof-of-concept robotic arm designed to validate a simple two-degree-of-freedom manipulator while learning the fundamentals of robotic arm design, control, and system integration.

---

## Mechanical

### Design Decisions
- Chose a larger base to provide a stable platform while learning the design process.
- Designed the arm as a simple 2-DOF manipulator to keep the initial prototype manageable.
- Prioritized functionality over optimization during the first iteration.

### Lessons Learned
- The base was larger than necessary for a 2-DOF arm.
- The design left significant unused internal volume.
- Future versions would reduce size while improving packaging and rigidity.

---

## Electrical

### Design Decisions
- Used two separate Arduinos to independently control each motor.
- Powered each servo separately because I did not yet have a reliable 6V power source capable of driving both motors simultaneously.

### Lessons Learned
- Multiple controllers increased wiring complexity.
- A dedicated battery pack and shared power distribution would simplify the electrical system.

---

## Software

### Features
- Independent control of two joints using four physical push buttons.
- Manual clockwise and counterclockwise control for each motor.
- Simple firmware designed to validate motor control and mechanical movement.

### Lessons Learned
- This version did not include position tracking or a homing routine.
- Manual button control was effective for testing but would not scale as additional joints were added.
- Future versions would replace manual controls with computer communication, position tracking, and software-based homing.
---

