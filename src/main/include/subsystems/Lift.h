/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "subsystems/Positioning.h"
#include "subsystems/Arm.h"
#include "RobotMap.h"

class Lift : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  WPI_TalonSRX *_liftMotor;
  Positioning *_positioning;
  Arm *_arm;

 public:
  Lift(Positioning *positioning, Arm *arm);
  void InitDefaultCommand() override;
  void setOverride(bool active);
  void setLiftMotor(double speed);
  int GetLiftDistance();
  /*void resetLiftEncoder();
  float getLiftDistance();*/
 private:
  bool encoderOverride = false;
};