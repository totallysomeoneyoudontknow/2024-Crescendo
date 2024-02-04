// Copyright (c) 2023-2024 CurtinFRC
// Open Source Software, you can modify it according to the terms
// of the MIT License at the root of this project
#pragma once

#include <frc/Servo.h>


#include "Wombat.h"

#include <frc/XboxController.h>


struct RobotMap {
    frc::Servo servo{9};
    frc::XboxController controller{0};
};