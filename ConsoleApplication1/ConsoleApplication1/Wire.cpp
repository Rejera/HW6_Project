#include "Wire.h"
#include "Gate.h"

Wire::Wire(vector <Gate*> a) {
	output = a;
}
int Wire::getState() {
	return state;
}
void Wire::setState(WireState a) {
	state = a;
}