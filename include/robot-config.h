#include "vex.h"
using namespace vex;

extern brain Brain;

extern controller Controller1;

extern motor FL;
extern motor ML;
extern motor BL;
extern motor FR;
extern motor MR;
extern motor BR;

extern motor_group drivetrainright;
extern motor_group drivetrainleft;

extern pneumatics PneumaticsA;
extern pneumatics PneumaticsB;
extern pneumatics PneumaticsC;

extern motor MotorA;
extern motor MotorB;
extern motor MotorC;
extern motor MotorD;

extern rotation RotationX;
extern rotation RotationY;

extern inertial Inertialsensor;

void vexcodeinit(void);