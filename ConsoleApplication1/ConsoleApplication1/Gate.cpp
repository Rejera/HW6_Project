#include "Gate.h"
#include "Wire.h"
using namespace std;

Gate::Gate(Wire *a, Wire *b, Wire *c, int d, string t) {
		in1 = a;
		in2 = b;
		out = c;
		delay = d;
		type = t;
		input1 = a->getState();
		input2 = b->getState();
		inChange = false;
}

Gate::Gate(Wire *a, Wire *b, int d, string t) {
	in1 = a;
	in2 = nullptr;
	out = b;
	delay = d;
	type = t;
	input1 = a->getState();
	inChange = false;
}

Event Gate::doLogic(int t, int c) {
	//Logic will go here depending on what gate type
	if (type == "OR") {
		if (in1->getState() == high || in2->getState == high) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
		else if (in1->getState() == low && in2->getState == low) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
	}
	if (type == "AND") {
		if (in1->getState() == low || in2->getState() == low) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
		else if (in1->getState() == high && in2->getState() == high) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
	}
	if (type == "NOT") {
		if (in1->getState() == high) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
		else if (in1->getState() == low) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
	}
	if (type == "XOR") {
		if ((in1->getState() == low && in2->getState() == low) || (in1->getState() == high && in2->getState() == high)) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
		else if (in1->getState() == low && in2->getState() == high || in1->getState() == high && in2->getState() == low) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
	}
	if (type == "NAND") {
		if (in1->getState() == high && in2->getState() == high) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
		else if (in1->getState() == low || in2->getState() == low) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
	}
	if (type == "NOR") {
		if (in1->getState() == low && in2->getState() == low) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
		else if (in1->getState() == high || in2->getState() == high) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
	}
	if (type == "XNOR") {
		if ((in1->getState() == low && in2->getState() == low) || (in1->getState() == high && in2->getState() == high)) {
			if (out->getState() != high) {
				return Event{ t + delay, out->getWireNum(), high, c };
			}
		}
		else if (in1->getState() == low && in2->getState() == high || in1->getState() == high && in2->getState() == low) {
			if (out->getState() != low) {
				return Event{ t + delay, out->getWireNum(), low, c };
			}
		}
	}

	return Event{ -1, 0, undefined, 0 }; //dummy event
}

bool Gate::inChanged() {
	if (in1->getState != input1 || in2->getState != input2) {
		return true;
	}
	else return false;
}