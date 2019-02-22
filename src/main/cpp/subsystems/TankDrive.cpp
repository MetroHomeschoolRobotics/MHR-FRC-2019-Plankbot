#include "ctre/Phoenix.h"
#include "subsystems/TankDrive.h"
#include "RobotMap.h"

TankDrive::TankDrive() : DriveSystem("TankDrive") {
    frontLeft = RobotMap::tankDriveFrontLeft;
    frontRight = RobotMap::tankDriveFrontRight;
    rearRight = RobotMap::tankDriveRearRight;
    rearLeft = RobotMap::tankDriveRearLeft;
    //positioning = Robot::positioning;
}

void TankDrive::InitDefaultCommand() {
}

void TankDrive::Periodic() {
}

void TankDrive::Move(double x, double y, double z){
	if(fabs(x) < threshold) {
		x = 0;
	}

	if(fabs(y) < threshold) {
		y = 0;
	}
	x = -x;
	y = -y;

	frontLeft->Set((y-x));
	rearLeft->Set((y-x));
	frontRight->Set((-y-x));
	rearRight->Set((-y-x));
}
