#ifndef Positioning_H
#define Positioning_H

#include "frc/Commands/Subsystem.h"
//#include "../LidarV3.h"
#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
#include <AHRS.h>
#include <iostream>
#include <fstream>
using namespace std;


class Positioning : public frc::Subsystem {

private:

	//std::shared_ptr<LidarV3> distanceSensor;
	std::shared_ptr<frc::AnalogInput> ultrasonicAnalogSensor;
	std::shared_ptr<frc::Ultrasonic> ultrasonicSensor;

	std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	std::shared_ptr<AHRS> navGyro;

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;
	std::shared_ptr<WPI_TalonSRX> rearRight;

public:
	Positioning();
	void UpdateDashboard();
	void InitDefaultCommand();
	double GetDistance();
	double GetGyroRotation();
	double GetFrontLeftDistance();
	double GetFrontRightDistance();
	double GetRearLeftDistance();
	double GetRearRightDistance();

	double GetArmRotation();
};

#endif  // Positioning_H
