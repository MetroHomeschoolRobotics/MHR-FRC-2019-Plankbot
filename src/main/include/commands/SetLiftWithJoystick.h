/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "OI.h"
#include "subsystems/Manipulator.h"

class SetLiftWithJoystick : public frc::Command {
 public:
  SetLiftWithJoystick(Manipulator *manipulator, frc::Joystick* driverControl);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  Manipulator *_manipulator;
  frc::Joystick * _driverControl;
};
