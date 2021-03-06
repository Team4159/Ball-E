#include "CommandBase.h"
#include "Commands/Scheduler.h"

#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
Drive* CommandBase::maindrive = NULL;
Shooter* CommandBase::shooter = NULL;
Lifter* CommandBase::toplifter = NULL;
Lifter* CommandBase::bottomlifter = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	oi = new OI();
	maindrive = new Drive();
	shooter = new Shooter();
	toplifter = new Lifter(LIFTER_TOP_PORT, false);
	bottomlifter = new Lifter(LIFTER_BOTTOM_PORT, true);
}
