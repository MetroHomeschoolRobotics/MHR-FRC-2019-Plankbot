/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/CargoSystem.h"

CargoSystem::CargoSystem(Positioning *positioning) : Subsystem("Cargo Subsystem") {
    _cargoMotor = RobotMap::cargoMotor.get();
    _positioning = positioning;
}

void CargoSystem::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

//sets the cargo intake/release motor to a speed
  void CargoSystem::setCargoMotor(double speed) {
    _cargoMotor->Set(speed);
  }