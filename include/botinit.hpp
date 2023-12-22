#pragma once
#include "main.h"
extern pros::Controller master;
// drive motors
extern pros::Motor lF; // left front motor. port 3, reversed
extern pros::Motor lM; // left middle motor. port 14, reversed
extern pros::Motor lB; // left back motor. port 12, reversed
extern pros::Motor rF; // right front motor. port 19
extern pros::Motor rM; // right middle motor. port 20
extern pros::Motor rB; // right back motor. port 1

extern pros::Rotation rot_sensor;

extern pros::MotorGroup leftMotors; // left motor group
extern pros::MotorGroup rightMotors;

extern pros::Motor intake;
extern pros::Motor cata;

extern pros::ADIDigitalOut flapLeftPiston; // ************FIX W/ ADI EXPANDER
extern pros::ADIDigitalOut flapRightPiston;
extern pros::ADIDigitalOut laDiabla;
extern pros::ADIDigitalOut blocker;

extern pros::Imu inertial_sensor;

extern lemlib::Drivetrain drivetrain;

// lateral motion controller
extern lemlib::ControllerSettings linearController;

// angular motion controller
extern lemlib::ControllerSettings angularController;

extern lemlib::OdomSensors sensors;
extern lemlib::Chassis chassis;