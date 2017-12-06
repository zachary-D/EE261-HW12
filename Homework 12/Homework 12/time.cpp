#include <iostream>
#include <sstream>
#include <string>

#include "time.h"

namespace util
{
	std::string toString(int value)
	{
		std::string output;
		std::stringstream convert;
		convert << value;
		convert >> output;

		return output;
	}
};

ztime::ztime()
{
	sec = 0;
	min = 0;
}

ztime::ztime(int seconds)
{
	sec = seconds;
	min = 0;

	roundValues();
}

ztime::ztime(int seconds, int minutes)
{
	sec = seconds;
	min = minutes;
	roundValues();
}

ztime::ztime(time_t _time)		//Note, this constructor rounds down to the nearest hour, therefore any data stored in hours or larger units is discarded
{
	sec = _time % 60;
	min = (_time / 60) % 60;
}

ztime ztime::now()
{
	return ztime(time(0));
}

void ztime::roundValues()
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

ztime ztime::operator+(ztime & other)
{
	return ztime(getTotal() + other.getTotal());
}

void ztime::operator+=(ztime & other)
{
	*this = getTotal() + other.getTotal();
}

ztime ztime::operator-(ztime & other)
{
	return ztime(getTotal() - other.getTotal());
}

void ztime::operator-=(ztime & other)
{
	*this = getTotal() - other.getTotal();
}

ztime ztime::operator*(ztime & other)
{
	return ztime(getTotal() * other.getTotal());
}

ztime ztime::operator*(int & other)
{
	return ztime(getTotal() * other);
}

void ztime::operator*=(ztime & other)
{
	*this = *this * other;
}

void ztime::operator*=(int & other)
{
	*this = *this * other;
}

ztime ztime::operator/(ztime & other)
{
	return ztime(getTotal() / other.getTotal());
}

ztime ztime::operator/(int & other)
{
	return ztime(getTotal() / other);
}

void ztime::operator/=(ztime & other)
{
	*this = *this / other;
}

void ztime::operator/=(int & other)
{
	*this = *this / other;
}

bool ztime::operator==(ztime & other)
{
	return getTotal() == other.getTotal();
}

bool ztime::operator<(ztime & other)
{
	return getTotal() < other.getTotal();
}

bool ztime::operator<=(ztime & other)
{
	return getTotal() <= other.getTotal();
}

bool ztime::operator>(ztime & other)
{
	return getTotal() > other.getTotal();
}

bool ztime::operator>=(ztime & other)
{
	return getTotal() >= other.getTotal();
}

std::string const ztime::toString()
{
	return util::toString(min) + " minutes and " + util::toString(sec) + " seconds";
}

void const ztime::print()
{
	std::cout << toString() << std::endl;
}