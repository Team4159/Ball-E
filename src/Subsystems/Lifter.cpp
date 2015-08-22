#include "Lifter.h"
#include "../RobotMap.h"

Lifter::Lifter(int lPort) :
		Subsystem("ExampleSubsystem")
{
	LiftMotor = new Victor(lPort);
	IsEnabled = false;
}

void Lifter::InitDefaultCommand()
{

}

void Lifter::SetState(bool state)
{
	if(IsEnabled)
		LiftMotor->Set( state ? 1.0 : 0.0 );
}

void Lifter::Enable()
{
	IsEnabled = true;
}

void Lifter::Disable()
{
	IsEnabled = false;
	SetState(false);
}
