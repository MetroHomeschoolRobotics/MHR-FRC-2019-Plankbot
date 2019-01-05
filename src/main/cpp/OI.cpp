/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>
#include "frc/smartdashboard/SmartDashboard.h"

#include "Commands/AutoLeft.h"
/* #include "Commands/Drive.h"
#include "Commands/Lift.h"
#include "Commands/SwitchDrive.h"
#include "Commands/Grab.h"
#include "Commands/OverrideLiftRotate.h"
#include "Commands/IntakeBox.h"
#include "Commands/ReleaseBox.h"
#include "Commands/CloseClamp.h"
#include "Commands/OpenClamp.h"
#include "Commands/Eject.h"
#include "Commands/ChargePneumatics.h"
#include "Commands/Drool.h"
#include "Commands/ArmPreset.h"
 */
OI::OI() {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    manipulatorJoystick.reset(new frc::Joystick(1));
    
    //SwitchDrive Button
   /*  switchDriveButton.reset(new frc::JoystickButton(driveJoystick.get(), 1));
    switchDriveButton->ToggleWhenPressed(new SwitchDrive());

    manipSwitchDriveButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 1));
    manipSwitchDriveButton->ToggleWhenPressed(new SwitchDrive());
 */
    //Grab Button
    //grabButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    //grabButton->ToggleWhenPressed(new Grab());

    //manipGrabButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 4));
    //manipGrabButton->ToggleWhenPressed(new Grab());

    //Override Button
/*     overrideButton.reset(new frc::JoystickButton(driveJoystick.get(), 5));
    overrideButton->ToggleWhenPressed(new OverrideLiftRotate());
 */
    //manipOverrideButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 5));
    //manipOverrideButton->ToggleWhenPressed(new OverrideLiftRotate());

/*     driveEatButton.reset(new frc::JoystickButton(driveJoystick.get(), 3));
    driveEatButton->WhenPressed(new IntakeBox());

    manipEatButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 3));
    manipEatButton->WhenPressed(new IntakeBox());

    drivePukeButton.reset(new frc::JoystickButton(driveJoystick.get(), 2));
    drivePukeButton->WhenPressed(new ReleaseBox());

    manipPukeButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 2));
    manipPukeButton->WhenPressed(new ReleaseBox());

    droolButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    droolButton->WhenPressed(new Drool());

    manipDroolButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 4));
    manipDroolButton->WhenPressed(new Drool());

    frc::JoystickButton *armPreset1 = new frc::JoystickButton(driveJoystick.get(), 7);
    armPreset1->WhenPressed(new ArmPreset(17900));

    frc::JoystickButton *armPreset2 = new frc::JoystickButton(driveJoystick.get(), 8);
    armPreset2->WhenPressed(new ArmPreset(8000));

    frc::JoystickButton *manipArmPreset1 = new frc::JoystickButton(manipulatorJoystick.get(), 7);
    manipArmPreset1->WhenPressed(new ArmPreset(17900));

    frc::JoystickButton *manipArmPreset2 = new frc::JoystickButton(manipulatorJoystick.get(), 8);
    manipArmPreset2->WhenPressed(new ArmPreset(8000));

 */    autoChooser = new frc::SendableChooser<frc::Command*>();
}

void OI::SetupDashboard() {
    //SmartDashboard Buttons
/*     frc::SmartDashboard::PutData("Charge Pneumatics", new ChargePneumatics());
    frc::SmartDashboard::PutData("Switch Drive", new SwitchDrive());
    frc::SmartDashboard::PutData("Drool", new Drool());
    frc::SmartDashboard::PutData("Eat", new IntakeBox());
    frc::SmartDashboard::PutData("Puke", new ReleaseBox());

    autoChooser->AddObject("Start Left", new AutoLeft());
    autoChooser->AddDefault("Start Center", new AutoCenter());
    autoChooser->AddObject("Start Right", new AutoRight());
    frc::SmartDashboard::PutData("Autonomous Start", autoChooser);
 */}

frc::SendableChooser<frc::Command*> *OI::getAutoChooser() {
	return autoChooser;
}

std::shared_ptr<frc::Joystick> OI::getDriveJoystick() {
	return driveJoystick;
}

std::shared_ptr<frc::Joystick> OI::getManipulatorJoystick() {
	return manipulatorJoystick;
}

std::shared_ptr<frc::JoystickButton> OI::getOverrideButton() {
	return overrideButton;
}

std::shared_ptr<frc::JoystickButton> OI::getManipOverrideButton(){
	return manipOverrideButton;
}

std::shared_ptr<frc::JoystickButton> OI::getClampInButton() {
	return clampInButton;
}

std::shared_ptr<frc::JoystickButton> OI::getClampOutButton() {
	return clampOutButton;
}
