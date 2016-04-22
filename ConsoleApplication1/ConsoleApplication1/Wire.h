#include "Enumerations.h"
#include <vector>
using namespace std;
class Gate;

class Wire {
public:
	Wire(vector <Gate*> a);
	int	getState();
	void setGate(Gate* a);
	void setState(WireState a);

private:
	WireState state;
	vector <Gate*> output;
	bool wChanged;
	
};
