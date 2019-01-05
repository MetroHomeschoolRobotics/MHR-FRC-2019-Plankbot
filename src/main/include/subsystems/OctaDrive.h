#pragma once

#ifndef OCTADRIVE_H
#define OCTADRIVE_H

#include "frc/commands/Subsystem.h"
#include "frc/WPILib.h"
#include "DriveSystem.h"

class OctaDrive: public DriveSystem {

private:

	std::shared_ptr<frc::DoubleSolenoid> switchSol1;

	bool isTank = true;

public:
	double threshold = 0.1;

	OctaDrive();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Move(double x, double y, double z) override;
	void SwitchMode();
	bool IsTankDrive();
};

#endif
