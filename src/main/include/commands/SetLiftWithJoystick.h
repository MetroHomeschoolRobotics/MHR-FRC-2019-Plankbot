/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "subsystems/Lift.h"
#include "subsystems/Positioning.h"
#include "OI.h"
#include "Robot.h"

class SetLiftWithJoystick : public frc::Command {
 
 public:
  SetLiftWithJoystick(Lift *lift, frc::Joystick* manipulatorControl);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  Lift *_lift;
  double _threshold = 0.1;
  frc::Joystick * _manipulatorControl;
};
