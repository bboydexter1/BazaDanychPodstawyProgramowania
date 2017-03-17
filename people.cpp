#include "people.h"

people::people(int _id, string _name, string _surname, int _age, string _dateOfBirth, long int _tNumber, int gender, string _nationality)
{
	id = _id;
	name = _name;
	surname = _surname;
	age = _age;
	dateOfBirth = _dateOfBirth;
	tNumber = _tNumber;
	if (gender == 1)
		isMale = true;
	else if (gender == 0)
		isMale = false;
	nationality = _nationality;
}

people::people()
{}

people::~people()
{
}
