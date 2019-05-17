/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ApproachLoadingHatch.h"

ApproachLoadingHatch::ApproachLoadingHatch() {
  //was 90
  AddSequential(new AutoArm(110, 0.6));
  // previous was 4950
  AddSequential(new AutoLift(3420, 0.6));
  AddSequential(new AutoArm(715, 0.6));
  //Old value: 615
  //This is working on this test
}