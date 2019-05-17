/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetClimb.h"

SetClimb::SetClimb(Climb *climb, frc::Joystick* driverControl) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _climb = climb;
  _driverControl = driverControl;

}

// Called just before this Command runs the first time
void SetClimb::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetClimb::Execute() {
  //right goes up, left goes down
  double left = _driverControl->GetRawAxis(2);
  double right = 0-_driverControl->GetRawAxis(3);
  double rate = 0;
  if (fabs(right) >= threshold && fabs(left) < threshold){
    rate = right;
  }
  else if (fabs(left) >= threshold && fabs(right) < threshold){
    rate = left;
  }
  else if (fabs(left) >= threshold && fabs(right) >= threshold){
    //with input from both, cancel inputs
    rate = right + left;
  }
  frc::SmartDashboard::PutNumber("right trigger", right);
  frc::SmartDashboard::PutNumber("left trigger", left);
  frc::SmartDashboard::PutNumber("hab climb rate", rate);
  _climb->setClimbMotor(rate);
}

// Make this return true when this Command no longer needs to run execute()
bool SetClimb::IsFinished() { return false; }

// Called once after isFinished returns true
void SetClimb::End() {
  _climb->setClimbMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetClimb::Interrupted() {
  End();
}
