/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Arm.h"

Arm::Arm(Positioning *positioning) : Subsystem("Arm Subsystem") {
  _armMotor = RobotMap::armMotor.get();
  _armMotorEncoder = RobotMap::armMotorEncoder.get();
  _positioning = positioning;
}

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
//creates encoder override variable
void Arm::setOverride(bool active){
	if (active) {
		encoderOverride = true;
	} else {
		encoderOverride = false;
  }
}

void Arm::setArmMotor(double speed) {
    double val = speed;
    int angle = getArmAngle();
    //limits run only if encoderOverride is false; by activating encoderOverride, driver circumvents limits
if(!encoderOverride){
    if (angle < 0 && speed < 0){
      val = 0;
    }  else if (angle > 500 && speed > 0){
      val = 0;
    }
if (getArmAngle() > 230 && speed == 0){
      val = -.15;
    }
    _armMotor->Set(val);
  }
}

//returns the current angle of the arm
//Check this
double Arm::getArmAngle() {
  return _armMotorEncoder->Get();
  }

void Arm::resetArmEncoder() {
    _armMotorEncoder->Reset();
  }
