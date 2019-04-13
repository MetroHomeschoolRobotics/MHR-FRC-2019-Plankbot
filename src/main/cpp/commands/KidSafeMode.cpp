/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/KidSafeMode.h"

KidSafeMode::KidSafeMode(/*Arm *arm, Lift *lift, DriveSystem *mainDrive*/) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _arm = Robot::ArmSystem();
  _lift = Robot::LiftSystem();
  _mainDrive = Robot::MainDrive();
  //_arm = arm;
  //_lift = lift;
  //_mainDrive = mainDrive;
  //int armAngle = _arm->getArmAngle()
}

// Called just before this Command runs the first time
void KidSafeMode::Initialize() {
  frc::SmartDashboard::PutNumber("Run Kidsafe Start", _arm->getKidSafe());
}

// Called repeatedly when this Command is scheduled to run
void KidSafeMode::Execute() {
  _arm->kidSafeMode(true);
  _lift->kidSafeMode(true);
  _mainDrive->kidSafeMode(true);
}

// Make this return true when this Command no longer needs to run execute()
bool KidSafeMode::IsFinished() { return true; }

// Called once after isFinished returns true
void KidSafeMode::End() {
  frc::SmartDashboard::PutNumber("Run KidSafe End", _arm->getKidSafe());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KidSafeMode::Interrupted() {
  End();
}
