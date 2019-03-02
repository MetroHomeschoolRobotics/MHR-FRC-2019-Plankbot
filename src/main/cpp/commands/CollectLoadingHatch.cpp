/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CollectLoadingHatch.h"

CollectLoadingHatch::CollectLoadingHatch() {
  AddSequential(new AutoArm(75, 0.4));
  AddSequential(new AutoLift(5, 0.4));
}
