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

void Drive::FromJoystickInput(double _mLeft, double _mRight)
{
	MainDrive->TankDrive(-1 * _mLeft, _mRight);
}

void Drive::Stop()
{
	MainDrive->Drive(0, 0);
}

void Drive::Enable()
{
	IsEnabled = true;
	Stop();
}

void Drive::Disable()
{
	IsEnabled = false;
	Stop();
}
