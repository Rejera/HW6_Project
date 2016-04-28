#include "Event.h"

using namespace std;

Event::Event(int t, int wN, WireState s, int c) {
	time = t;
	wireN = wN;
	state = s;
	count = c;
}

int Event::getWireNumber() {
	return wireN;
}

WireState Event::getWireState() {
	return state;
}

bool Event::operator<(const Event e) const {
	if (time < e.time) {
		return true;
	}
	else if (time == e.time && count < e.count) {
		return true;
	}
	else return false;
}