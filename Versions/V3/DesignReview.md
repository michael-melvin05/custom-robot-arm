# Version 3 - Design Review

## Overview

Version 3 focused on improving the mechanical design and making the arm move more like an actual robot. I kept the same 3-DOF layout but improved the shoulder and wrist mounting, made more room for electronics, and rewrote the motion control so multiple joints could move together.

## Mechanical

- Returned to the larger base from Version 1 after realizing the smaller Version 2 base did not leave enough room for electronics and wiring.
- Redesigned the shoulder to a dual support structure to improve rigidity.
- Redesigned the wrist servo mount for a more secure connection.
- The mechanical structure is much better than Version 2, but wire routing and electronics packaging can still be improved.
- The end effector is still very basic and is something I want to redesign in the next version.

## Electrical

- Kept the same general electrical setup from Version 2 because it was working well enough for the current arm.
- Most of the work in this version went toward mechanical and software improvements rather than changing the electronics.
- Wiring is still somewhat temporary and could be integrated into the mechanical design much better in a future version.

## Software

- Replaced the previous blocking stepper control with AccelStepper.
- Added simultaneous multi-axis movement with smooth acceleration and deceleration.
- Added predefined robot poses while keeping the position tracking and software homing from Version 2.
- This fixed one of my biggest problems with Version 2, where each joint had to finish moving before the next joint could move.
- Implemented inverse kinematics for end-effector positioning.
- Integrated the arm with ROS 2 for higher-level joint control.
- Created a URDF model of the robot.
- Visualized the robot model and joint movement in RViz.
