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
	setlocale(LC_ALL, ""); //ÅÄÖ
	int number;
	char response;
	//------------------------------------------------------------ huvudloopen
	do
	{
		//------------------------------------------------------------ loop för att kontrollera om talet är ett pallindrom

		do
		{
			cout << "Skriv in ett femsiffrigt heltal: ";
			bool isDigit = true;   //----------- går att ta bort true
			do
			{
				if (!(cin >> number))   //--------------------- returnerar falskt om det inte är ett nummer 
				{
					cout << "Endast siffror \x84r till\x86tna, skriv ett nytt tal.";
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // rensa buffer för cin 
					isDigit = false;
				}
				else
				{
					isDigit = true;
				}
			} while (!isDigit);

		} while (number < 10000 || number > 99999);  //----------------- kollar att talet är fem siffror 

		int reverse = 0;
		int orgNumber = number;
		int lastDigit;

		while (number >= 10) //------ för att kolla nummret baklänges
		{
			lastDigit = number % 10;
			number = number / 10;
			reverse = (reverse * 10) + lastDigit;
		}
		reverse = (reverse * 10) + number;  //--- lägger på sista siffran 

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
		//------------------------------------------------------------ loop för att köra igen om användaren svarar Y
		do
		{
			cin >> response;
			response = toupper(response);

		} while (!(response == 'Y' || response == 'N'));

	} while (response == 'Y');
	return 0;

}

/*
\x86 = å
\x84 = ä
\x94 = ö
*/