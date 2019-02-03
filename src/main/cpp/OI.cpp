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
#include "commands/SetLiftWithJoystick.h"
#include "commands/SetArmWithJoystick.h"
#include "commands/CollectCargo.h"
#include "commands/ReleaseCargo.h"
/*
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
OI::OI(DriveSystem *drive, Positioning *positioning, CargoSystem *cargoSystem, Lift *lift, Arm *arm) {

	//Instantiate the Joystick
    driveJoystick.reset(new frc::Joystick(0));
    manipulatorJoystick.reset(new frc::Joystick(1));
   // collectButton.reset(new frc::JoystickButton(driveJoystick.get(), 3));
    // releaseButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));

    _driveCommand.reset(new Drive(driveJoystick.get(), manipulatorJoystick.get()));
    _drive = drive;
	_positioning = positioning;
	_cargoSystem = cargoSystem;
    _lift = lift;
    _arm = arm;

//_setLiftWithJoystick.reset(new SetLiftWithJoystick(Lift *_lift, frc::Joystick))
  _setLiftWithJoystick.reset(new SetLiftWithJoystick(_lift, driveJoystick.get()));
    //Collect Button
  //  collectButton.reset(new frc::JoystickButton(driveJoystick.get(), 3));
    //collectButton->Execute(new CollectCargo());
    collectButton.reset(new frc::JoystickButton(driveJoystick.get(), 3));
    collectButton->WhileHeld(new CollectCargo(_cargoSystem));

    releaseButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    releaseButton->WhileHeld(new ReleaseCargo(_cargoSystem));

//        manipEatButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 3));
  //  manipEatButton->WhenPressed(new IntakeBox());

   //Grab Button
    //grabButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    //grabButton->ToggleWhenPressed(new Grab());


    //_setArmWithJoystick.reset(new SetArmWithJoystick(_manipulator, driveJoystick.get(), x));


    //Release Button
    //releaseButton.reset(new frc::JoystickButton(driveJoystick.get(), 4));
    //releaseButton->Execute(new ReleaseCargo());




    //manipGrabButton.reset(new frc::JoystickButton(manipulatorJoystick.get(), 4));
    //manipGrabButton->ToggleWhenPressed(new Grab());

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

 */
    autoChooser = new frc::SendableChooser<frc::Command*>();
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

frc::Command* OI::DriveCommand() {
	return _driveCommand.get();
}

frc::Command* OI::LiftJoystick() {
    return _setLiftWithJoystick.get();
}