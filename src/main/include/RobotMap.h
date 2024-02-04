// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project
#pragma once

#include <frc/Compressor.h>
#include <frc/DoubleSolenoid.h>
#include <frc/XboxController.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc/system/plant/DCMotor.h>
#include <units/angle.h>
#include <units/length.h>

#include <string>

#include <ctre/phoenix6/CANcoder.hpp>
#include <ctre/phoenix6/Pigeon2.hpp>
#include <ctre/phoenix6/TalonFX.hpp>

#include "Climber.h"
#include "Wombat.h"

#include <frc/XboxController.h>
#include <frc/Servo.h>

struct RobotMap {

    struct Controllers{
        frc::XboxController driver = frc::XboxController(0);
        frc::XboxController coDriver = frc::XboxController(1);
    };
    Controllers controllers;

  struct Climber {
    frc::Servo servo {9};
    // rev::CANSparkMax* climberMotor = new rev::CANSparkMax{99, rev::CANSparkMax::MotorType::kBrushless};
    // wom::CANSparkMaxEncoder climberEncoder{climberMotor, 0.1_m};

    // wom::Gearbox climberGearbox{climberMotor, &climberEncoder, frc::DCMotor::NEO(1)};
    

    // ClimberConfig config{
    //     climberGearbox,
    // };
  };
  Climber climberSystem;
};
