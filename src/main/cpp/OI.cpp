/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "frc/smartdashboard/SmartDashboard.h"

#include "commands/AutoTest.h"
#include "commands/Drive.h"
#include "commands/AutoLiftTest.h"
#include "commands/SetLiftWithJoystick.h"
#include "commands/SetArmWithJoystick.h"
#include "commands/CollectCargo.h"
#include "commands/ReleaseCargo.h"

OI::OI(DriveSystem *drive, Positioning *positioning, CargoSystem *cargoSystem, Lift *lift, Arm *arm) {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    manipulatorJoystick.reset(new frc::Joystick(1));

    _driveCommand.reset(new Drive(driveJoystick.get(), manipulatorJoystick.get()));
    _drive = drive;
	_positioning = positioning;
	_cargoSystem = cargoSystem;
    _lift = lift;
    _arm = arm;

  _setLiftWithJoystick.reset(new SetLiftWithJoystick(_lift, driveJoystick.get()));

  _setArmWithJoystick.reset(new SetArmWithJoystick(_arm, manipulatorJoystick.get()));

    collectButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 3));
    collectButton->WhileHeld(new CollectCargo(_cargoSystem));

    releaseButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 4));
    releaseButton->WhileHeld(new ReleaseCargo(_cargoSystem));

    lowLiftButton.reset(new frc::JoystickButton(driveJoystick.get(), 1));
    lowLiftButton->WhenPressed(new AutoLift(2000, 0.4));

    midRocketButton.reset(new frc::JoystickButton(driveJoystick.get(), 2));
    midRocketButton->WhenPressed(new AutoLift(15500, 0.4));

    highRocketButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    highRocketButton->WhenPressed(new AutoLift(28600, 0.4));

    autoChooser = new frc::SendableChooser<frc::Command*>();
}

void OI::SetupDashboard() {
    //SmartDashboard Buttons
}

frc::SendableChooser<frc::Command*> *OI::getAutoChooser() {
	return autoChooser;
}

frc::Command* OI::DriveCommand() {
	return _driveCommand.get();
}

frc::Command* OI::LiftJoystick() {
    return _setLiftWithJoystick.get();
}

frc::Command* OI::ArmJoystick() {
    return _setArmWithJoystick.get();
}