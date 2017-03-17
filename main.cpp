#include <algorithm>
#include "functions.cpp"


int main()
{
	using namespace std;

	string wyraz;

	cout << "witam w programie do ops�ugi podstawowej tekstowej ''bazy danych''" << endl;
	cout << "wprowadz numer operacji kt�r� chcesz wykona� :" << endl;
	cout << "1 - wy�wietl baze ludzi" << endl;
	cout << "2 - posortuj baze ludzie wed�ug imion" << endl;
	cout << "3 - posortuj baze ludzie wed�ug nazwisk" << endl;
	cout << "4 - posortuj baze ludzie wed�ug wieku" << endl;
	cout << "5 - dodaj x przypadkowych os�b" << endl;
	cout << "6 - dodaj now� osobe" << endl;
	cout << "7 - usu� osob� o id x" << endl;
	// to do add id at random
	cin >> wyraz;

	switch (stoi(wyraz))
	{
		case 1 :
			showBD();
			break;
		case 2:
		{
			fstream bd;
			vector<string> bdV;
			bd.open("People.txt", ios::in);
			if (bd.is_open())
			{
				string str;
				while (getline(bd, str))
				{
					bdV.push_back(str);
				}
				bd.close();
			}
			for (int i = 0; i <= bdV.size(); i++)
			{
				vector<string> str;
				str = cutDate(bdV[i], ';');
				bdV[i] = str[1] + ";" + str[0] + ";" + str[2] + ";" + str[3] + ";" + str[4] + ";" + str[5] + ";" + str[6] + ";" + str[7];
			}
			sort(bdV.begin() , bdV.end());
			cout << "zapisa� do pliku - z		czy wy�wietli� na konsoli - w" << endl;
			char x;
			cin >> x;
			if (x == 'z')
			{
				string name;
				fstream file;
				cout << "podaj nazwe pliku do ktorego chcesz zapisa�"<< endl ;
				cin >> name;
				file.open(name + ".txt", ios::out || ios::app);
				if (file.is_open())
					for (int i = 0; i <= bdV.size(); i++)
					{
						file << bdV[i] + "\n";
					}
			}
			if (x == 'w')
			{
				for (int i = 0; i <= bdV.size(); i++)
				{
					cout << bdV[i] << endl;
				}
			}
			break;
		}
		case 3:
		{
			fstream bd;
			vector<string> bdV;
			bd.open("People.txt", ios::in);
			if (bd.is_open())
			{
				string str;
				while (getline(bd, str))
				{
					bdV.push_back(str);
				}
				bd.close();
			}
			for (int i = 0; i <= bdV.size(); i++)
			{
				vector<string> str;
				str = cutDate(bdV[i], ';');
				bdV[i] = str[2] + ";" + str[0] + ";" + str[1] + ";" + str[3] + ";" + str[4] + ";" + str[5] + ";" + str[6] + ";" + str[7];
			}
			sort(bdV.begin(), bdV.end());
			cout << "zapisa� do pliku - z		czy wy�wietli� na konsoli - w" << endl;
			char x;
			cin >> x;
			if (x == 'z')
			{
				string name;
				fstream file;
				cout << "podaj nazwe pliku do ktorego chcesz zapisa�" << endl;
				cin >> name;
				file.open(name + ".txt", ios::in | ios::app);
				if (file.is_open())
					for (int i = 0; i <= bdV.size(); i++)
					{
						file << bdV[i] + "\n";
					}
			}
			if (x == 'w')
			{
				for (int i = 0; i <= bdV.size(); i++)
				{
					cout << bdV[i] << endl;
				}
			}
			break;
			break;
		}
		case 4:
		{
			fstream bd;
			vector<string> bdV;
			bd.open("People.txt", ios::in);
			if (bd.is_open())
			{
				string str;
				while (getline(bd, str))
				{
					bdV.push_back(str);
				}
				bd.close();
			}
			for (int i = 0; i <= bdV.size(); i++)
			{
				vector<string> str;
				str = cutDate(bdV[i], ';');
				bdV[i] = str[3] + ";" + str[0] + ";" + str[1] + ";" + str[2] + ";" + str[4] + ";" + str[5] + ";" + str[6] + ";" + str[7];
			}
			sort(bdV.begin(), bdV.end());
			cout << "zapisa� do pliku - z		czy wy�wietli� na konsoli - w" << endl;
			char x;
			cin >> x;
			if (x == 'z')
			{
				string name;
				fstream file;
				cout << "podaj nazwe pliku do ktorego chcesz zapisa�" << endl;
				cin >> name;
				file.open(name + ".txt", ios::in | ios::app);
				if (file.is_open())
					for (int i = 0; i <= bdV.size(); i++)
					{
						file << bdV[i] + "\n";
					}
			}
			if (x == 'w')
			{
				for (int i = 0; i <= bdV.size(); i++)
				{
					cout << bdV[i] << endl;
				}
			}
			break;

			break;
		}
		case 5:
		{
			cout << "podaj ile os�b ma by� dodanych do bazy" << endl;
			int x;
			cin >> x;
			makePeople(x);
			break;
		}
		case 6:
		{
			string name;
			string surname;
			int age;
			string dateOfBirth;
			string tnumber;
			string nationality;
			string isMale;

			cout << "podaj imi� osoby" << endl;
			cin >> name;
			cout << "podaj nazwisko osoby" << endl;
			cin >> surname;
			cout << "podaj date urodzenia odzielon� '-' osoby" << endl;
			cin >> dateOfBirth;
			cout << "podaj numer telefonu osoby" << endl;
			cin >> tnumber;
			cout << "podaj narodowo�� osoby" << endl;
			cin >> nationality;
			cout << "wpisz 1 je�li osoba jest m�szczyzn� lub 0 je�li jest kobiet�" << endl;
			cin >> isMale;

			vector<string> date = cutDate(dateOfBirth, '-');
			age = 2017 - stoi(date[2]);

			fstream outFile("People.txt", ios::app);

			addPerson(people::people(getId(), name, surname, age, dateOfBirth, stoi(tnumber), stoi(isMale), nationality), outFile);

			break;
		}
		case 7:
		{
			cout << "osobe o jakim id ma zosta� usuni�ta ?" << endl;
			int x;
			cin >> x;
			rmPerson(x);
			break;
		}
		default:
			cout << "poda�e� nieistniej�c� opcje" << endl;
			break;
	}
	
	system("PAUSE");
	return(1);
}

