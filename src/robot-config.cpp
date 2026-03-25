#include "vex.h"

using namespace vex;


brain Brain;

controller Controller1 = controller(primary);
motor FL = motor(PORT1, ratio6_1, false); //port number, gear_ratio, reverse = true
motor ML = motor(PORT2, ratio6_1, false); //f= front, m= middle, b= back
motor BL = motor(PORT3, ratio6_1, false); //r= right, l= left
motor FR = motor(PORT4, ratio18_1, false); //modify port number, ratio, reverse
motor MR = motor(PORT5, ratio18_1, false); 
motor BR = motor(PORT6, ratio18_1, false); 

motor_group drivetrainright = motor_group(FR, MR, BR);  //Drivetrain Motor Right
motor_group drivetrainleft = motor_group(FL, ML, BL); //Drivetrain Motor Left

void vexcodeinit(void) {
}