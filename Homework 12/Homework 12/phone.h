#pragma once

#include <string>

#include "time.h"	//Just to take util::toString() from it

enum phoneType_type
{
	home,
	office,
	fax,
	cell,
	pager,
};

class phone
{
public:
	phone();
	phone(int country, int area, int number); 
	phone(int country, int area, int number, phoneType_type type);

private:
	int countryCode;
	int areaCode;
	int phoneNumber;
	phoneType_type phoneType;
	
public:
	int const getCountry() { return countryCode; }
	void setCountry(int code) { countryCode = code; }

	int const getArea() { return areaCode; }
	void setArea(int code) { areaCode = code; }

	int const getNumber() { return phoneNumber; }
	void setNumber(int num) { phoneNumber = num; }

	phoneType_type const getType() { return phoneType; }
	void setType(phoneType_type type) { phoneType = type; }

	bool operator==(phone & other);
	bool operator!=(phone & other);

	std::string const toString();
};