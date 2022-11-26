#pragma once
#include"passenger.h"
#include "info.h"
class Bus
{
public:
	Bus();
	~Bus();
	bool empty(int n_psngr = 1); // checks if bus is empty
	void add(passenger p); //adds passengers to bus
	bool avilable(Time t); // checks if bus is avilable for rides at given time

private:
	classes b_class;// buss class
	int capacity; // bus capacity
	Time maintenance; // next checkup time
	int speed; // in KM/hr
	Time DI; // time to get back to company
	passenger* psngrs; // list of passengers
	int count; // number of passengers riding the bus
};

