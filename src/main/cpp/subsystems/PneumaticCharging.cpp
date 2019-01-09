/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/PneumaticCharging.h"

PneumaticCharging::PneumaticCharging(frc::Compressor* compressor) : Subsystem("Pneumatic Charging") {
	pneumoCharger = compressor;
}

void PneumaticCharging::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void PneumaticCharging::Charge() {
	pneumoCharger->SetClosedLoopControl(true);
}

void PneumaticCharging::StopCharging() {
	pneumoCharger->SetClosedLoopControl(false);
}

bool PneumaticCharging::ChargeComplete() {
	return pneumoCharger->GetPressureSwitchValue();
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
