/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       chloegwynnethhia                                          */
/*    Created:      3/10/2026, 9:11:24 AM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include <robot-config.h>

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void calibrateinertialsensor() {
  Inertialsensor.calibrate();
    while (Inertialsensor.isCalibrating()) {
      Controller1.Screen.clearLine(3);
      Controller1.Screen.print("Calibrating");
    }
      Controller1.Screen.clearLine(3);
      Controller1.Screen.print("Done");
      Controller1.rumble("-.-");
      wait (2, msec);
}

void pre_auton(void) {

    vexcodeinit();
  calibrateinertialsensor();
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

   void Armup() {
      PneumaticsA.close();
    }

    void Armdown() {
      PneumaticsA.open();
    }

    void setPosition(
    double value,rotationUnits units );

    void movemotora() {
    MotorA.spin(forward);
    }

    void movemotorb() {
    MotorB.spin(forward);
    }

    void movemotorc() {
    MotorC.spin(forward);
    }

    void movemotord() {
    MotorD.spin(forward);
    }

    void liftingtube() {
      PneumaticsB.close();
    }

    void descendingtube() {
      PneumaticsB.open();
    }

    void middlecontrol() {
      PneumaticsC.close();
    }

    void topcontrol() {
      PneumaticsC.open();
    }

    void stopmotorabcd() {
      MotorA.stop();
      MotorB.stop();
      MotorC.stop();
      MotorD.stop();
    }

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // Inside usercontrol loop

    //drivetrains forward and backward
    if (Controller1.Axis3.position() > 10) {
        drivetrainleft.spin(forward);
        drivetrainright.spin(forward);
    } else if (Controller1.Axis3.position() < -10) {
        drivetrainleft.spin(reverse);
        drivetrainright.spin(reverse);
    } else {
        drivetrainleft.stop();
        drivetrainright.stop();
    }

        //Drivetrain will be solved later problem

    //drivetrain left and right
    if (Controller1.Axis4.position() > 10) {
        drivetrainleft.spin(forward);
        drivetrainright.spin(reverse);
    } else if (Controller1.Axis4.position() < -10) {
        drivetrainleft.spin(reverse);
        drivetrainright.spin(forward);
    } else {
        drivetrainleft.stop();
        drivetrainright.stop();
    }
    

    //Pneumatic arms
    Controller1.ButtonL1.pressed(Armdown);
    Controller1.ButtonL2.pressed(Armup);

    //pneumatic switching between top & middle control zones
    Controller1.ButtonUp.pressed(topcontrol);
    Controller1.ButtonLeft.pressed(middlecontrol);

    //pneumatic lifting and descending of the mechanism for the tube balls
    Controller1.ButtonDown.pressed(descendingtube);
    Controller1.ButtonRight.pressed(liftingtube);

    //4 motors (a, b, c, d)
    Controller1.ButtonA.pressed(movemotora);
    Controller1.ButtonX.pressed(movemotorb);
    Controller1.ButtonY.pressed(movemotorc);
    Controller1.ButtonB.pressed(movemotord);
    Controller1.ButtonR1.pressed(stopmotorabcd);

    //rotation sensor
    double angleX = RotationX.angle(degrees);
    double angleY = RotationY.angle(degrees);
    RotationX.setPosition(0.0, degrees);
    RotationY.setPosition(0.0, degrees);
    
    // Display a message at the starting cursor
    Brain.Screen.setCursor(3, 12);
    Brain.Screen.print("Angle X value:");
    Brain.Screen.setCursor(3, 30);
    Brain.Screen.print(angleX);
    Brain.Screen.setCursor(5, 12);
    Brain.Screen.print("Angle Y value:");
    Brain.Screen.setCursor(5, 30);
    Brain.Screen.print(angleY);

    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // .......................................................................

 

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}



//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);


  
  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}