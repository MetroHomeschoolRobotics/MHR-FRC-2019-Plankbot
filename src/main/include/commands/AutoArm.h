///----------------------------------------------------------------------------/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        /
/ Open Source Software - may be modified and shared by FRC teams. The code   /
/ must be accompanied by the FIRST BSD license file in the root directory of /
/ the project.                                                               /
/----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "../Robot.h" 
#include "subsystems/Lift.h"

class AutoArm : public frc::Command {
 public:
 AutoArm(float height, double speed);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

private:
    float startPos, targetPos;
  double rate;
    float GetEncoderValue();
  WPI_TalonSRX *_armMotor;
};