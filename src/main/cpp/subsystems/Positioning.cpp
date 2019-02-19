#include "subsystems/Positioning.h"
#include "RobotMap.h"

Positioning::Positioning() : frc::Subsystem("PositioningSubsystem") {
	//distanceSensor = RobotMap::lidarDistanceSensor;
	ultrasonicAnalogSensor = RobotMap::ultrasonicAnalogDistanceSensor;
	ultrasonicSensor = RobotMap::ultrasonicDistanceSensor;
	gyro = RobotMap::gyro;
	//gyro.get()->Reset();
	navGyro = RobotMap::navGyro;
	frontLeft = RobotMap::tankDriveFrontLeft;
	frontRight = RobotMap::tankDriveFrontRight;
	rearLeft = RobotMap::tankDriveRearLeft;
	rearRight = RobotMap::tankDriveRearRight;
	liftMotor = RobotMap::liftMotor;
	armMotor = RobotMap::armMotor;
	armMotorEncoder = RobotMap::armMotorEncoder;
	//liftEncoder = RobotMap::liftMotorEncoder;
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
	
	frc::SmartDashboard::PutNumber("Lift Distance", GetLiftDistance());
	frc::SmartDashboard::PutNumber("Arm Distance", GetArmDistance());
	//frc::SmartDashboard::PutNumber("Top Limit Switch", !RobotMap::manipulatorTopSwitch.get()->Get());
	frc::SmartDashboard::PutNumber("Bottom Limit Switch", !RobotMap::manipulatorBottomSwitch.get()->Get());
	

	if (RobotMap::pixySPI != nullptr) {
		FRCPixyBlock* spiBlock = RobotMap::pixySPI->GetBlocks(0);
		if (spiBlock == nullptr){
			frc::SmartDashboard::PutNumber("SPI Blocks", 0);
			frc::SmartDashboard::PutNumber("SPI Block - X", 0);
			frc::SmartDashboard::PutNumber("SPI Block - Y", 0);
			frc::SmartDashboard::PutNumber("SPI Block - H", 0);
			frc::SmartDashboard::PutNumber("SPI Block - W", 0);
		} else {
			frc::SmartDashboard::PutNumber("SPI Blocks", 1);
			frc::SmartDashboard::PutNumber("SPI Block - X", spiBlock->getX()/1000);
			frc::SmartDashboard::PutNumber("SPI Block - Y", spiBlock->getY()/1000);
			frc::SmartDashboard::PutNumber("SPI Block - H", spiBlock->getHeight()/1000);
			frc::SmartDashboard::PutNumber("SPI Block - W", spiBlock->getWidth()/1000);
		}
	}

	if (RobotMap::pixyI2C != nullptr) {
		FRCPixyBlock* spiBlock = RobotMap::pixyI2C->GetBlocks(0);
		if (spiBlock == nullptr){
			frc::SmartDashboard::PutNumber("I2C Blocks", 0);
			frc::SmartDashboard::PutNumber("I2C Block - X", 0);
			frc::SmartDashboard::PutNumber("I2C Block - Y", 0);
			frc::SmartDashboard::PutNumber("I2C Block - H", 0);
			frc::SmartDashboard::PutNumber("I2C Block - W", 0);
		} else {
			frc::SmartDashboard::PutNumber("I2C Blocks", 1);
			frc::SmartDashboard::PutNumber("I2C Block - X", spiBlock->getX()/1000);
			frc::SmartDashboard::PutNumber("I2C Block - Y", spiBlock->getY()/1000);
			frc::SmartDashboard::PutNumber("I2C Block - H", spiBlock->getHeight()/1000);
			frc::SmartDashboard::PutNumber("I2C Block - W", spiBlock->getWidth()/1000);
		}
	}
/*
	FRCPixyVersion* version = RobotMap::pixySPI->CheckVersion();
	if (version == nullptr){
		std::wcout << L"Pixy - unknown version" << std::endl;
	} else {
		std::wcout << L"Pixy - version " << version->getFirmware() << std::endl;
	}
	*/
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

float Positioning::GetArmDistance() {
	return armMotorEncoder.get()->Get();
}

float Positioning::GetLiftDistance() {
	return liftMotor.get()->GetSelectedSensorPosition(0);//+9757;
}

void Positioning::ResetLiftEncoder() {
/*	if (!RobotMap::manipulatorBottomSwitch.get()->Get()) {
		liftEncoder.get()->Reset();
		liftMotor.get()->Reset();
	}*/
}

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
