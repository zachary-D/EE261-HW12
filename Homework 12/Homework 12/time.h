#pragma once

#include <string>
#include <time.h>	//C++'s pre-baked time header, included here for time_t support

namespace util
{
	std::string toString(int value);
}

class ztime	//Named ztime instead of time to avoid naming conflicts
{
public:
	ztime();
	ztime(int seconds);
	ztime(int seconds, int minutes);
	ztime(time_t _time);

	static ztime now();		//A psudo-constructor that creates an element containing the current time, capped at an hour

private:
	int min = 0;
	int sec = 0;
	bool neg = false;	//If the value is negated

public:
	void roundValues();	//Validates that sec < 60, converts to minutes as needed

	int const getMin() { return min * (neg ? -1: 1); }
	int const getSec() { return sec * (neg ? -1: 1); }
	int const getTotal() { return (neg == true ? -1 : 1) * (min * 60 + sec); }

	ztime operator+(ztime & other);
	void operator+=(ztime & other);
	ztime operator-(ztime & other);
	void operator-=(ztime & other);

	ztime operator*(ztime & other);
	ztime operator*(int & other);
	void operator*=(ztime & other);
	void operator*=(int & other);
	ztime operator/(ztime & other);
	ztime operator/(int & other);
	void operator/=(ztime & other);
	void operator/=(int & other);

	bool operator==(ztime & other);
	bool operator<(ztime & other);
	bool operator<=(ztime & other);
	bool operator>(ztime & other);
	bool operator>=(ztime & other);

	std::string const toString();
	void const print();
};