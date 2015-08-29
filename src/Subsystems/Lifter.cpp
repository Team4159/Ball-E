#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter(int lPort, bool inverted) :
		Subsystem("ExampleSubsystem")
{
	LiftMotor = new Victor(lPort);
	IsEnabled = false;
	IsInverted = inverted;
}

void Lifter::InitDefaultCommand()
{

}

void Lifter::SetState(int state)
{
	if(IsEnabled)
	{
		switch(state)
		{
		case State::OFF:
			LiftMotor->Set(0.0);
			break;
		case State::UP:
			LiftMotor->Set(IsInverted ? -1.0 : 1.0);
			break;
		case State::DOWN:
			LiftMotor->Set(IsInverted ? 1.0 : -1.0);
			break;
		}
	}
}

void Lifter::Enable()
{
	IsEnabled = true;
}

void Lifter::Disable()
{
	IsEnabled = false;
	SetState(State::OFF);
}
