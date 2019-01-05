#include "ctre/Phoenix.h"
#include "subsystems/MechDrive.h"
#include "RobotMap.h"

std::shared_ptr<Positioning> positioning;
std::shared_ptr<frc::MecanumDrive> driveTrain;

MechDrive::MechDrive() : DriveSystem("MechDrive") {

	frontLeft = RobotMap::tankDriveFrontLeft;
    frontRight = RobotMap::tankDriveFrontRight;
    rearRight = RobotMap::tankDriveRearRight;
    rearLeft = RobotMap::tankDriveRearLeft;
    //positioning = Robot::positioning;
    driveTrain = RobotMap::mainDrive;
    driveTrain.get()->SetSafetyEnabled(false);
}

void MechDrive::InitDefaultCommand() {
}

void MechDrive::Periodic() {
}

void MechDrive::Move(double x, double y, double z){
	double distance = positioning.get()->GetDistance();
	// Output sensor data
	//std::printf("Lidar Distance %4.2f \n", distance);
	//std::printf("Gyro Angle %4.2f \n", positioning.get()->GetAngle());

	if(fabs(x) < threshold) {
		x = 0;
	}

	if(fabs(y) < threshold) {
		y = 0;
	}

	if(fabs(z) < threshold) {
		z = 0;
	}

	//driveTrain.get()->DriveCartesian(x, y, z, positioning.get()->GetAngle());
	frontLeft->Set(y-x+z);
	rearLeft->Set(y+x+z);
	frontRight->Set(-y-x+z);
	rearRight->Set(-y+x+z);
}
