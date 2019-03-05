/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoRight.h"

AutoRight::AutoRight() {//Requires(Robot::MainDrive());
	AddSequential(new AutoDrive(8500, -0.8,-0.5));
	AddSequential(new AutoDrive(23000, 0,-0.5));
	AddSequential(new AutoDrive(3000, 0.7,-0.5));
	AddSequential(new AutoDrive(2000, 0,-0.5));
}
