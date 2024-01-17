#include "ShooterBehaviour.h"


ShooterManualControl::ShooterManualControl(Shooter *shooter, frc::XboxController &codriver): _shooter(shooter), _codriver(codriver){
    Controls(shooter);
}

void ShooterManualControl::OnTick(units::second_t dt) {
    if (_codriver.GetLeftBumper()) {
       _shooter->setState(ShooterState::kSpinUp);
       _shooter->setPidGoal(65_rad_per_s);
    } else if (_codriver.GetRightBumper()) {
       _shooter->setState(ShooterState::kSpinUp);
       _shooter->setPidGoal(20_rad_per_s);
    }
    
    double rawControl;
    if(_codriver.GetAButtonPressed()){
        if (rawControl == true){
            rawControl = false;
        } else {
            rawControl = true;
        }
    }
if (!rawControl) { // rawControl == false
    if (_codriver.GetLeftBumper()) {
        _shooter->setState(ShooterState::kSpinUp);
        _shooter->setPidGoal(65_rad_per_s);
    } else if (_codriver.GetRightBumper()) {
        _shooter->setState(ShooterState::kSpinUp);
        _shooter->setPidGoal(20_rad_per_s);
    }
} else {
     _shooter->setRaw(0_V);
     
}

}