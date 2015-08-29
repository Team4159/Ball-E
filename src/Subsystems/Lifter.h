#ifndef Lifter_H
#define Lifter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Lifter: public Subsystem
{
private:
	bool IsEnabled;
	bool IsInverted;

	Victor *LiftMotor;
public:
	Lifter(int lPort, bool inverted);
	void InitDefaultCommand();
	void SetState(int state);
	void Enable();
	void Disable();
	enum State {
		UP,DOWN,OFF
	};
};

#endif
