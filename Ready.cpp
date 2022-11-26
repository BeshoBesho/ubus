#include "Ready.h"

ready::ready(classes X1, Time X2, int X3, Time X4, float X5, int X6)
{
	TYP=X1;
	ET=X2;
	DIST=X3;
	LT=X4;
	COST=X5;
	ID=X6;
}

void ready::execute()
{
	p->set_class(TYP);

}

