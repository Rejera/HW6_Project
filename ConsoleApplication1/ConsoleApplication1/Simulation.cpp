#include <iostream>
#include "Wire.h"
#include "Gate.h"
#include "Enumerations.h"
#include "Event.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
	string file, circFile, vecFile,object,wireName,sDelay;
	ifstream Circuit, Vector;
	vector<Gate*> gates;
	vector<Wire*> wires;
	int wireNumber, inW1,inW2,outW,iDelay;
	vector <string> gate{ "NOT","AND","OR","XOR","NAND","NOR","XNOR" };
	cout << "Please input the name of the circuit you want to simulate:" << endl;
	cin >> file;
	circFile = file + ".txt";
	vecFile = file + "_v.txt";
	Circuit.open(circFile);
	Vector.open(vecFile);
	
	while (!Circuit.eof()) {
		Circuit >> object;
		if (object == "INPUT" || object == "OUTPUT") {
			Circuit >> wireName;
			Circuit >> wireNumber;
			if (wires.size < wireNumber) {}
			while (wires.size < wireNumber) {
				wires.push_back(nullptr);
			}
			wires.push_back(new Wire{ wireName, wireNumber });
		}
		if (wires.size > wireNumber) {
			wires[wireNumber] = new Wire{ wireName, wireNumber };
		}
		for (int i = 0; i < 7;i++) {
			if (object == gate[i]) {
				if (object != "NOT") {
					Circuit >> sDelay;
					Circuit >> inW1;
					Circuit >> inW2;
					Circuit >> outW;
					iDelay = (int)sDelay[0];
					gates.push_back(new Gate{ wires[inW1],wires[inW2],wires[outW],iDelay,object });
				}
				if (object == "NOT") {
					Circuit >> sDelay;
					Circuit >> inW1;
					Circuit >> outW;
					iDelay = (int)sDelay[0];
					gates.push_back(new Gate{ wires[inW1],wires[outW],iDelay,object });
				}
			}
		}
	}
	while (!Vector.eof()) {

	}

}