/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoTest.h"

AutoTest::AutoTest() {

  //AddSequential(new AutoDriveRotation(100, 0, 0.25, 0, tankDriveFrontLeft));
  AddSequential(new AutoDriveRotation(60, -0.25, 0, 0, tankDriveFrontLeft));
}
