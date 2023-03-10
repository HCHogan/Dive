#include <stddef.h>

class Airplane {
private:
	struct AirplaneRep {
		unsigned long miles;
		char type;
	};
private:
	union {
		AirplaneRep rep;
		Airplane* next;			// embedded pointer
	};
public:
	unsigned long getMiles() {return rep.miles;}
	char getType() { return rep.type; }
	void set(unsigned long m, char t) {
		rep.miles = m;
		rep.type = t;
	}

public:
	static void* operator new(size_t size);
};
