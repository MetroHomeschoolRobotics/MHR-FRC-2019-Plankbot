/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "frc/smartdashboard/SmartDashboard.h"

#include "commands/ArmEncoderOverride.h"
#include "commands/LiftEncoderOverride.h"
#include "commands/AutoTest.h"
#include "commands/AutoLift.h"
#include "commands/AutoArm.h"
#include "commands/LoadingHatch.h"
#include "commands/Drive.h"
#include "commands/SetLiftWithJoystick.h"
#include "commands/SetArmWithJoystick.h"
#include "commands/CollectCargo.h"
#include "commands/ReleaseCargo.h"
#include "commands/ApproachLoadingHatch.h"
#include "commands/CollectLoadingHatch.h"
#include "commands/LoadingCargo.h"

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

    collectButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 5));
    collectButton->WhileHeld(new CollectCargo(_cargoSystem));

    releaseButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 6));
    releaseButton->WhileHeld(new ReleaseCargo(_cargoSystem));

    approachLoadingHatchButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 1));
    approachLoadingHatchButton->WhenPressed(new ApproachLoadingHatch);

    collectLoadingHatchButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 3));
    collectLoadingHatchButton->WhenPressed(new CollectLoadingHatch);

    loadingCargoButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 2));
    loadingCargoButton->WhenPressed(new LoadingCargo);

    //lowLiftButton.reset(new frc::JoystickButton(driveJoystick.get(), 1));
    //lowLiftButton->WhenPressed(new AutoLift(2000, 0.4));
    //low rocket on new gear ratio is 4709

    //midRocketButton.reset(new frc::JoystickButton(driveJoystick.get(), 2));
    //midRocketButton->WhenPressed(new AutoLift(16750, 0.4));
    //mid rocket on new gear ratio is 16750
    //old mid rocket value was 15500

    //highRocketButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    //highRocketButton->WhenPressed(new AutoLift(28600, 0.4));

    armEncoderOverrideButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 8));
    armEncoderOverrideButton->WhileHeld(new ArmEncoderOverride(_arm));    //verticalArmButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 2));
    //verticalArmButton->WhenPressed(new AutoArm(180, 0.4));

    //loadingHatchButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 1));
    //loadingHatchButton->WhenPressed(new LoadingHatch());


    liftEncoderOverrideButton.reset(new frc::JoystickButton(driveJoystick.get(), 7));
    liftEncoderOverrideButton->WhileHeld(new LiftEncoderOverride(_lift));

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