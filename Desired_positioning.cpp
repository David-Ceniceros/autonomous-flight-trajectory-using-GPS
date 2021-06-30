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
		Monitor.println("forward");
	}
	if (timer > 30 && timer < 45) // stops for 1.5 secs
	{
		Monitor.println("stop");
	}
	if (timer > 46 && timer < 76) // backwards for 3 secs
	{
		Monitor.println("backward");
	}
	if (timer > 77 && timer < 92) // stops for 1.5 secs
	{
		Monitor.println("stop again");
	}
	if (timer > 93 && timer < 123) // forward again for 3 secs
	{
		Monitor.println("forward again");
	}
	if (timer > 123) // land drone
	{
		Monitor.println("land drone");
	}

}

void onLoopFinish()
{
}
