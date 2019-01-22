#ifndef TANKDRIVE_H
#define TANKDRIVE_H

#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "Positioning.h"
#include "DriveSystem.h"

class TankDrive: public DriveSystem {

private:

	std::shared_ptr<rev::CANSparkMax> frontLeft;
	std::shared_ptr<rev::CANSparkMax> frontRight;
	std::shared_ptr<rev::CANSparkMax> rearRight;
	std::shared_ptr<rev::CANSparkMax> rearLeft;
	std::shared_ptr<Positioning> positioning;

public:
	double threshold = 0.1;

	TankDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z) override;
};

#endif
