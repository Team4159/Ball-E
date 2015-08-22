#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Lifter.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{

		CommandBase::init();
		autonomousCommand = NULL;
		lw = LiveWindow::GetInstance();

		// Setup main robot drive with tank from OI joysticks
		CommandBase::maindrive->FromJoystickInput(CommandBase::oi->GetLeftJoystick(), CommandBase::oi->GetRightJoystick());
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

		CommandBase::maindrive->Enable();
		CommandBase::shooter->Enable();
		CommandBase::toplifter->Enable();
		CommandBase::bottomlifter->Enable();
	}

	void TeleopPeriodic()
	{
		CommandBase::shooter->SetState(CommandBase::oi->GetJoystick(JOYSTICK_SHOOTER_PORT)->GetRawButton(JOYSTICK_SHOOTER_BUTTON));
		CommandBase::toplifter->SetState(CommandBase::oi->GetJoystick(JOYSTICK_TOP_LIFTER_PORT)->GetRawButton(JOYSTICK_TOP_LIFTER_BUTTON_UP));
		CommandBase::bottomlifter->SetState(CommandBase::oi->GetJoystick(JOYSTICK_BOTTOM_LIFTER_PORT)->GetRawButton(JOYSTICK_BOTTOM_LIFTER_BUTTON_UP));

		Scheduler::GetInstance()->Run();
	}

	void TeleopEnd()
	{
		CommandBase::maindrive->Disable();
		CommandBase::shooter->Disable();
		CommandBase::toplifter->Disable();
		CommandBase::bottomlifter->Disable();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

