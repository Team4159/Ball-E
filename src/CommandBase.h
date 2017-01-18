#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/Drive.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Lifter.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;
	static Drive *maindrive;
	static Shooter *shooter;
	static Lifter *toplifter;
	static Lifter *bottomlifter;
	Encoder *RightEnc = new Encoder(0, 1, false, Encoder::EncodingType::k4X); // change port for digital inputs
	Encoder *LeftEnc = new Encoder(0, 1, false, Encoder::EncodingType::k4X); // change port for digital inputs
};

#endif
