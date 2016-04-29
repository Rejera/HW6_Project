#include "Enumerations.h"
#include <vector>
using namespace std;
class Gate;

#ifndef WIRE_H
#define WIRE_H

class Wire {
public:
	Wire(string a, int b);
	WireState	getState();
	void setState(WireState a);

	int getWireNum();

private:
	string wireName;
	int wireNum;
	WireState state;
	
};
#endif