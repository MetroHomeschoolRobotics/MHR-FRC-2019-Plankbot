/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoTest.h"

AutoTest::AutoTest() {

  //30 (rounded up) is encoder rotation value for driving off hab at beginning of auto period
  //-.25 is motor speed on y axis
  //With current gear ratio and wheel diameter, 1 drive train encoder rotation is 1.7599957" 
  AddSequential(new AutoDriveRotation(-30, 0, -0.25, 0, tankDriveFrontLeft));
}
