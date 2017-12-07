#include<iostream>
#include<time.h>

using std::cout;
using std::endl;

#include "time.h"
#include "phone.h"



int main()
{
	{	//Exercise 6 demonstration
		ztime now = ztime::now();

		cout << "It is currently " << now.toString() << " past the hour." << endl;

		cout << "In 10 minutes it will be " << (now + ztime(0, 10)).toString() << " past the hour." << endl;

		cout << now.toString() << " minus 1 minute and 3 seconds is " << (now - ztime(3, 10)).toString() << endl;
	}

	cout << endl;

	{	//Exercise 8 demonstration
		phone myPhone(1, 518, 8886132, cell);
		cout << "My phone number is " << myPhone.toString() << endl;

		cout << "My area code is " << myPhone.getArea() << endl;

		phone otherPhone(2, 316, 4812649, home);

		cout << "myPhone does ";
		if(myPhone != otherPhone) cout << "not ";
		cout << "equal otherPhone" << endl;
	}

	std::cin.ignore();

	return 0;
}