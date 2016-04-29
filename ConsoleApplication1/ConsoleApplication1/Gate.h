#include "Event.h"
using namespace std;
class Wire;

#ifndef GATE_H
#define GATE_H

class Gate {
public:
	Gate(Wire *a, Wire *b, Wire *c, int d, string t);
	Gate(Wire *a, Wire *b, int d, string t);
	
	Event doLogic(int time, int count);

	bool inChanged();

	private:
		Wire *in1, *in2;
		Wire *out;
		int delay;
		string type;
		WireState input1, input2;
};
#endif