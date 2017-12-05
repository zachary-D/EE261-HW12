#pragma once

class time
{
public:
	time();
	time(int seconds);
	time(int seconds, int minutes);

private:
	int min = 0;
	int sec = 0;
	bool neg = false;	//If the value is negated

public:
	void roundValues();	//Validates that sec < 60, converts to minutes as needed

	//NOTE: getMin() and getSec() do NOT include the negative, if the value is negative
	int const getMin() { return min; }
	int const getSec() { return sec; }
	int const getTotal() { return (neg == true? -1 : 1) * (min * 60 + sec); }

	time operator+(time & other);
	void operator+=(time & other);
	time operator-(time & other);
	void operator-=(time & other);

	time operator*(time & other);
	time operator*(int & other);
	void operator*=(time & other);
	void operator*=(int & other);
	time operator/(time & other);
	time operator/(int & other);
	void operator/=(time & other);
	void operator/=(int & other);

	bool operator<(time & other);
	bool operator<=(time & other);
	bool operator>(time & other);
	bool operator>=(time & other);

	void const print();
};