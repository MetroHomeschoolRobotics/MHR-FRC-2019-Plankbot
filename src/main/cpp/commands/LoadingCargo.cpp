/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LoadingCargo.h"

LoadingCargo::LoadingCargo() {
  AddSequential(new AutoArm(100, 0.6));
  AddSequential(new AutoLift(12000, 0.6));
}
