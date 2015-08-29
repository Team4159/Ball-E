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
		bool topLifterUp = CommandBase::oi->GetJoystick(JOYSTICK_TOP_LIFTER_PORT)->GetRawButton(JOYSTICK_TOP_LIFTER_BUTTON_UP);
		bool topLifterDown = CommandBase::oi->GetJoystick(JOYSTICK_TOP_LIFTER_PORT)->GetRawButton(JOYSTICK_TOP_LIFTER_BUTTON_DOWN);
		bool bottomLifterUp = CommandBase::oi->GetJoystick(JOYSTICK_BOTTOM_LIFTER_PORT)->GetRawButton(JOYSTICK_BOTTOM_LIFTER_BUTTON_UP);
		bool bottomLifterDown = CommandBase::oi->GetJoystick(JOYSTICK_BOTTOM_LIFTER_PORT)->GetRawButton(JOYSTICK_BOTTOM_LIFTER_BUTTON_DOWN);

		CommandBase::maindrive->FromJoystickInput(CommandBase::oi->GetLeftJoystick()->GetAxis(Joystick::AxisType::kYAxis), CommandBase::oi->GetRightJoystick()->GetAxis(Joystick::AxisType::kYAxis));
		CommandBase::shooter->SetState(CommandBase::oi->GetJoystick(JOYSTICK_SHOOTER_PORT)->GetRawButton(JOYSTICK_SHOOTER_BUTTON));
		if(topLifterUp && !topLifterDown)
			CommandBase::toplifter->SetState(Lifter::State::UP);
		else if(topLifterDown && !topLifterUp)
			CommandBase::toplifter->SetState(Lifter::State::DOWN);
		else
			CommandBase::toplifter->SetState(Lifter::State::OFF);

		if(bottomLifterUp && !bottomLifterDown)
			CommandBase::bottomlifter->SetState(Lifter::State::UP);
		else if(bottomLifterDown && !bottomLifterUp)
			CommandBase::bottomlifter->SetState(Lifter::State::DOWN);
		else
			CommandBase::bottomlifter->SetState(Lifter::State::OFF);

		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

