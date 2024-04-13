#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int hours, minutes, seconds;
	void trueTime();

public:
	const int DEF_T = 0;
	const int MIN_T = 0;
	const int MAX_H = 24;
	const int MAX_M = 60;
	Time();
	Time(int hours, int minutes, int seconds);
	int fullMinutes();
	void minusMinutes();
	int getHours();
	int getMinutes();
	int getSeconds();
	void setHours(int h);
	void setMinutes(int m);
	void setSeconds(int s);
};

#endif // !TIME_H

#include "time.h"
#include <iostream>
#include <ostream>
#include <iomanip>

using namespace std;

Time::Time()
{
	this->hours = DEF_T;
	this->minutes = DEF_T;
	this->seconds = DEF_T;

	trueTime();
}

Time::Time(int hours, int minutes, int seconds)
	: hours(hours), minutes(minutes), seconds(seconds)
{
	trueTime();
}

void Time::trueTime()
{
	int sum = seconds + minutes * MAX_M + hours * int(pow(MAX_M, 2));
	if (sum < 0)
	{
		sum += int(pow(MAX_M, 2) * MAX_H);
	}
	seconds = sum % MAX_M;
	sum = sum / MAX_M;
	minutes = sum % MAX_M;
	sum = sum / MAX_M;
	hours = sum % MAX_H;
}

int Time::fullMinutes()
{
	return minutes + hours * 60;
}

void Time::minusMinutes()
{
	minutes -= 10;
	trueTime();
}

int Time::getHours()
{
	return this->hours;
}
int Time::getMinutes()
{
	return this->minutes;
}
int Time::getSeconds()
{
	return this->seconds;
}
void Time::setHours(int h)
{
	this->hours = h;
	trueTime();
}
void Time::setMinutes(int m)
{
	this->minutes = m;
	trueTime();
}
void Time::setSeconds(int s)
{
	this->seconds = s;
	trueTime();
}

ostream& operator<<(ostream& os, Time& obj)
{
	os << setfill('0') << setw(2) << obj.getHours() << ":"
		<< setw(2) << obj.getMinutes() << ":"
		<< setw(2) << obj.getSeconds() << endl;
	return os;
}

istream& operator>>(istream& is, Time& obj)
{
	int h, m, s;
	is >> h >> m >> s;
	obj.setHours(h);
	obj.setMinutes(m);
	obj.setSeconds(s);
	return is;
}

int main()
{
	Time* t1 = new Time();
	Time* t2 = new Time(25, 1, 70);
	Time* t3 = new Time(-10, -50, 70);
	Time* t4 = new Time();

	cin >> *t4;
	cout << *t1;
	cout << *t2;
	cout << *t3;
	cout << *t4;

	delete t1;
	delete t2;
	delete t3;
	delete t4;
}