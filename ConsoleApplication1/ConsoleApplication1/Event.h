#include "Enumerations.h"
class Event{
	public:
		Event(int t, int wN, WireState s, int c);

		int getWireNumber();
		WireState getWireState();

		bool operator<(const Event e) const;

	private:
		int time;
		int wireN;
		WireState state;
		int count;
};
