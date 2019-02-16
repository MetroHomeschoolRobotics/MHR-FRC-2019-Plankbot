/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoLift.h"

//AutoLift::AutoLift(float height, Lift *lift) {
AutoLift::AutoLift(float height, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::LiftSystem());
	//_lift = lift;
	_liftMotor = RobotMap::liftMotor.get();
	rate = speed;
	startPos = 0;
	targetPos = height;
}

float AutoLift::GetEncoderValue() {
  return  Robot::PositioningSystem()->GetLiftDistance();
}

// Called just before this Command runs the first time
void AutoLift::Initialize() {
	startPos = GetEncoderValue();
	frc::SmartDashboard::PutNumber("AutoLift Start", startPos);
	  _liftMotor->Set(rate);
	  //::_liftMotor->setLiftMotor(0.25);
}

// Called repeatedly when this Command is scheduled to run
void AutoLift::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool AutoLift::IsFinished() {
	if (targetPos > 0) {
		return startPos > targetPos;
	} else {
		return startPos < targetPos;
	}
}

// Called once after isFinished returns true
void AutoLift::End() {
	  _liftMotor->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoLift::Interrupted() {
	End();
}