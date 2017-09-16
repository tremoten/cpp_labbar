//------------------------------------------------------------------- 
// Lab2 u3.cpp 
// Uppgift 2 - Pallindrom
// Anna-Malin Joshammar
//------------------------------------------------------------------- 
#include <iostream>		// cout endl
#include <iomanip>      // setw
using namespace std;	//cout cin 
//-------------------------------------------------------------------

int main(){

	//variabler 
	setlocale(LC_ALL, ""); //���
	int number;
	char response;
	//------------------------------------------------------------ huvudloopen
	do
	{
		//------------------------------------------------------------ loop f�r att kontrollera om talet �r ett pallindrom

		do
		{
			cout << "Skriv in ett femsiffrigt heltal: ";
			bool isDigit = true;   //----------- g�r att ta bort true
			do
			{
				if (!(cin >> number))   //--------------------- returnerar falskt om det inte �r ett nummer 
				{
					cout << "Endast siffror \x84r till\x86tna, skriv ett nytt tal.";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // rensa buffer f�r cin 
					isDigit = false;
				}
				else
				{
					isDigit = true;
				}
			} while (!isDigit);

		} while (number < 10000 || number > 99999);  //----------------- kollar att talet �r fem siffror 

		int reverse = 0;
		int orgNumber = number;
		int lastDigit;

		while (number >= 10) //------ f�r att kolla nummret bakl�nges
		{
			lastDigit = number % 10;
			number = number / 10;
			reverse = (reverse * 10) + lastDigit;
		}
		reverse = (reverse * 10) + number;  //--- l�gger p� sista siffran 

		if (reverse == orgNumber)
		{
			cout << "Ditt tal " << orgNumber << endl;
			cout << "Ditt tal bakl\x84nges " << reverse << " \x84r ett palindrom" << endl;
		}
		else
		{
			cout << "Ditt tal " << orgNumber << endl;
			cout << "Ditt tal bakl\x84nges " << reverse << " \x84r inte ett palindrom" << endl;
		}

		cout << "Vill du testa ett nytt nummer? (y/n): ";
		//------------------------------------------------------------ loop f�r att k�ra igen om anv�ndaren svarar Y
		do
		{
			cin >> response;
			response = toupper(response);

		} while (!(response == 'Y' || response == 'N'));

	} while (response == 'Y');
	return 0;

}

/*
\x86 = �
\x84 = �
\x94 = �
*/