#include "Drive.h"
#include "../RobotMap.h"

Drive::Drive() :
		Subsystem("Drive")
{
	IsEnabled = false;
}

void Drive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Drive::FromJoystickInput(Joystick *_mLeft, Joystick *_mRight)
{
	MainDrive->TankDrive(_mLeft, _mRight, false);
}

void Drive::Stop()
{
	MainDrive->Drive(0, 0);
}

void Drive::Enable()
{
	IsEnabled = true;
}

void Drive::Disable()
{
	IsEnabled = false;
	Stop();
}
