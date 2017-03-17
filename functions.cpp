#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "people.h"

void addPerson(people p, fstream& database)
{
	string str = p.id + ";" + p.name + ";" + p.surname + ";" + to_string(p.age) + ";" + p.dateOfBirth + ";" + to_string(p.tNumber) + ";" + to_string(p.isMale) + ";" + p.nationality + "\n";
	if (database.is_open())
		database << str;
}

int getId()
{
	int id;
	fstream idF;
	idF.open("id.txt", ios::in | ios::out);
	if (idF.is_open())
	{
		string str;
		while (getline(idF, str))
		{
			id = stoi(str);
		}
		id++;
		idF << to_string(id);
		idF.close();
	}
	return id;
}


void makePeople(int quantity)
{
	ifstream namesFile("names.txt", ios::in);
	ifstream fNamesFile("fNames.txt", ios::in);
	ifstream surnamesFile("surnames.txt", ios::in);
	fstream outFile("outFile.txt", ios::app);

	vector<string> names;
	vector<string> fNames;
	vector<string> surnames;

	srand((unsigned int)time(NULL));
	//int iSecret = rand() % 10 + 1; pierwsza ilosc liczb od sera w ym przypadku 9 + pocz¹tkowa liczba

	if (fNamesFile.is_open())
	{
		string str;
		while (getline(fNamesFile, str))
		{
			fNames.push_back(str);
		}
		fNamesFile.close();
	}

	if (namesFile.is_open())
	{
		string str;
		while (getline(namesFile, str))
		{
			names.push_back(str);
		}
		namesFile.close();
	}

	if (surnamesFile.is_open())
	{
		string str;
		while (getline(surnamesFile, str))
		{
			surnames.push_back(str);
		}
		surnamesFile.close();
	}

	for (int i = 1; i <= quantity; i++)
	{
		int j = rand() % 40 + 13;
		int g = rand() % 2;
		string name;
		if (g == 1)
			name = names[rand() % 40];
		else
			name = fNames[rand() % 35];
		addPerson(people::people
		(
			getId()
			, name,
			surnames[rand() % 20],
			j,
			to_string(rand() % 29 + 1) + "-" + to_string(rand() % 12 + 1) + "-" + to_string(2017 - j),
			rand() % 899999999 + 100000000,
			g,
			"Polska"
		)
			, outFile);
	}
	outFile.close();
}

void showBD()
{
	ifstream bd;
	bd.open("People.txt", ios::in);
	if (bd.is_open())
	{
		string str;
		while (getline(bd, str))
		{
			cout << str << endl;
		}
		bd.close();
	}
}

vector<string> cutDate(string str , char separation)
{
	vector<string> date;

	stringstream ss(str);
	string piece;

	while (getline(ss, piece, separation))
	{
		date.push_back(piece);
	}

	return date;
}

void rmPerson(int id)
{
	fstream bd;
	vector<string> strV;
	bd.open("People.txt", ios::in | ios::out );
	if (bd.is_open())
	{
		string str;
		while (getline(bd, str))
		{
			strV.push_back(str);
		}
		for (int i = 0; i <= strV.size(); i++)
		{
			if (cutDate(strV[i], ';')[0] != to_string(id))
			{
				bd << strV[i];
			}
		}
		bd.close();
	}
}





