#include "Event.h"
event::event() 
{

}

classes stoclasses(string x)
{
	if (x == "N")
		return Economy;
	else if (x == "S")
		return Business;
	else if (x == "V")
		return VIP;
}

Time stotime(string x)
{
	string h, m;
	int n;
	for (int i = 0; i < x.length(); i++)
	{
		if (x[i] != ':')
		{
			h += x[i];
		}
		else
		{
			n = x.length() - i;
			break;
		}
	}
	for (int i = n; i = x.length(); i++)
	{
		m += x[i];
	}
	Time t(1, stoi(h), stoi(m));
	return t;
}
