/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoDriveRotation.h"

AutoDriveRotation::AutoDriveRotation(double rotation, double driveX, double driveY, double driveZ, DriveMotorEncoder encoder) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::MainDrive());
	startPos = 0;
	targetPos = rotation;
	x = driveX;
	y = driveY;
	z = driveZ;
	encoderSource = encoder;
}

double AutoDriveRotation::GetEncoderValue() {
	switch(encoderSource){
		case tankDriveFrontLeft: return  Robot::PositioningSystem()->GetFrontLeftDistance();
		case tankDriveFrontRight: return  Robot::PositioningSystem()->GetFrontRightDistance();
		case tankDriveRearLeft: return  Robot::PositioningSystem()->GetRearLeftDistance();
		case tankDriveRearRight: return  Robot::PositioningSystem()->GetRearRightDistance();
	}
	return 0;
}

// Called just before this Command runs the first time
void AutoDriveRotation::Initialize() {
	startPos = GetEncoderValue();
	frc::SmartDashboard::PutNumber("Auto Drive Rotation Start", startPos);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveRotation::Execute() {
	Robot::MainDrive()->Move(x, y, z);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveRotation::IsFinished() {
	if (targetPos > 0) {
		return (GetEncoderValue() - startPos) > targetPos;
	} else {
		return (GetEncoderValue() - startPos) < -targetPos;
	}
}

// Called once after isFinished returns true
void AutoDriveRotation::End() {
	Robot::MainDrive()->Move(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveRotation::Interrupted() {
	End();
}
