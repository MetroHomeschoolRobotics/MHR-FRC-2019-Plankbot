/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>
#include "subsystems/Arm.h"
#include "subsystems/Lift.h"
#include "subsystems/DriveSystem.h"
#include "../Robot.h"

class KidSafeMode : public frc::Command {
 public:
  KidSafeMode(/*Arm *arm, Lift *lift, DriveSystem *mainDrive*/);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

  private:
  //Arm *_arm;
  //Lift *_lift;
  //DriveSystem *_mainDrive;
  //for no parameters:
  Arm* _arm;
  Lift* _lift;
  DriveSystem* _mainDrive;
};
