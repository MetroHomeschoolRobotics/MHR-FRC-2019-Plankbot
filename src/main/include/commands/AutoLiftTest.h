/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/CommandGroup.h>
#include "AutoLift.h"
#include "RobotMap.h"
#include "../Robot.h"

class AutoLiftTest : public frc::CommandGroup {//candidate: AutoLift::AutoLift(float, Lift*)  AutoLift(float height, Lift *lift);
 public:
  AutoLiftTest();
};
