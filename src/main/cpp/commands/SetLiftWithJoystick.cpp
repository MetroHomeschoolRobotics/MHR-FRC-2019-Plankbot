/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetLiftWithJoystick.h"

SetLiftWithJoystick::SetLiftWithJoystick(Manipulator *manipulator, frc::Joystick* driverControl) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _manipulator = manipulator;
  _driverControl = driverControl;
}

// Called just before this Command runs the first time
void SetLiftWithJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetLiftWithJoystick::Execute() {
  double speed = _driverControl->GetRawAxis(5);
  _manipulator->setLiftMotor(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool SetLiftWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void SetLiftWithJoystick::End() {
  _manipulator->setLiftMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetLiftWithJoystick::Interrupted() {
  End();
}
