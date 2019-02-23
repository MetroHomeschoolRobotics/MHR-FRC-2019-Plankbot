/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LiftEncoderOverride.h"

LiftEncoderOverride::LiftEncoderOverride(Lift *lift) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _lift = lift;
//  _positioning = positioning;
}

// Called just before this Command runs the first time
void LiftEncoderOverride::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LiftEncoderOverride::Execute() {
  _lift->setOverride(true);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftEncoderOverride::IsFinished() { return false; }

// Called once after isFinished returns true
void LiftEncoderOverride::End() {
 _lift->setOverride(false);
 RobotMap::liftMotor.get()->SetSelectedSensorPosition(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftEncoderOverride::Interrupted() {}
