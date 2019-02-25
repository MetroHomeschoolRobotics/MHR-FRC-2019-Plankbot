/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ArmEncoderOverride.h"

ArmEncoderOverride::ArmEncoderOverride(Arm *arm) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _arm = arm;
}

// Called just before this Command runs the first time
void ArmEncoderOverride::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ArmEncoderOverride::Execute() {
  _arm->setOverride(true);
}

// Make this return true when this Command no longer needs to run execute()
bool ArmEncoderOverride::IsFinished(){ return false; }

// Called once after isFinished returns true
void ArmEncoderOverride::End() {
  _arm->resetArmEncoder();
  _arm->setOverride(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmEncoderOverride::Interrupted() {}