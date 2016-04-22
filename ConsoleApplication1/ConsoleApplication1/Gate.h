using namespace std;
class Wire;
class Gate {
	Gate();
	Gate(Wire *a, Wire *b, Wire *c, int d, string t);

	int	doLogic();


private:
	Wire *in1, *in2;
	Wire *out;
	int delay;
	string type;
};
