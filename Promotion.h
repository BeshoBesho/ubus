#pragma once
#include "Event.h"
using namespace std;
#include <string>


class promotion : public event
{
private:
	Time ED;
	float ExtraMoney;
	int ID;
public:
	promotion(Time X1,float X2,int X3);
	void execute();
};
