/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "subsystems/Positioning.h"
#include "RobotMap.h"

class Arm : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  WPI_TalonSRX *_armMotor;
  frc::Encoder *_armMotorEncoder;
  Positioning *_positioning;

 public:
  Arm(Positioning *positioning);
  void InitDefaultCommand() override;
  void kidSafeMode(bool safe);
  bool getKidSafe();
  void overrideJoystick(bool ignore);
  void setOverride(bool active);
  void setArmMotor(double speed);
  double getArmAngle();
  void resetArmEncoder();
 
 private:
  bool joystickOverride = false;
  bool kidSafe = false;
  bool encoderOverride = false;
};
