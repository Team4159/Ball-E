#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
const int DRIVE_LEFT_PORT = 0;
const int DRIVE_RIGHT_PORT = 1;

const int SHOOTER_PORT_A = 2;
const int SHOOTER_PORT_B = 3;
const int SHOOTER_PORT_C = 4;
const int SHOOTER_PORT_D = 5;

const int LIFTER_TOP_PORT = 6;
const int LIFTER_BOTTOM_PORT = 7;


const int JOYSTICK_LEFT_PORT = 1;
const int JOYSTICK_RIGHT_PORT = 2;

const int JOYSTICK_SHOOTER_PORT = JOYSTICK_RIGHT_PORT;
const int JOYSTICK_SHOOTER_BUTTON = 1;

const int JOYSTICK_TOP_LIFTER_PORT = JOYSTICK_RIGHT_PORT;
const int JOYSTICK_TOP_LIFTER_BUTTON_UP = 3;
const int JOYSTICK_TOP_LIFTER_BUTTON_DOWN = 2;

const int JOYSTICK_BOTTOM_LIFTER_PORT = JOYSTICK_LEFT_PORT;
const int JOYSTICK_BOTTOM_LIFTER_BUTTON_UP = 3;
const int JOYSTICK_BOTTOM_LIFTER_BUTTON_DOWN = 2;

#endif
