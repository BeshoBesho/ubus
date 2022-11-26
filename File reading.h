#pragma once
#include "passenger.h"
#include "Ready.h"
#include "Promotion.h"
#include "Cancellation.h"
#include <iostream>
using namespace std;
#include <string>
#include <fstream>

void reading (string n)
{
	int noevents;
	string x;
	string Name =n+".txt";
	ifstream Infile;
	Infile.open(Name);
	if (Infile.is_open())
	{
		cout << "File has been opened";
		for (int i = 0; i < 8; i++)
		{
			Infile >> x;
			if (x == "R")
			{
				string x1, x2, x3, x4, x5, x6;
				Infile >> x1 >> x2 >> x3 >> x4 >> x5 >> x6;
				ready r(stoclasses(x1), stotime(x2), stoi(x3), stotime(x4), stof(x5), stoi(x6));
			}
			else if (x=="X")
			{
				string x1, x2;
				Infile >> x1 >> x2;
				cancellation r(stotime(x1), stoi(x2)); 
			}
			else if (x == "P")
			{
				string x1, x2, x3;
				Infile >> x1 >> x2>>x3;
				promotion r(stotime(x1), stof(x2), stoi(x3)); 
			}

		}
	}
	else
		cout<<"No file with this name";

};
