/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Manipulator.h"

Manipulator::Manipulator() : Subsystem("ExampleSubsystem") {}

void Manipulator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

//sets the lift motor to a specified speed
  void setLiftMotor(double speed) {
    liftMotor->Set(speed);
  }

//sets the cargo intake/release motor to a speed
  void setCargoMotor(double speed) {
    cargoMotor->Set(speed);
  }

//sets the arm motor to a specified speed
    void setArmMotor(double speed) {
    armMotor->Set(speed);
  }

//returns the current angle of the arm
  double getArmAngle()  {
    armPot->Get();
  }

//returns the distance the lifter has risen
  double getLiftDistance()  {
    liftEncoder->GetDistance();
  }

//resets the lift encoder
  void resetLiftEncoder() {
    liftEncoder->Reset();
  }


