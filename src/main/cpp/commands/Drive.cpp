#include "commands/Drive.h"

Drive::Drive(frc::Joystick* driverControl, frc::Joystick* manipulatorControl) : frc::Command() {
	Requires(Robot::MainDrive());
	_driverControl = driverControl;
	_manipulatorControl = manipulatorControl;
}

void Drive::Initialize() {
}

void Drive::Execute() {
	double total = abs(_driverControl->GetRawAxis(0)) +
		abs(_driverControl->GetRawAxis(1)) +
		abs(_driverControl->GetRawAxis(2)) +
		abs(_driverControl->GetRawAxis(3));
	if (total > _threshold*2) {
		Robot::MainDrive()->Move(
				_driverControl->GetRawAxis(0),
				_driverControl->GetRawAxis(1),
				_driverControl->GetRawAxis(2) - _driverControl->GetRawAxis(3));
	} else {
		Robot::MainDrive()->Move(
				_manipulatorControl->GetRawAxis(0),
				_manipulatorControl->GetRawAxis(1),
				_manipulatorControl->GetRawAxis(2) - _manipulatorControl->GetRawAxis(3));
	}
}

bool Drive::IsFinished() {

	return false;

}

void Drive::End() {
}

void Drive::Interrupted() {
}
