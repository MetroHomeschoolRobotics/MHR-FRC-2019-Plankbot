/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoLiftTest.h"

AutoLiftTest::AutoLiftTest() {
  //5000 and 2000 are test values
  AddSequential(new AutoLift(5000, 0.25));
  AddSequential(new AutoLift(2000, -0.25));
}
