// this is to program drone to move from one position to another
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
	timer++; // 100 = 10 seconds

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
	if (timer > 46 && timer < 76) // backwards for 3 secs
	{
		RcCommand.set(RC_PITCH, 1450);
		//Monitor.println("backward");
	}
	if (timer > 76 && timer < 91)
	{
		RcCommand.set(RC_PITCH, 1500);
		//Monitor.println("final stop");
	}
	if (timer > 91)
	{
		Command.land(105);
		//Monitor.println("land drone");
	}

}

void onLoopFinish()
{
}

