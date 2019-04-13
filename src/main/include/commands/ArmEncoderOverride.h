/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "subsystems/Arm.h"
#include "OI.h"
#include "Robot.h"

class ArmEncoderOverride : public frc::Command {
 public:
  ArmEncoderOverride(Arm *arm);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
   Arm *_arm;
   bool IsKidSafe();
   //bool kidSafe = _arm->getKidSafe();
};
