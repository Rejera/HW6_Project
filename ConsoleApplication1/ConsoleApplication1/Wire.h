#include "Enumerations.h"
#include <vector>
using namespace std;
class Gate;

#ifndef WIRE_H
#define WIRE_H

class Wire {
public:
	Wire(string a, int b);
	int	getState();
	void addGate(Gate* a);
	void setState(WireState a);

private:
	string wireName;
	int wireNum;
	WireState state;
	vector <Gate*> output;
	bool wChanged;
	
};
#endif