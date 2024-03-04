// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project

#include "ShooterBehaviour.h"

ShooterManualControl::ShooterManualControl(Shooter* shooter, frc::XboxController* tester)
    : _shooter(shooter), _codriver(tester) {
  Controls(shooter);
}

void ShooterManualControl::OnTick(units::second_t dt) {
  table->GetEntry("RawControl").SetBoolean(_rawControl);


  if (_codriver->GetAButtonPressed()) {
    if (_rawControl) {
      _rawControl = false;
    } else {
      _rawControl = true;
    }
  }

    if (_rawControl) {
      _shooter->SetState(ShooterState::kRaw);
      
      if (_codriver->GetLeftTriggerAxis() > 0.1) {
        _shooter->SetRaw(12_V * _codriver->GetLeftTriggerAxis());
      } else if (_codriver->GetRightTriggerAxis() > 0.1) {
        _shooter->SetRaw(-12_V * _codriver->GetRightTriggerAxis());
      } else {
        _shooter->SetRaw(0_V);
      }

    } else {

      if (_codriver->GetPOV() == 0) { 
        _shooter->SetPidGoal(300_rad_per_s);
        _shooter->SetState(ShooterState::kSpinUp);
      } else if (_codriver->GetPOV() == 90) { // this will work with vision 
        // _shooter->SetPidGoal(300_rad_per_s);
        // _shooter->SetState(ShooterState::kSpinUp);
      } else if(_codriver->GetPOV() == 180){
        _shooter->SetPidGoal(200_rad_per_s);
        _shooter->SetState(ShooterState::kSpinUp);
      } else {
        _shooter->SetState(ShooterState::kIdle);
      }

    } 
} 


AutoShooter::AutoShooter(Shooter* shooter, units::radians_per_second_t speed)
  : _shooter(shooter), _speed(speed) {
    Controls(shooter);
}

void AutoShooter::OnTick(units::second_t dt){
  _shooter->SetPidGoal(_speed);
  _shooter->SetState(ShooterState::kSpinUp);
}