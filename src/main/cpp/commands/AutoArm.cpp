/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoArm.h"

AutoArm::AutoArm(float height, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::ArmSystem());
	_armMotor = RobotMap::armMotor.get();
	_armMotorEncoder = RobotMap::armMotorEncoder.get();
	rate = speed;
	startPos = 0;
	targetPos = height;
}

float AutoArm::GetEncoderValue() {
  //return  Robot::PositioningSystem()->GetArmDistance();
  return _armMotorEncoder->Get();
}

// Called just before this Command runs the first time
void AutoArm::Initialize() {
	startPos = GetEncoderValue();
	if (startPos < targetPos) {
		rate = -abs(rate);
	} else {
		rate = abs(rate);
		//swapped absolute value of rates
	}
	frc::SmartDashboard::PutNumber("AutoArm Start", startPos);
	frc::SmartDashboard::PutNumber("AutoArm Speed", rate);
}

// Called repeatedly when this Command is scheduled to run
void AutoArm::Execute() {
  _armMotor->Set(rate);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoArm::IsFinished() {
	if (rate > 0) {
		return GetEncoderValue() < targetPos;
	} else {
		return GetEncoderValue() > targetPos;
	}
}

// Called once after IsFinished returns true
void AutoArm::End() {
	  _armMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArm::Interrupted() {
	End();
}