#pragma once
#include "info.h"
class Time
{
public:
	Time(Day d= Sat, int h=0, int m=0);
	~Time();
	Time remaining(Time event, Time now);
private:
	int hour, minute;
	int time();
	Day day;
};



inline Time::Time(Day d, int h, int m)
{
	day = d;
	hour = h;
	minute = m;
}

Time::~Time()
{
}

inline Time Time::remaining(Time event, Time now)
{
	int remaining = event.time() - now.time();
	int d = ((remaining / 60 / 24)%7);
	remaining -= (d * 60 * 24);
	int h = remaining / 60;
	remaining -= (h * 60);
	Time left(d, h,remaining);
}

inline int Time::time()
{
	int time = (day * 24 + hour)*60 + minute;
	return time;
}
