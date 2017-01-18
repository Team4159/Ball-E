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

	// jank
	Encoder *RightEnc = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
	Encoder *LeftEnc = new Encoder(2, 3, false, Encoder::EncodingType::k4X);

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

		// get encoder values
		int leftCount = LeftEnc->Get();
		double leftDistance = LeftEnc->GetDistance();
		double leftPeriod = LeftEnc->GetPeriod();
		double leftRate = LeftEnc->GetRate();
		bool leftDirection = LeftEnc->GetDirection();
		bool leftStopped = LeftEnc->GetStopped();

		int rightCount = RightEnc->Get();
		double rightDistance = RightEnc->GetDistance();
		double rightPeriod = RightEnc->GetPeriod();
		double rightRate = RightEnc->GetRate();
		bool rightDirection = RightEnc->GetDirection();
		bool rightStopped = RightEnc->GetStopped();

		// print encoder values to smart dashboard
		SmartDashboard::PutNumber("Left Count", leftCount);
		SmartDashboard::PutNumber("Left Distance", leftDistance);
		SmartDashboard::PutNumber("Left Period", leftPeriod);
		SmartDashboard::PutNumber("Left Rate", leftRate);
		SmartDashboard::PutNumber("Left Direction", leftDirection);
		SmartDashboard::PutNumber("Left Stopped", leftStopped);

		SmartDashboard::PutNumber("Right Count", rightCount);
		SmartDashboard::PutNumber("Right Distance", rightDistance);
		SmartDashboard::PutNumber("Right Period", rightPeriod);
		SmartDashboard::PutNumber("Right Rate", rightRate);
		SmartDashboard::PutNumber("Right Direction", rightDirection);
		SmartDashboard::PutNumber("Right Stopped", rightStopped);


		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
