#pragma once
#include"Time.h"
#include "info.h"
class passenger
{
public:
	passenger(classes c=Economy);
	~passenger();	
private:
	Time Ready, Ride, Getoff;
	classes p_class;// passenger class
	int Distnace;// in KM
	float cost; // in EGP
};

