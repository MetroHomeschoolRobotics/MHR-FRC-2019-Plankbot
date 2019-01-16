/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetLiftWithJoystick.h"

SetLiftWithJoystick::SetLiftWithJoystick() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SetLiftWithJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetLiftWithJoystick::Execute() {
  double speed = manipulatorJoystick.GetRawAxis(4);
  liftMotor->Set(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetLiftWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void SetLiftWithJoystick::End() {
  liftMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLiftWithJoystick::Interrupted() {
  End();
}
