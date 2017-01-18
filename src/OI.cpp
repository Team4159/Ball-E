#include "OI.h"

OI::OI()
{
	// Process operator interface input here.
}

Joystick *OI::GetLeftJoystick()
{
	return LeftJoystick;
}

Joystick *OI::GetRightJoystick()
{
	return RightJoystick;
}

Joystick *OI::GetJoystick(int port)
{
	switch(port)
	{
	case JOYSTICK_RIGHT_PORT:
		return RightJoystick;
	case JOYSTICK_LEFT_PORT:
		return LeftJoystick;
	default:
		return 0;
	}
}
