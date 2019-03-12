/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ApproachLoadingHatch.h"

ApproachLoadingHatch::ApproachLoadingHatch() {
  //mary says put it at 85
  AddSequential(new AutoArm(90, 0.6));
  // previous was 4950
  AddSequential(new AutoLift(3420, 0.6));
  AddSequential(new AutoArm(615, 0.6));
  //This is working on this test
}
