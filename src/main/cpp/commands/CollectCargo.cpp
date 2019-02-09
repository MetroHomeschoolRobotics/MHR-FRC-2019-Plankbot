/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CollectCargo.h"

CollectCargo::CollectCargo(CargoSystem *cargoSystem) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::Cargo());
  _cargoSystem = cargoSystem;
}

// Called just before this Command runs the first time
void CollectCargo::Initialize() {}

// Called repeatedly when this Command is scheduled to run
//When CollectCargo is called, wheels spin to collect 
void CollectCargo::Execute() {
//  bool collect = _driverControl->GetRawButton(3);
    _cargoSystem->setCargoMotor(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool CollectCargo::IsFinished() { return false; }

// Called once after isFinished returns true
//When ended, motor turns off
void CollectCargo::End() {
  _cargoSystem->setCargoMotor(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CollectCargo::Interrupted() {
  End();
}