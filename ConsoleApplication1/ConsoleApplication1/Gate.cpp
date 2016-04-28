#include "Gate.h"
#include "Wire.h"
using namespace std;

Gate::Gate(Wire *a, Wire *b, Wire *c, int d, string t) {
		in1 = a;
		in2 = b;
		out = c;
		delay = d;
		type = t;
}

Gate::Gate(Wire *a, Wire *b, int d, string t) {
	in1 = a;
	in2 = b;
	out = nullptr;
	delay = d;
	type = t;
}

int Gate::doLogic() {
	//Logic will go here depending on what gate type
	if (type == "OR") {
		if (in1->getState() ==high || in2->getState==high) {
			out->setState(high);

		}
		else if (in1->getState() == low && in2->getState == low) {
			out->setState(low);
		}
		else if (in1->getState() == undefined || in2->getState() == undefined) {
			out->setState(undefined);
		}
	}
	if (type == "AND") {
		if (in1->getState() == low || in2->getState() == low) {
			out->setState(low);
		}
		else if (in1->getState() == high && in2->getState() == high) {
			out->setState(high);
		}
		else if (in1->getState() == undefined || in2->getState() == undefined) {
			out->setState(undefined);
		}
	}
	if (type == "NOT") {
		if (in1->getState() == high) {
			out->setState(low);
		}
		else if (in1->getState() == low) {
			out->setState(high);
		}
		else if (in1->getState() == undefined) {
			out->setState(undefined);
		}
	}
}