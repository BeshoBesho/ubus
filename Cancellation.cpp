#include "Cancellation.h"

cancellation::cancellation(Time X1, int X2)
{
	ED = X1;
	ID = X2;
}
void cancellation::execute()
{
	if (p != nullptr)
		delete p;
}