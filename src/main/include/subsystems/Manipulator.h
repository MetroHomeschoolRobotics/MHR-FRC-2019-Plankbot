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


class Manipulator : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  //Motors for the lift, the arm, and the cargo collector; 
  //an encoder on the lift and a potentiometer on the arm
  WPI_TalonSRX *_liftMotor; 
  //std::shared_ptr<frc::Encoder> liftEncoder;
	frc::Spark *_armMotor;
  frc::AnalogPotentiometer *_armPot;
	frc::Spark *_cargoMotor;
  Positioning *_positioning;

 public:
  Manipulator(Positioning *positioning);
  void InitDefaultCommand();
  void setLiftMotor(double speed);
  void setCargoMotor(double speed);
  void setArmMotor(double speed);
  void resetLiftEncoder();
  double getArmAngle();
  double getLiftDistance();
};
