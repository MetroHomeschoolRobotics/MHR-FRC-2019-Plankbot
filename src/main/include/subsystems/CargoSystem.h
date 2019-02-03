/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "subsystems/Positioning.h"
#include "RobotMap.h"

class CargoSystem : public frc::Subsystem {
 private:
 frc::Spark *_cargoMotor;
 Positioning *_positioning;

 public:
  CargoSystem(Positioning *positioning);
  void InitDefaultCommand() override;
  void setCargoMotor(double speed);
};