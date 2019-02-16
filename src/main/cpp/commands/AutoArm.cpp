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
	rate = speed;
	startPos = 0;
	targetPos = height;
}

float AutoArm::GetEncoderValue() {
  return  Robot::PositioningSystem()->GetArmDistance();
}

// Called just before this Command runs the first time
void AutoArm::Initialize() {
	startPos = GetEncoderValue();
	frc::SmartDashboard::PutNumber("AutoArm Start", startPos);
	  _armMotor->Set(rate);
}

// Called repeatedly when this Command is scheduled to run
void AutoArm::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoArm::IsFinished() {
	if (targetPos > 0) {
		return startPos > targetPos;
	} else {
		return startPos < targetPos;
	}
}

// Called once after isFinished returns true
void AutoArm::End() {
	  _armMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArm::Interrupted() {
	End();
}