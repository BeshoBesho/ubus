#pragma once
#include "passenger.h"
#include <string>
using namespace std;
class event
{
private:

public:
	passenger* p;
	event();
	~event();
	void virtual execute() = 0;
};
