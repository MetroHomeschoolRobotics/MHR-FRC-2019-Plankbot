#ifndef Positioning_H
#define Positioning_H

#include "frc/Commands/Subsystem.h"
//#include "../LidarV3.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <AHRS.h>
#include <iostream>
#include <fstream>
#include "RobotMap.h"
using namespace std;


class Positioning : public frc::Subsystem {

private:

	//std::shared_ptr<LidarV3> distanceSensor;
	std::shared_ptr<frc::AnalogInput> ultrasonicAnalogSensor;
	std::shared_ptr<frc::Ultrasonic> ultrasonicSensor;

	std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	std::shared_ptr<AHRS> navGyro;

	std::shared_ptr<rev::CANSparkMax> frontLeft;
	std::shared_ptr<rev::CANSparkMax> frontRight;
	std::shared_ptr<rev::CANSparkMax> rearLeft;
	std::shared_ptr<rev::CANSparkMax> rearRight;

	std::shared_ptr<WPI_TalonSRX> liftMotor;
	std::shared_ptr<frc::Encoder> liftEncoder;

public:
	Positioning();
	void UpdateDashboard();
	void InitDefaultCommand();
	double GetDistance();
	double GetGyroRotation();
	double GetLiftDistance();
	double GetFrontLeftDistance();
	double GetFrontRightDistance();
	double GetRearLeftDistance();
	double GetRearRightDistance();
	float GetAccelX();
	float GetAccelY();
	float GetVelocityX();
	float GetVelocityY();

	double GetArmRotation();
};

#endif  // Positioning_H
