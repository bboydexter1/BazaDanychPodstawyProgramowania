#pragma once
#include <string>


using namespace std;

class people
{
public:
	int id;
	std::string name;
	std::string surname;
	int age;
	std::string dateOfBirth;
	long int tNumber;
	bool isMale;
	std::string nationality;

public:
	people(int _id, string _name, string _surname, int _age, string _dateOfBirth, long int _tNumber, int gender, string _nationality);
	people();
	~people();
};

