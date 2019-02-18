/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/SetArmWithJoystick.h"

SetArmWithJoystick::SetArmWithJoystick(Arm *arm, frc::Joystick* manipulatorControl) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::ArmSystem());
  _arm = arm;
  _manipulatorControl = manipulatorControl;
}

// Called just before this Command runs the first time
void SetArmWithJoystick::Initialize() {
  frc::SmartDashboard::PutString("ArmInit", "Initializing");
}

// Called repeatedly when this Command is scheduled to run
void SetArmWithJoystick::Execute() {
  double rate = _manipulatorControl->GetRawAxis(1);
  if (abs(rate)<_threshold){
    rate = -.15;
  }

   _arm->setArmMotor(rate);
   frc::SmartDashboard::PutString("ArmExec", "Executing");
   frc::SmartDashboard::PutNumber("ArmRate", rate);
}

// Make this return true when this Command no longer needs to run execute()
bool SetArmWithJoystick::IsFinished() { return false; }

// Called once after isFinished returns true
void SetArmWithJoystick::End() {
  _arm->setArmMotor(0);
  frc::SmartDashboard::PutString("ArmEnd", "Ending");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetArmWithJoystick::Interrupted() {
  End();
  frc::SmartDashboard::PutString("ArmInter", "interrupting");
}
