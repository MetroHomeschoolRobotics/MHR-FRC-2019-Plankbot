/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Lift.h"
#include <cmath>

Lift::Lift(Positioning *positioning, Arm *arm) : Subsystem("Lift Subsystem") {
  _liftMotor = RobotMap::liftMotor.get();
  _arm = arm;
  _positioning = positioning;
}

void Lift::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Lift::kidSafeMode(bool safe){
  kidSafe = safe;
}

int Lift::GetLiftDistance() {
  return _positioning->GetLiftDistance();
}

void Lift::setOverride(bool active){
  if (active && !kidSafe) {
    encoderOverride = true;
  } else {
    encoderOverride = false;
  }
}

//sets the lift motor to a specified speed
  void Lift::setLiftMotor(double speed) {
    //_liftMotor->Set(speed);
    int pos = RobotMap::liftMotor.get()->GetSelectedSensorPosition(0);
  if (!encoderOverride && !kidSafe) {
    if (pos > 28000 && speed > 0){
      speed = 0;
    } else if (speed > 0 && pos > 23000){
      speed /= 2;
    } else if (speed > 0 && pos > 25000){
      speed /= 2;
   // } else if (speed < 0 && pos < 2000){
    //  speed /= 2;
    //real will be 7000?
    } else if (speed < 0 && pos < 12000){
      speed /= 3;
    }
    if (speed < -0.6){
      speed = -0.6;
    }
  //if (kidSafe){
  //  if (pos > )
  }
  if (kidSafe) {
    if (pos > 24000 && speed > 0){
      speed = 0;
    } else if (speed > 0 && pos > 23000){
      speed /= 3;
    } else if (speed > 0 && pos > 25000){
      speed /= 2;
    } else if (speed < 0 && pos < 13000){
      speed /= 4;
    }
    if (speed < -0.5){
      speed = -0.5;
    }
  }
    //frc::SmartDashboard::PutNumber("lift val", val);
   //if (abs(speed) > 0 && RobotMap::armMotorEncoder.get()->Get() < 70){
    // RobotMap::armMotor.get()->Set(-0.4);
    //  speed = 0;
    //}
  //}

  //if (kidSafe)
  
  if (!RobotMap::manipulatorBottomSwitch.get()->Get()) {
    RobotMap::liftMotor.get()->SetSelectedSensorPosition(0, 0);
  }
  if (speed < 0 && !RobotMap::manipulatorBottomSwitch.get()->Get()){
      // Bottom Limit Switch Hit -- STOP!!
    speed = 0;
     //RobotMap::liftMotor.get()->SetSelectedSensorPosition(0, 0);
    } else if (speed > 0 && !RobotMap::manipulatorTopSwitch.get()->Get()){
    // Top Limit Switch Hit -- STOP!!
    speed = 0;
    }

  if (pos > 3500 && speed == 0){
      speed = .15;
  } else if (speed == 0){
      speed = .05;
    }
   
 /*
    if (!RobotMap::manipulatorBottomSwitch.get()->Get()){
// If the bottom limit switch is pressed, we want to keep the values between 1 and 0
      speed = fmax(speed, 0);
    } else if (!RobotMap::manipulatorTopSwitch.get()->Get()){ 
// If the top limit switch is pressed, we want to keep the values between 0 and -1
      speed = fmin(speed, 0);
    }
    */
   //PREVIOUS WAS 70
  if (_arm->getArmAngle() < 100 && (speed > 0.15 || speed < 0)) {
    _arm->overrideJoystick(true);
    if (pos < 3500) {
      _liftMotor->Set(0.05);
    } else {
    _liftMotor->Set(0.15);
    }
  } else {
    _arm->overrideJoystick(false);

    if (!kidSafe){
    _liftMotor->Set(speed);
    } else if (kidSafe){
    _liftMotor->Set(speed/2);
    }
    //_liftMotor->Set(speed);
    frc::SmartDashboard::PutNumber("lift speed", speed);
  }
}

bool Lift::getKidSafe() {
  return kidSafe;
}
//returns the distance the lifter has risen
  /*float Lift::getLiftDistance()  {
    return 0;
    //return lift encoder distance
  }

//resets the lift encoder
  void Lift::resetLiftEncoder() {
    //_liftMotor->(reset)
  }*/