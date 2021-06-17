// Do not remove the include below
#include "PlutoPilot.h"
#include "Control.h"
#include "User.h"

int32_t initial_x_Axis;
int32_t initial_y_Axis;
int32_t moving_x_Axis;
int32_t moving_y_Axis;
int32_t future_x_Axis = 10; //place holder
int32_t future_y_Axis = 10; //place holder

void plutoInit()
{

}

void onLoopStart()
{
	//obtains current position
	initial_x_Axis = DesiredPosition.get(X);
	initial_y_Axis = DesiredPosition.get(Y);

	//sets current positions to zero
	DesiredPosition.set(X,0);
	DesiredPosition.set(Y,0);

}

void plutoLoop()
{
	// allows the drone to autonomously fly toward first position
	if (initial_x_Axis <= 0 && initial_y_Axis <= 0) {
		initial_y_Axis = moving_y_Axis;
		moving_y_Axis++;
		RcCommand.set(RC_PITCH, 1400);
	}

	// when drone gets to first position, it stops
	if (moving_y_Axis = future_y_Axis) {
		RcCommand.set(RC_PITCH, 1500);
	}

	// allows the drone to autonomously fly toward second position
	if (initial_x_Axis <= 0 && moving_y_Axis >= 10) {
		initial_x_Axis = moving_x_Axis;
		moving_x_Axis++;
		RcCommand.set(RC_ROLL, 1400);
	}

	// when drone gets to second position, it stops
	if (moving_x_Axis = future_x_Axis) {
		RcCommand.set(RC_ROLL, 1500);
	}

	// allows the drone to autonomously fly toward third position
	if (moving_x_Axis >= 10 && moving_y_Axis >= 10) {
		moving_y_Axis--;
		RcCommand.set(RC_PITCH, 1600);
	}

	// when drone gets to third position, it stops
	if (moving_y_Axis = initial_y_Axis) {
		RcCommand.set(RC_PITCH, 1500);
	}

	// allows the drone to autonomously fly toward initial position
	if (initial_x_Axis >= 10 && initial_y_Axis <= 0) {
		moving_y_Axis--;
		RcCommand.set(RC_ROLL, 1600);
	}

	// when drone gets to initial position, it stops
	if (moving_x_Axis = initial_x_Axis) {
		RcCommand.set(RC_ROLL, 1500);
	}
}

void onLoopFinish()
{

}
