// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#include "Robot.h"

void Robot::RobotInit() {}

void Robot::RobotPeriodic() {

}

void Robot::AutonomousInit() {
  // loop.Clear();
  // sched->InterruptAll();
}
void Robot::AutonomousPeriodic() {
}

void Robot::TeleopInit() {
}
void Robot::TeleopPeriodic() {
  
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {

}
void Robot::TestPeriodic() {

  double value = robotmap.controller.GetRightTriggerAxis();
  std::cout << value << std::endl;
  robotmap.servo.SetAngle(180 * value);
  
}