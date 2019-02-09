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
		double x = _driverControl->GetRawAxis(0);
		double y = _driverControl->GetRawAxis(1);
		if (abs(x) < _threshold){
			x = 0;
		} else if (abs(x) < _threshold * 7){
			x /= 2;
		}
		if (abs(y) < _threshold){
			y = 0;
		} else if (abs(y) < _threshold * 7){
			y /= 2;
		}
		Robot::MainDrive()->Move(
				x,
				y,
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
