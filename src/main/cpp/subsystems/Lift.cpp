/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"

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

//sets the lift motor to a specified speed
  void Lift::setLiftMotor(double speed) {
    _liftMotor->Set(speed);
      if (speed < 0 && !RobotMap::manipulatorBottomSwitch.get()->Get()){
    // Bottom Limit Swith Hit -- STOP!!
    speed = 0;
  } else if (speed > 0 && !RobotMap::manipulatorTopSwitch.get()->Get()){
    // Top Limit Switch Hit -- STOP!!
    speed = 0;
  }
  }

//returns the distance the lifter has risen
  /*double Lift::getLiftDistance()  {
    return 0;
    //return lift encoder distance
  }

//resets the lift encoder
  void Lift::resetLiftEncoder() {
    //_liftMotor->(reset)
  }*/