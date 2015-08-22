#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Lifter: public Subsystem
{
private:
	bool IsEnabled;

	Victor *LiftMotor;
public:
	Lifter(int lPort);
	void InitDefaultCommand();
	void SetState(bool state);
	void Enable();
	void Disable();
};

#endif
