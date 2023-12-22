#include "main.h"

void disrupt_autonomous(){
    blocker.set_value(true);
	intake=127;
	chassis.moveToPose(-30, -40, 90, 3000, false, 0, 0.4, 127, true);
	intake=-127;
	chassis.moveToPoint(0, -40, 3000, false);
}
