#include "Bus.h"
Bus::Bus()
{
	passenger* p = new passenger[count];
	psngrs = p;
}

Bus::~Bus()
{
}

inline bool Bus::empty(int n_psngr)
{
	if (count == capacity) { return false; }
	else
	{
		return true;
	}
}

void Bus::add(passenger p)
{
	psngrs[count] = p;
	count += 1;
}

bool Bus::avilable(Time t)
{
	return false;
}
