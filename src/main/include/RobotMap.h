/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

#include "frc/WPILib.h"
#include "ctre/Phoenix.h"
//#include "LidarV3.h"
#include "AHRS.h"
#include "rev/CANSparkMax.h"

class RobotMap {

public:
	static std::shared_ptr<rev::CANSparkMax> tankDriveFrontLeft;
	static std::shared_ptr<rev::CANSparkMax> tankDriveFrontRight;
	static std::shared_ptr<rev::CANSparkMax> tankDriveRearRight;
	static std::shared_ptr<rev::CANSparkMax> tankDriveRearLeft;

	static std::shared_ptr<WPI_TalonSRX> liftMotor;
	static std::shared_ptr<frc::Spark> cargoMotor;
	static std::shared_ptr<frc::Spark> armMotor;
	static std::shared_ptr<frc::AnalogPotentiometer> armPot;

	static std::shared_ptr<frc::DoubleSolenoid> octoDriveSwitchSol1;
	static std::shared_ptr<frc::DoubleSolenoid> liftGrabSol1;
	static std::shared_ptr<frc::DoubleSolenoid> pusherSol1;
	static std::shared_ptr<frc::DoubleSolenoid> pusherSol2;

	static std::shared_ptr<frc::Encoder> liftMotorEncoder;

	//static std::shared_ptr<LidarV3> lidarDistanceSensor;
	static std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	static std::shared_ptr<frc::Compressor> pneumoCharger;
	static std::shared_ptr<frc::Ultrasonic> ultrasonicDistanceSensor;
	static std::shared_ptr<frc::AnalogInput> ultrasonicAnalogDistanceSensor;
	static int UltrasonicAnalogPort;
	static std::shared_ptr<AHRS> navGyro;

	static void init();
};
