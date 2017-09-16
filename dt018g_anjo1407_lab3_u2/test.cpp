//------------------------------------------------------------------- 
// Lab3 u2.cpp 
// Uppgift 2 - Sortera 3 namn
// Anna-Malin Joshammar
//------------------------------------------------------------------- 
#include <iostream>		// cout endl
#include <string>		//string-klassen
using namespace std;	//cout cin 
//-------------------------------------------------------------------

int main(){

	// https://www.youtube.com/watch?v=NzWdy7_LK_I
	setlocale(LC_ALL, ""); //ÅÄÖ

	//variabler 
	string name1;
	string name2;
	string name3;

	cout << "Skriv tre för och efternamn" << endl << endl;
	cout << "Person 1" << endl;
	cout << "Förnamn och efternamn: ";
	getline(cin, name1);

	cout << "Person 2" << endl;
	cout << "Förnamn och efternamn: ";
	getline(cin, name2);

	cout << "Person 3" << endl;
	cout << "Förnamn och efternamn: ";
	getline(cin, name3);

	cout << "Du har skrivit in dessa tre personer: " << endl << name1 << endl << name2 << endl << name3 << endl << endl;

	//Ändra namnen till små bokstäver
	string name1ToLower = name1;
	string name2ToLower = name2;
	string name3ToLower = name3;

	//Name1                                                  
	for (int i = 0; i <= name1ToLower.size(); i++)
	{
		name1ToLower[i] = tolower(name1ToLower[i]);
	}

	//Name2
	for (int i = 0; i <= name2ToLower.size(); i++)
	{
		name2ToLower[i] = tolower(name2ToLower[i]);
	}

	//Name3
	for (int i = 0; i <= name3ToLower.size(); i++)
	{
		name3ToLower[i] = tolower(name3ToLower[i]);
	}


	//Dela på förnamn och efternamn
	string firstName1;
	string lastName1;
	string tempFirstName;
	string tempLastName;

	//Name1
	for (int i = 0; i <= name1ToLower.size(); i++)
	{
		char tempChar = name1ToLower[i];
		tempFirstName += tempChar;

		if (name1ToLower[i] == ' ')
		{
			firstName1 = tempFirstName;

			for (int j = i; j <= name1ToLower.size(); j++)
			{
				char tempChar1 = name1ToLower[j];
				tempLastName += tempChar1;
			}
			lastName1 = tempLastName;
		}
	}

	//Delar på förnamn och efternamn
	string firstName2;
	string lastName2;
	tempFirstName = "";
	tempLastName = "";

	//Name2
	for (int i = 0; i <= name2ToLower.size(); i++)
	{
		char tempChar = name2ToLower[i];
		tempFirstName += tempChar;

		if (name2ToLower[i] == ' ')
		{
			firstName2 = tempFirstName;

			for (int j = i; j <= name2ToLower.size(); j++)
			{
				char tempChar1 = name2ToLower[j];
				tempLastName += tempChar1;
			}
			lastName2 = tempLastName;
		}
	}

	//Delar på förnamn och efternamn
	string firstName3;
	string lastName3;
	tempFirstName = "";
	tempLastName = "";

	//Name3
	for (int i = 0; i <= name3ToLower.size(); i++)
	{
		char tempChar = name3ToLower[i];
		tempFirstName += tempChar;

		if (name3ToLower[i] == ' ')
		{
			firstName3 = tempFirstName;

			for (int j = i; j <= name3ToLower.size(); j++)
			{
				char tempChar1 = name3ToLower[j];
				tempLastName += tempChar1;
			}
			lastName3 = tempLastName;
		}
	}

	// Kontroll för att se vilket av namnen som ska vara först
	if (lastName1 < lastName2 && lastName1 < lastName3)  // name1 är först 
	{
		cout << name1 << endl;

		if (lastName2 < lastName3)
		{
			cout << name2 << endl;
			cout << name3 << endl;
		}
		else if (lastName2 == lastName3)
		{
			if (firstName2 <= firstName3) // mindre el likamed
			{
				cout << name2 << endl;
				cout << name3 << endl;
			}
			else
			{
				cout << name3 << endl;
				cout << name2 << endl;
			}
		}
		else
		{
			cout << name3 << endl;
			cout << name2 << endl;
		}
	}

	else if (lastName2 < lastName1 && lastName2 < lastName3) // name2 är först 
	{
		cout << name2 << endl;

		if (lastName1 < lastName3)
		{
			cout << name1 << endl;
			cout << name3 << endl;
		}
		else if (lastName1 == lastName3)
		{
			if (firstName1 <= firstName3) // mindre el likamed
			{
				cout << name1 << endl;
				cout << name3 << endl;
			}
			else
			{
				cout << name3 << endl;
				cout << name1 << endl;
			}
		}
		else
		{
			cout << name3 << endl;
			cout << name1 << endl;
		}
	}

	else if (lastName3 < lastName1 && lastName3 < lastName2) // name3 är först
	{
		cout << name3 << endl;

		if (lastName2 < lastName1)
		{
			cout << name2 << endl;
			cout << name1 << endl;
		}
		else if (lastName2 == lastName1)
		{
			if (firstName2 <= firstName1) // mindre el likamed
			{
				cout << name2 << endl;
				cout << name1 << endl;
			}
			else
			{
				cout << name1 << endl;
				cout << name2 << endl;
			}
		}
		else
		{
			cout << name1 << endl;
			cout << name2 << endl;
		}
	}

	//Kontroll ifall efternamn är likadana så ska den fortsätta på förnamn

	else if (lastName1 == lastName2 && lastName1 < lastName3)  // 1 o 2 lika 3 är sist 
	{
		if (firstName1 <= firstName2)
		{
			cout << name1 << endl;
			cout << name2 << endl;
		}
	}

	else if (lastName1 == lastName3 && lastName1 < lastName2)  // 1 o 3 lika 2 är sist 
	{
		if (firstName1 <= firstName3)
		{
			cout << name1 << endl;
			cout << name3 << endl;
		}
	}

	else if (lastName2 == lastName3 && lastName2 < lastName1)  // 2 o 3 lika 1 är sist 
	{
		if (firstName2 <= lastName3)
		{
			cout << name2 << endl;
			cout << name3 << endl;
		}
	}

	else if (lastName1 == lastName2 && lastName2 == lastName3)  // alla har samma efternamn 
	{
		if (firstName1 < firstName2 && firstName1 < firstName3)  // name1 är först 
		{
			cout << name1 << endl;

			if (firstName2 < firstName3)
			{
				cout << name2 << endl;
				cout << name3 << endl;
			}
			else if (firstName2 == firstName3)
			{
				if (firstName2 <= firstName3) // mindre el likamed
				{
					cout << name2 << endl;
					cout << name3 << endl;
				}
				else
				{
					cout << name3 << endl;
					cout << name2 << endl;
				}
			}
			else
			{
				cout << name3 << endl;
				cout << name2 << endl;
			}
		}

		else if (firstName2 < firstName1 && firstName2 < firstName3) // name2 är först 
		{
			cout << name2 << endl;

			if (firstName1 < firstName3)
			{
				cout << name1 << endl;
				cout << name3 << endl;
			}
			else if (firstName1 == firstName3)
			{
				if (firstName1 <= firstName3) // mindre el likamed
				{
					cout << name1 << endl;
					cout << name3 << endl;
				}
				else
				{
					cout << name3 << endl;
					cout << name1 << endl;
				}
			}
			else
			{
				cout << name3 << endl;
				cout << name1 << endl;
			}
		}

		else if (firstName3 < firstName1 && firstName3 < firstName2) // name3 är först
		{
			cout << name3 << endl;

			if (firstName2 < firstName1)
			{
				cout << name2 << endl;
				cout << name1 << endl;
			}
			else if (firstName2 == firstName1)
			{
				if (firstName2 <= firstName1) // mindre el likamed
				{
					cout << name2 << endl;
					cout << name1 << endl;
				}
				else
				{
					cout << name1 << endl;
					cout << name2 << endl;
				}
			}
			else
			{
				cout << name1 << endl;
				cout << name2 << endl;
			}
		}
	}
	return 0;
}
/*
\x86 = å
\x84 = ä
\x94 = ö
*/