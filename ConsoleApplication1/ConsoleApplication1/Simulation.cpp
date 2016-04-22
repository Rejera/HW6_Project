#include <iostream>
#include "Wire.h"
#include "Gate.h"
#include "Enumerations.h"
#include "Event.h"
#include <fstream>
#include <string>

using namespace std;

int main() {
	string file, circFile, vecFile,object;
	ifstream Circuit, Vector;
	vector <string> gate{ "NOT","AND","OR","XOR","NAND","NOR","XNOR" };
	cout << "Please input the name of the circuit you want to simulate:" << endl;
	cin >> file;
	circFile = file + ".txt";
	vecFile = file + "_v.txt";
	Circuit.open(circFile);
	Vector.open(vecFile);
	
	while (!Circuit.eof()) {
		Circuit >> object;
		if (object == "input") {

		}
		if (object == "output") {

		}
	}

	for (int i = 0; i < 7;i++) {
		if (object == gate[i]) {

		}
	}


}