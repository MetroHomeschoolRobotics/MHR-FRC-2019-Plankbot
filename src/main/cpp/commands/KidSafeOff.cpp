/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/KidSafeOff.h"

KidSafeOff::KidSafeOff(Arm *arm, Lift *lift, DriveSystem *mainDrive) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _arm = arm;
  _lift = lift;
  _mainDrive = mainDrive;
  //_arm = Robot::ArmSystem();
  //_lift = Robot::LiftSystem();
  //_mainDrive = Robot::MainDrive();
}

// Called just before this Command runs the first time
void KidSafeOff::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void KidSafeOff::Execute() {
  frc::SmartDashboard::PutString("KidSafe", "Off");
  _arm->kidSafeMode(false);
  _lift->kidSafeMode(false);
  _mainDrive->kidSafeMode(false);
}

// Make this return true when this Command no longer needs to run execute()
bool KidSafeOff::IsFinished() { return true; }

// Called once after isFinished returns true
void KidSafeOff::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void KidSafeOff::Interrupted() {
  End();
}
