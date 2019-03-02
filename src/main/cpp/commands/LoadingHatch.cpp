/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LoadingHatch.h"

LoadingHatch::LoadingHatch() {
  AddParallel(new AutoArm(550, 0.4));
  AddParallel(new AutoLift(2000, 0.4));
}
