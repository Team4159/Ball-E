#ifndef Shooter_H
#define Shooter_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "RobotMap.h"

class Shooter: public Subsystem
{
private:
	bool IsEnabled;

	Victor *ShooterMotorA = new Victor(SHOOTER_PORT_A);
	Victor *ShooterMotorB = new Victor(SHOOTER_PORT_B);
	Victor *ShooterMotorC = new Victor(SHOOTER_PORT_C);
	Victor *ShooterMotorD = new Victor(SHOOTER_PORT_D);

public:
	Shooter();
	void InitDefaultCommand();
	void SetState(bool state);
	void Enable();
	void Disable();
};

#endif
