#pragma once
#include "Event.h"
using namespace std;
#include <string>


class cancellation : public event
{
private:
	Time ED;
	int ID;
public:
	cancellation(Time X1,int X2);
	void execute();
};