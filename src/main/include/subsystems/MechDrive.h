#ifndef MECHDRIVE_H
#define MECHDRIVE_H

#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "subsystems/Positioning.h"
#include "subsystems/DriveSystem.h"

class MechDrive: public DriveSystem {

private:

	std::shared_ptr<WPI_TalonSRX> frontLeft;
	std::shared_ptr<WPI_TalonSRX> frontRight;
	std::shared_ptr<WPI_TalonSRX> rearRight;
	std::shared_ptr<WPI_TalonSRX> rearLeft;
	std::shared_ptr<frc::MecanumDrive> driveTrain;
	std::shared_ptr<Positioning> positioning;

public:
	double threshold = 0.1;

	MechDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z) override;

};

#endif
