#pragma once
#include "Event.h"
using namespace std;
#include <string>



class ready : public event
{
private:
	classes	TYP;
	Time ET;
	int DIST;
	Time LT;
	float COST;
	int ID;

public:
	ready(classes X1,Time X2,int X3,Time X4,float X5,int X6);
	void execute();
};