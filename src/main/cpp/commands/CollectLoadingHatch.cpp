/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CollectLoadingHatch.h"

CollectLoadingHatch::CollectLoadingHatch() {
  AddSequential(new AutoArm(100, 0.8));
  //We can slash the speed partway through
  AddSequential(new AutoArm(75, 0.2));
  AddSequential(new AutoLift(5, 0.5));
  //we want it to go to zero, but we wrote 10 for encoder slop
  AddSequential(new AutoArm(10, 0.2)); 
  //AddSequential(new AutoArm(85, 0.4));
  //AddSequential(new AutoLift(5, 0.4));
  //This one has been broken and might be going down too fast
}
