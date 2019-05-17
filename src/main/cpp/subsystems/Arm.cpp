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
void Arm::kidSafeMode(bool safe){
    kidSafe = safe;
    frc::SmartDashboard::PutBoolean("Arm::kidSafeMode t", kidSafe);
}

bool Arm::getKidSafe(){
  return kidSafe;
  //frc::SmartDashboard::PutNumber("Arm::KidSafeGet", kidSafe);
}

void Arm::overrideJoystick(bool ignore){
  if (ignore) {
    joystickOverride = true;
  } else { 
    joystickOverride = false;
  }
}

//creates encoder override variable
void Arm::setOverride(bool active){
	if (active && !kidSafe) {
    frc::SmartDashboard::PutNumber("Arm::KidSafeEnc", kidSafe);
		encoderOverride = true;
	} else {
		encoderOverride = false;
  }
  frc::SmartDashboard::PutNumber("encoderoverride", encoderOverride);
}

void Arm::setArmMotor(double speed) {
    double val = speed;
    int angle = getArmAngle();
    frc::SmartDashboard::PutBoolean("Arm::KidSafe", kidSafe);
    //limits run only if encoderOverride is false; by activating encoderOverride, driver circumvents limits
//if(!encoderOverride && !kidSafe){
 // frc::SmartDashboard::PutNumber("Arm::setMotorkidsafe", kidSafe);
    /*if (angle < 0 && speed > 0){
      val = 0;
    // }  else if (angle > 800 && speed < 0){
    }  else if (angle > 400 && speed < 0){

      val = 0;
    }
    // if (angle > 230 && speed == 0){
    if (angle > 130 && speed == 0){
      val = .05;
    }
  }*/
if (kidSafe){
  if (angle < 5 && speed > 0){
    val = 0;
  } else if (angle > 725 && speed < 0){
    val = 0;
  }
  if (angle > 230 && speed == 0){
    val = .05;
  }
}

  //previous was 70, 100
  if (joystickOverride && angle < 50) {
      val = -0.4;
  }
  if (!kidSafe){
  _armMotor->Set(val/2);
  } else if (kidSafe){
  _armMotor->Set(val/4);
  }
  frc::SmartDashboard::PutNumber("arm val", val);
}

//returns the current angle of the arm
//Check this
double Arm::getArmAngle() {
  float degree = _armMotorEncoder->Get();
  frc::SmartDashboard::PutNumber("Arm Distance", degree);
  return degree;
}

void Arm::resetArmEncoder() {
  if (!kidSafe){
    _armMotorEncoder->Reset();
    frc::SmartDashboard::PutString("Resetting?", "Yes");
  }
}
