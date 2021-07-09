// this is to program drone to autonomously fly a trajectory in the shape of a square
// Created by: David Ceniceros
// Updated July 8th, 2021

#include "PlutoPilot.h"
#include "Utils.h"
#include "User.h"

int timer = 0;

void plutoInit()
{
}

void onLoopStart()
{
}

void plutoLoop()
{
	timer++; // 10 = 1 seconds

	if (timer < 30) // forward for 3 secs
	{
		RcCommand.set(RC_PITCH, 1550);
		//Monitor.println("forward");
	}
	if (timer > 30 && timer < 45) // stops for 1.5 secs
	{
		RcCommand.set(RC_PITCH, 1500);
		//Monitor.println("stop");
	}
	if (timer > 46 && timer < 76) // left for 3 secs
	{
		RcCommand.set(RC_ROLL, 1450);
		//Monitor.println("left");
	}
	if (timer > 77 && timer < 92) // stops for 1.5 secs
	{
		RcCommand.set(RC_ROLL, 1500);
		//Monitor.println("stop");
	}
	if (timer > 93 && timer < 123) // backward for 3 secs
	{
		RcCommand.set(RC_PITCH, 1450);
		//Monitor.println("backwards");
	}
	if (timer > 123 && timer <138) // stops for 1.5 secs
	{
		RcCommand.set(RC_PITCH, 1500);
		//Monitor.println("stop");
	}
	if (timer > 138 && timer < 168) // right for 3 secs
	{
		RcCommand.set(RC_ROLL, 1550);
		//Monitor.println("right");
	}
	if (timer > 168 && timer < 178) // final stop for 1.5 secs
	{
		RcCommand.set(RC_ROLL, 1500);
		//Monitor.println("final stop");
	}
	if (timer > 178) // land drone
	{
		Command.land(105);
		//Monitor.println("land drone");
	}

}

void onLoopFinish()
{
}

