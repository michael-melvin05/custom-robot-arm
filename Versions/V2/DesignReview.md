# Version 2 - Design Review

## Overview

Version 2 was a major upgrade from the first prototype. I added a third degree of freedom, redesigned the arm to be more compact, moved everything onto one Arduino, and replaced the push-button controls with computer-based control.

## Mechanical

- Reduced the size of the base and the platform supporting the second joint.
- Redesigned the second arm section to make room for an additional servo.
- Added a third joint, turning the arm from a 2-DOF prototype into a 3-DOF system.
- Making everything smaller improved the overall design, but I made the base too small to easily fit one of the stepper drivers.
- I also needed to think more about where the electronics were placed because wiring near the rotating base could easily become tangled.

## Electrical

- Replaced the two-Arduino setup with a single Arduino controlling all three motors.
- Added a dedicated battery pack capable of powering the motors from one source.
- This significantly cleaned up the electrical system compared with Version 1.
- Packaging the second stepper driver was still a problem because it needed to stay inside the rotating portion of the robot to prevent wires from twisting around the base.

## Software

- Replaced the physical push buttons with computer-to-Arduino serial communication.
- Added individual joint control with adjustable speed and movement increments.
- Added step based position tracking and a software homing routine.
- One major limitation was that the joints still moved one at a time. I wanted the robot to move multiple joints together and eventually move to commanded positions rather than manually controlling each joint.
