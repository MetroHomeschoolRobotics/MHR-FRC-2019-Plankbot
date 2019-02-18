/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"
#include <cmath>

Lift::Lift(Positioning *positioning) : Subsystem("Lift Subsystem") {
  _liftMotor = RobotMap::liftMotor.get();
  _positioning = positioning;
}

void Lift::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

int Lift::GetLiftDistance() {
  return _positioning->GetLiftDistance();
}


//sets the lift motor to a specified speed
  void Lift::setLiftMotor(double speed) {
    //_liftMotor->Set(speed);
/*      if (speed < 0 && !RobotMap::manipulatorBottomSwitch.get()->Get()){
    // Bottom Limit Switch Hit -- STOP!!
    speed = 0;
  } else if (speed > 0 && !RobotMap::manipulatorTopSwitch.get()->Get()){
    // Top Limit Switch Hit -- STOP!!
    speed = 0;
*/
    if (!RobotMap::manipulatorBottomSwitch.get()->Get()){
// If the bottom limit switch is pressed, we want to keep the values between 1 and 0
      speed = fmax(speed, 0);
    } else if (!RobotMap::manipulatorTopSwitch.get()->Get()){ 
// If the top limit switch is pressed, we want to keep the values between 0 and -1
      speed = fmin(speed, 0);
    }
 _liftMotor->Set(speed);
  }

//returns the distance the lifter has risen
  /*float Lift::getLiftDistance()  {
    return 0;
    //return lift encoder distance
  }

//resets the lift encoder
  void Lift::resetLiftEncoder() {
    //_liftMotor->(reset)
  }*/