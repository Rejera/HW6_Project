#include <iostream>
#include "Wire.h"
#include "Gate.h"
#include "Enumerations.h"
#include "Event.h"
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <functional>

using namespace std;

int main() {
	map<char, int> convert;
	for (int i = 0;i < 26;i++) {
		char letter = 'A';
		convert[letter] = i + 1;
		letter++;
	}
	string file, circFile, vecFile,object,wireName,sDelay;
	ifstream Circuit, Vector;
	vector<Gate*> gates;
	vector<Wire*> wires;
	int wireNumber, inW1,inW2,outW,iDelay,time,count,wirVal;
	WireState vecWirVal;
	vector <string> gate{ "NOT","AND","OR","XOR","NAND","NOR","XNOR" };
	char c;
	count = 0;
	priority_queue <Event, vector<Event>, greater<Event>> eq;
	Event current;

	cout << "Please input the name of the circuit you want to simulate:" << endl;
	cin >> file;
	circFile = file + ".txt";
	vecFile = file + "_v.txt";
	Circuit.open(circFile);
	Vector.open(vecFile);
	while (Circuit.fail() == true && Vector.fail() == true) {
		cout << "The file name that you entered is incorrect. Please enter another, or type 'quit' to exit the program.";
		cin >> file;
		if (file == "quit") {
			return 1;
		}
		circFile = file + ".txt";
		vecFile = file + "_v.txt";
		Circuit.open(circFile);
		Vector.open(vecFile);
	}
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
		cin >> object;
		if (object == "INPUT") {
			cin >> c;
			cin >> time;
			cin >> wirVal;
			if (wirVal == 1) {
				vecWirVal = high;
			}
			else if (wirVal == 0) {
				vecWirVal = low;
			}
			eq.emplace(new Event{ time,convert[c],vecWirVal, count });
			count++;
		}
	}

	while (!eq.empty() && current.getTime<60) {
		current = eq.pop;
		wires[current.getWireNumber].setState(current.getWireState);

		for (int i = 0; i < gates.size(); i++) {
			if (gates[i]->inChanged) {
				eq.emplace(gates[i]->doLogic(current.getTime, count));
				count++;
			}
		}
	}
}