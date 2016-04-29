#include "Wire.h"
#include "Gate.h"


WireState Wire::getState() {
	return state;
}
void Wire::setState(WireState a) {
	state = a;
}
int Wire::getWireNum() {
	return wireNum;
}
Wire::Wire(string a, int b) {
	wireName = a;
	wireNum = b;
	state = undefined;
}