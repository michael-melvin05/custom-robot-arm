# Version 3 - Design Notes

## Overview

Version 3 focused on refining the mechanical design while significantly improving the robot's motion control software. Rather than introducing additional degrees of freedom, this revision emphasized increased structural rigidity, improved actuator mounting, and coordinated multi-axis motion. These improvements provide a stronger mechanical and software foundation for future work involving URDF generation, kinematics, ROS2, and trajectory planning.

---

## Mechanical

### Design Changes

- Returned to the larger base originally used in Version 1.
- Redesigned the shoulder assembly using a dual-support structure.
- Improved the mounting method for the wrist servo.

### Design Reasoning

Although Version 2 reduced the overall size of the robot, the smaller base limited the available space for future electronics and internal wiring. Returning to the larger base provides significantly more room for hardware while maintaining a stable platform.

The shoulder assembly was redesigned from a single-sided support into a dual-support configuration. This design increases the rigidity of the second joint by reducing bending loads and improving overall structural support.

The wrist servo mount was also redesigned to create a more secure attachment. The new mounting arrangement provides improved mechanical stability and a cleaner overall design.

### Design Concerns

- Internal wire routing can still be improved.
- The structural improvements have not yet been tested under heavier payloads.
- The End-Effector can further be devloped and will be before version 4. 

---

## Electrical

### Design Changes

- No major electrical hardware changes.

### Design Reasoning

The electrical architecture developed during Version 2 continues to meet the current requirements of the robot. Since this revision primarily focused on mechanical and software improvements, no significant electrical modifications were necessary.

### Design Concerns

- Wiring management should be improved as the robot becomes more permanent.
- Future revisions should further integrate the electronics into the mechanical design.

---

## Software

### Features Added

- Replaced the original blocking motion control with the AccelStepper library.
- Implemented simultaneous multi-axis motion.
- Added smooth acceleration and deceleration for both stepper motors.
- Implemented predefined robot poses.
- Retained the software-based homing system developed in Version 2.

### Design Reasoning

The original control software moved one joint at a time, resulting in slow and unrealistic robot motion. By implementing AccelStepper, each joint can now move toward its target position simultaneously while automatically handling acceleration and deceleration.

The software architecture also shifted from commanding individual joint movements to commanding complete robot poses. This more closely resembles how industrial robotic manipulators are controlled and establishes the foundation for future implementation of forward kinematics, inverse kinematics, and trajectory planning.

### Design Concerns

- Motion is currently limited to predefined robot poses.
- Motion planning between poses has not yet been implemented.
- The software homing system assumes no missed motor steps.
- Joint limits are currently managed manually and should be incorporated into a more complete motion control system.

---

## Next Goals

- Export the robot to a URDF.
- Implement forward kinematics.
- Implement inverse kinematics.
- Integrate with ROS2.
- Implement trajectory planning.
- Continue improving the overall mechanical design.
