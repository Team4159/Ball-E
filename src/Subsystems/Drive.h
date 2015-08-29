#ifndef Drive_H
#define Drive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Drive: public Subsystem
{
private:
	bool IsEnabled;

	Victor *LeftDrive = new Victor(DRIVE_LEFT_PORT);
	Victor *RightDrive = new Victor(DRIVE_RIGHT_PORT);
	RobotDrive *MainDrive = new RobotDrive(*LeftDrive, *RightDrive);
public:
	Drive();
	void InitDefaultCommand();
	void FromJoystickInput(double _mLeft, double _mRight);
	void Stop();
	void Enable();
	void Disable();
};

#endif
