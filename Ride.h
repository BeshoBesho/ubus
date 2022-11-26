#pragma once
#include "Event.h"
#include "passenger.h"
class Ride :public event
{
public:
	Ride();
	~Ride();
	void execute();
private:
	passenger* p;
};

