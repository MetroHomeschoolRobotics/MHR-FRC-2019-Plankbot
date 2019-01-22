#include "subsystems/Positioning.h"
#include "RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
	//distanceSensor = RobotMap::lidarDistanceSensor;
	ultrasonicAnalogSensor = RobotMap::ultrasonicAnalogDistanceSensor;
	ultrasonicSensor = RobotMap::ultrasonicDistanceSensor;
	gyro = RobotMap::gyro;
	gyro.get()->Reset();
	navGyro = RobotMap::navGyro;
	frontLeft = RobotMap::tankDriveFrontLeft;
	frontRight = RobotMap::tankDriveFrontRight;
	rearLeft = RobotMap::tankDriveRearLeft;
	rearRight = RobotMap::tankDriveRearRight;
}

void Positioning::UpdateDashboard(){
	frc::SmartDashboard::PutNumber("Front Left", GetFrontLeftDistance());
	frc::SmartDashboard::PutNumber("Front Right", GetFrontRightDistance());
	frc::SmartDashboard::PutNumber("Rear Left", GetRearLeftDistance());
	frc::SmartDashboard::PutNumber("Rear Right", GetRearRightDistance());
	frc::SmartDashboard::PutNumber("Gyro", GetGyroRotation());
	frc::SmartDashboard::PutNumber("Accleration Y", GetAccelY());
	frc::SmartDashboard::PutNumber("Acceleration X", GetAccelX());
	frc::SmartDashboard::PutNumber("Velocity X", GetVelocityX());
	frc::SmartDashboard::PutNumber("Velocity Y", GetVelocityY());
}


void Positioning::InitDefaultCommand() {
}

double Positioning::GetDistance() {
	//if (ultrasonicAnalogSensor.get()->CheckAnalogInputChannel(RobotMap::UltrasonicAnalogPort)) {
		// measured in inches
		frc::SmartDashboard::PutString("Distance Type", "Ultrasonic");
		double voltage = ultrasonicAnalogSensor.get()->GetVoltage();
		return voltage * 105;
	//} else {
		// measured in cm with a lot of variance
		//SmartDashboard::PutString("Distance Type", "Lidar");
		//return distanceSensor.get()->GetDistance();
	//}
	//return ultrasonicSensor.get()->GetRangeInches();

	//return distanceSensor.get()->GetDistance();
}

double Positioning::GetGyroRotation() {
	//return 0;
	return navGyro.get()->GetAngle();
	//return gyro.get()->GetAngle();
}

float Positioning::GetAccelX() {
	return navGyro.get()->GetRawAccelX();
}

float Positioning::GetAccelY() {
	return navGyro.get()->GetRawAccelY();
}

float Positioning::GetVelocityX() {
	return navGyro.get()->GetVelocityX();
}

float Positioning::GetVelocityY() {
	return navGyro.get()->GetVelocityY();
}

/*
double Positioning::GetArmRotation() {
	return RobotMap::liftMotor.get()->GetSelectedSensorPosition(0);
}
*/

double Positioning::GetFrontLeftDistance() {
	// encoder runs in reverse
	return -frontLeft.get()->GetEncoder().GetPosition();
}

double Positioning::GetFrontRightDistance() {
	return frontRight.get()->GetEncoder().GetPosition();
}

double Positioning::GetRearLeftDistance() {
	// encoder runs in reverse
	return -rearLeft.get()->GetEncoder().GetPosition();
}

double Positioning::GetRearRightDistance() {
	return rearRight.get()->GetEncoder().GetPosition();
}


