#include "commands/Drive.h"

Drive::Drive(frc::Joystick* driverControl, frc::Joystick* manipulatorControl) : frc::Command() {
	Requires(Robot::MainDrive());
	_driverControl = driverControl;
	_manipulatorControl = manipulatorControl;
	//_mainDrive = mainDrive;
	_mainDrive = Robot::MainDrive();
}

void Drive::Initialize() {
}

void Drive::Execute() {
	double x = _driverControl->GetRawAxis(0);
	double y = _driverControl->GetRawAxis(1);
	double z = _driverControl->GetRawAxis(2) - _driverControl->GetRawAxis(3);
	double total = abs(x) + abs(y) + abs(z);
	bool kidSafe = _mainDrive->getKidSafe();

	if (total > _threshold*2) {
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
		// Cut overall speed in half
		x /= 2;
		y /= 2;
	} else {
		x = 0;
		y = 0;
		z = 0;
	}
	
	if (kidSafe){
		x /= 2;
		y /= 2;
	} else if (_driverControl->GetRawButton(6)) {
		x *= 2;
		y *= 2;
	} else if (_driverControl->GetRawButton(5)) {
		x /= 2;
		y /= 2;
	}

	Robot::MainDrive()->Move(x,	y, z);
}

bool Drive::IsFinished() {

	return false;

}

void Drive::End() {
}

void Drive::Interrupted() {
}
