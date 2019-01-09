#ifndef DRIVE_H
#define DRIVE_H

#include "frc/commands/Subsystem.h"
#include "../Robot.h"

class Drive: public frc::Command {

public:
	Drive(frc::Joystick* driverControl, frc::Joystick* manipulatorControl);
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;

private:
	double _threshold = 0.1;
	frc::Joystick* _driverControl;
	frc::Joystick* _manipulatorControl;
};

#endif
