# Dev Diary

## Part 1 - Position Mode
We tuned position mode and then tested applying force by hand.

Observations when set to positon 0:

* Always returns to the same position. (Very accurate)
* Current draw continously increases if it's not able to reach it's position
    * This causes a fault in the TMC6200 if current rises too high
* The further the motor is from it's target position, the more current it draws

## Part 2 - TI Article
https://www.electronicdesign.com/technologies/power/whitepaper/21130416/simple-lowcost-dynamometer-setup-for-motor-testing-part-2
https://www.hackster.io/motor-torque-test-bench-team/dynamometer-for-stepper-motors-84864e

### TI Code Loop (Pseudocode summary)
1. Init System
2. Init Motor
    1. Write to registers
    2. Init encoder
3. Wait for system to be enabled
    * Disable key parameter editing while enabled
5. 