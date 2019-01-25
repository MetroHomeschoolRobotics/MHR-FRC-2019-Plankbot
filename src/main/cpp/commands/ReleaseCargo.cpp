/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ReleaseCargo.h"

ReleaseCargo::ReleaseCargo(Manipulator *manipulator) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  _manipulator = manipulator;
}

// Called just before this Command runs the first time
void ReleaseCargo::Initialize() {}

// Called repeatedly when this Command is scheduled to run
//When called, cargoMotor spins to shoot cargo 
void ReleaseCargo::Execute() {
//  _manipulator->setCargoMotor(1);
  //bool release = _driverControl->GetRawButton(4);
//  _manipulator->setCargoMotor(-1);
    _manipulator->setCargoMotor(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool ReleaseCargo::IsFinished() { return true; }

// Called once after isFinished returns true
//When ended, cargoMotor turned off
void ReleaseCargo::End() {
  _manipulator->setCargoMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReleaseCargo::Interrupted() {
  End();
}
