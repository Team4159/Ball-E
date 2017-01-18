#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() :
		Subsystem("Shooter")
{
	IsEnabled = false;
}

void Shooter::InitDefaultCommand()
{

}

void Shooter::SetState(bool state)
{
	if(IsEnabled)
	{
		ShooterMotorA->Set( state ? 1.0 : 0.0 );
		ShooterMotorB->Set( state ? 1.0 : 0.0 );
		ShooterMotorC->Set( state ? 1.0 : 0.0 );
		ShooterMotorD->Set( state ? 1.0 : 0.0 );
	}
}

void Shooter::Enable()
{
	IsEnabled = true;
}

void Shooter::Disable()
{
	IsEnabled = false;
	SetState(false);
}
