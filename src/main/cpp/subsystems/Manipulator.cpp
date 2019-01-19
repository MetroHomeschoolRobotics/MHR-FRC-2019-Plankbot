/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Manipulator.h"


Manipulator::Manipulator(Positioning *positioning) : Subsystem("Manipulator Subsystem") {
  _liftMotor = RobotMap::liftMotor.get();
  _cargoMotor = RobotMap::cargoMotor.get();
  _armMotor = RobotMap::armMotor.get();
  _positioning = positioning;
}

void Manipulator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

//sets the lift motor to a specified speed
  void Manipulator::setLiftMotor(double speed) {
    _liftMotor->Set(speed);
  }

//sets the cargo intake/release motor to a speed
  void Manipulator::setCargoMotor(double speed) {
    _cargoMotor->Set(speed);
  }

//sets the arm motor to a specified speed
    void Manipulator::setArmMotor(double speed) {
    _armMotor->Set(speed);
  }

//returns the current angle of the arm
//Check this
  double Manipulator::getArmAngle()  {
    return _armPot->Get();
  }

//returns the distance the lifter has risen
  double Manipulator::getLiftDistance()  {
    return 0;
    // _liftMotor->GetAngle();
  }

//resets the lift encoder
  void Manipulator::resetLiftEncoder() {
    //_liftMotor->(reset)
  }


