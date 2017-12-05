#include <iostream>

#include "time.h"

time::time()
{
	sec = 0;
	min = 0;
}

time::time(int seconds)
{
	sec = seconds;
	min = 0;

	roundValues();
}

time::time(int seconds, int minutes)
{
	sec = seconds;
	min = minutes;
	roundValues();
}

void time::roundValues()
{
	if(sec < 0)	//If we have a negative value for seconds, convert minutes to seconds and add it
	{
		sec += min * 60;
		min = 0;

		if(sec < 0)	//If the net time is negative, we know that the value as a whole is negative.  Therefore, set the negative flag, and make sec & min positive
		{
			sec *= -1;
			neg = true;
		}

	}

	if(sec >= 60)		//Convert any value of sec into as many minutes as possible
	{
		min += sec / 60;
		sec = sec % 60;
	}
	
}

time time::operator+(time & other)
{
	return time(getTotal() + other.getTotal());
}

void time::operator+=(time & other)
{
	*this = getTotal() + other.getTotal();
}

time time::operator-(time & other)
{
	return time(getTotal() - other.getTotal());
}

void time::operator-=(time & other)
{
	*this = getTotal() - other.getTotal();
}

time time::operator*(time & other)
{
	time(getTotal() * other.getTotal());
}

time time::operator*(int & other)
{
	time(getTotal() * other);
}

void time::operator*=(time & other)
{
	*this = *this * other;
}

void time::operator*=(int & other)
{
	*this = *this * other;
}

time time::operator/(time & other)
{
	return time(getTotal() / other.getTotal());
}

time time::operator/(int & other)
{
	return time(getTotal() / other);
}

void time::operator/=(time & other)
{
	*this = *this / other;
}

void time::operator/=(int & other)
{
	*this = *this / other;
}

bool time::operator==(time & other)
{
	return getTotal() == other.getTotal();
}

bool time::operator<(time & other)
{
	return getTotal() < other.getTotal();
}

bool time::operator<=(time & other)
{
	return getTotal() <= other.getTotal();
}

bool time::operator>(time & other)
{
	return getTotal() > other.getTotal();
}

bool time::operator>=(time & other)
{
	return getTotal() >= other.getTotal();
}

void const time::print()
{
	std::cout << "min: " << min << " sec: " << sec << std::endl;
}