/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/* test */

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "commands/AutoTest.h"
#include "subsystems/TankDrive.h"

 std::unique_ptr<OI> Robot::m_oi;

std::shared_ptr<DriveSystem> Robot::m_mainDrive;
std::shared_ptr<Positioning> Robot::m_positioningSystem;
std::shared_ptr<PneumaticCharging> Robot::m_pneumaticCompressor;
std::shared_ptr<CargoSystem> Robot::m_cargoSystem;
std::shared_ptr<Lift> Robot::m_lift;
std::shared_ptr<Arm> Robot::m_arm;

void Robot::RobotInit() {
  RobotMap::init();

  m_mainDrive.reset(new TankDrive());
  m_defaultAutoCommand = new AutoTest();

  //m_leftAutoCommand = new AutoLeft();
  //m_centerAutoCommand = new AutoCenter();
  //m_rightAutoCommand = new AutoRight();

  m_chooser.SetDefaultOption("Test", m_defaultAutoCommand);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    //Instantiate OI
  //m_pneumaticCompressor.reset(new PneumaticCharging(RobotMap::pneumoCharger.get()));
  m_positioningSystem.reset(new Positioning());
  m_cargoSystem.reset(new CargoSystem(m_positioningSystem.get()));
  m_lift.reset(new Lift(m_positioningSystem.get()));
  m_arm.reset(new Arm(m_positioningSystem.get()));

	m_oi.reset(new OI(m_mainDrive.get(), m_positioningSystem.get(), m_cargoSystem.get(), m_lift.get(), m_arm.get()));
	m_oi.get()->SetupDashboard();
  }


/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }

  m_autonomousCommand = m_chooser.GetSelected();

  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Start();
  }

  
  m_oi.get()->DriveCommand()->Cancel();
  m_oi.get()->LiftJoystick()->Cancel();
  m_oi.get()->ArmJoystick()->Cancel();
  //added get arm joystick
}

void Robot::AutonomousPeriodic() { 
  frc::Scheduler::GetInstance()->Run(); 
  m_positioningSystem->UpdateDashboard(); 
  }

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  m_oi.get()->DriveCommand()->Start();
  m_oi.get()->LiftJoystick()->Start();
  m_oi.get()->ArmJoystick()->Start();
  //added arm joystick
}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run();
  m_positioningSystem->UpdateDashboard(); 
  
}

void Robot::TestPeriodic() {}

DriveSystem* Robot::MainDrive() {
  return m_mainDrive.get();
}


PneumaticCharging* Robot::PneumaticCompressor(){
    return m_pneumaticCompressor.get();
}
Positioning* Robot::PositioningSystem(){
    return m_positioningSystem.get();
}

Lift* Robot::LiftSystem(){
    return m_lift.get();
}

CargoSystem* Robot::Cargo(){
    return m_cargoSystem.get();
}

Arm* Robot::ArmSystem(){
    return m_arm.get();
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
