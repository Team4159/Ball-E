#ifndef OI_H
#define OI_H

#include "WPILib.h"
#include "RobotMap.h"

class OI
{
private:
	Joystick *LeftJoystick = new Joystick(JOYSTICK_LEFT_PORT);
	Joystick *RightJoystick = new Joystick(JOYSTICK_RIGHT_PORT);
public:
	OI();
	Joystick *GetLeftJoystick();
	Joystick *GetRightJoystick();
	Joystick *GetJoystick(int port);
};

#endif
