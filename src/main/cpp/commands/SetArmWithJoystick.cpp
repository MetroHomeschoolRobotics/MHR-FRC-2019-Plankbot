/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetArmWithJoystick.h"

SetArmWithJoystick::SetArmWithJoystick(Manipulator *manipulator) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _manipulator = manipulator;
}

// Called just before this Command runs the first time
void SetArmWithJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void SetArmWithJoystick::Execute() {
  //joystickValue=OI.manipulatorJoystick.GetRawAxis(5);
  //currentAngle = Manipulator.GetArmAngle();
  _manipulator->setArmMotor(0);
}

// Make this return true when this Command no longer needs to run execute()
bool SetArmWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void SetArmWithJoystick::End() {
  _manipulator->setArmMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmWithJoystick::Interrupted() {
  End();
}
