// Do not remove the include below
#include "PlutoPilot.h"
#include "Peripheral.h"
#include "User.h"

void plutoInit()
{
	GPIO.init(Pin19, OUTPUT);
	setUserLoopFrequency(2000);
}

void onLoopStart()
{
}

void plutoLoop()
{
	GPIO.write(Pin19, STATE_TOGGLE);
}

void onLoopFinish()
{
}

