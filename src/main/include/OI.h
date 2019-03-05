/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"
#include "subsystems/CargoSystem.h"
#include "subsystems/Lift.h"
#include "subsystems/Arm.h"
#include "subsystems/Positioning.h"
#include "subsystems/DriveSystem.h"

class OI {

private:

	//Create Private Objects
	std::shared_ptr<frc::Command> _driveCommand;
	std::shared_ptr<frc::Command> _setLiftWithJoystick;
	std::shared_ptr<frc::Command> _setArmWithJoystick;
	std::shared_ptr<frc::Joystick> driveJoystick;
	std::shared_ptr<frc::Joystick> manipulatorJoystick;
	frc::SendableChooser<frc::Command*> *autoChooser;
	std::shared_ptr<frc::JoystickButton> collectButton;
	std::shared_ptr<frc::JoystickButton> releaseButton;
	//std::shared_ptr<frc::JoystickButton> lowLiftButton;
	//std::shared_ptr<frc::JoystickButton> midRocketButton;
	//std::shared_ptr<frc::JoystickButton> highRocketButton;
	//std::shared_ptr<frc::JoystickButton> verticalArmButton;
	//std::shared_ptr<frc::JoystickButton> flatArmButton;
	//std::shared_ptr<frc::JoystickButton> loadingHatchButton;
	std::shared_ptr<frc::JoystickButton> armEncoderOverrideButton;
	std::shared_ptr<frc::JoystickButton> liftEncoderOverrideButton;
	std::shared_ptr<frc::JoystickButton> approachLoadingHatchButton;
	std::shared_ptr<frc::JoystickButton> collectLoadingHatchButton;

	DriveSystem *_drive;
	Positioning *_positioning; 
	CargoSystem *_cargoSystem;
	Lift *_lift;
	Arm *_arm;

public:

	OI(DriveSystem *drive, Positioning *positioning, CargoSystem *cargoSystem, Lift *lift, Arm *arm);

	void SetupDashboard();

	//Create Private Inputs
	frc::Command* DriveCommand();
	frc::Command* LiftJoystick();
	frc::Command* ArmJoystick();
	frc::SendableChooser<frc::Command*> *getAutoChooser();
};
