// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#include "Robot.h"

// include units
#include <units/velocity.h>
#include <units/acceleration.h>
#include <units/length.h>
#include <units/angle.h>
#include <units/time.h>
#include <units/voltage.h>

#include <frc/kinematics/DifferentialDriveKinematics.h>
#include <frc/controller/RamseteController.h>
#include <frc/Timer.h>

static units::second_t lastPeriodic;


void Robot::RobotInit() {}

void Robot::RobotPeriodic() {
  units::second_t dt = wom::now() - lastPeriodic;
  lastPeriodic = wom::now();

  loop.Poll();
  wom::BehaviourScheduler::GetInstance()->Tick();

  // climber->OnUpdate(dt);
}

void Robot::AutonomousInit() {
  // loop.Clear();
  // sched->InterruptAll();
}
void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
  loop.Clear();
  wom::BehaviourScheduler* scheduler = wom::BehaviourScheduler::GetInstance();
  scheduler->InterruptAll();
  // _swerveDrive->OnStart();
  // sched->InterruptAll();
}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {

}
void Robot::TestPeriodic() {

  double value = robotmap.controllers.coDriver.GetRightTriggerAxis();
  std::cout << value << std::endl;
  robotmap.climberSystem.servo.SetAngle(180 * value);
  
}