#include "vex.h"

using namespace vex;


brain Brain;

controller Controller1 = controller(primary);

//drivetrain motors
motor FL = motor(PORT1, ratio6_1, false); //port number, gear_ratio, reverse = true
motor ML = motor(PORT2, ratio6_1, true); //f= front, m= middle, b= back
motor BL = motor(PORT3, ratio6_1, false); //r= right, l= left
motor FR = motor(PORT4, ratio6_1, false); //modify port number, ratio, reverse
motor MR = motor(PORT5, ratio6_1, true); 
motor BR = motor(PORT6, ratio6_1, false); 

//drivetrain group
motor_group drivetrainright = motor_group(FR, MR, BR);  //Drivetrain Motor Right
motor_group drivetrainleft = motor_group(FL, ML, BL); //Drivetrain Motor Left

//pneumatics arm
pneumatics PneumaticsA = pneumatics(Brain.ThreeWirePort.A);

//lifting and descending of the mechanism pneumatics tube balls 
pneumatics PneumaticsB = pneumatics(Brain.ThreeWirePort.B);

//switching between top & middle control zones
pneumatics PneumaticsC = pneumatics(Brain.ThreeWirePort.C);

//4 of the motors
motor MotorA = motor(PORT9, false);
motor MotorB = motor(PORT10, false);
motor MotorC = motor(PORT11, false);
motor MotorD = motor(PORT12, false);

//Rotation sensors
rotation RotationX = rotation(PORT7);
rotation RotationY = rotation(PORT8);

//Inertial sensors
inertial Inertialsensor = inertial(PORT13); 

void vexcodeinit(void) {
}