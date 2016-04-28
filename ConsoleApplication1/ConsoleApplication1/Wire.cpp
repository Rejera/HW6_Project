#include "Wire.h"
#include "Gate.h"


WireState Wire::getState() {
	return state;
}
void Wire::setState(WireState a) {
	state = a;
}
void Wire::addGate(Gate* a) {
	output.push_back(a);
}
Wire::Wire(string a, int b) {
	wireName = a;
	wireNum = b;
	state = undefined;
}