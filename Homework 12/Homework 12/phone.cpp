#include "phone.h"

phone::phone()
{
	countryCode = 0;
	areaCode = 0;
	phoneNumber = 0;
	phoneType = home;
}

phone::phone(int country, int area, int number)
{
	countryCode = country;
	areaCode = area;
	phoneNumber = number;
	phoneType = home;
}

phone::phone(int country, int area, int number, phoneType_type type)
{
	countryCode = country;
	areaCode = area;
	phoneNumber = number; 
	phoneType = type;
}

bool phone::operator==(phone & other)
{
	return (getCountry() == other.getCountry())
		&& (getArea() == other.getArea())
		&& (getNumber() == other.getNumber())
		&& (getType() == other.getType());
}

bool phone::operator!=(phone & other)
{
	return (getCountry() != other.getCountry())
		|| (getArea() != other.getArea())
		|| (getNumber() != other.getNumber())
		|| (getType() != other.getType());
}

std::string const phone::toString()
{
	std::string type;
	switch(phoneType)
	{
		case home:
			type = "home";
			break;

		case office:
			type = "office";
			break;

		case fax:
			type = "fax";
			break;

		case cell:
			type = "cell";
			break;

		case pager:
			type = "pager";
			break;
	}
	return "+" + util::toString(countryCode) + " (" + util::toString(areaCode) + ") " + util::toString(phoneNumber) + " (" + type + ")";
	
}