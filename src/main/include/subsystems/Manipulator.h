/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>

class Manipulator : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  //Motors for the lift, the arm, and the cargo collector; 
  //an encoder on the lift and a potentiometer on the arm
  std::shared_ptr<frc::Spark> liftMotor; 
  std::shared_ptr<frc::Encoder> liftEncoder;
	std::shared_ptr<frc::Spark> armMotor;
  std::shared_ptr<frc::AnalogPotentiometer> armPot;
	std::shared_ptr<frc::Spark> cargoMotor;
 
 public:
  Manipulator();
  void InitDefaultCommand() override;
  void setLiftMotor() override;
  void setCargoMotor() override;
  void setArmMotor() override;
  void resetLiftEncoder() override;
  double getArmAngle() override;
  double getLiftDistance() override;
};
