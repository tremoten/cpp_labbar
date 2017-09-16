//-----------------------------------------------------------------------------
// Lab4 u2.cpp
// Uppgift 2 - Program f�r att ber�kna samtalstaxa f�r RingPling2
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include <iostream>     // cout endl
#include <sstream>		// iss
#include <iomanip>     // setw
#include <string>      // string-klassen
#include <vector>	   // vector
using namespace std;   //cout cin
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funktionsprototyp
//------------------------------------------------------------------------------
bool isTimeFormatValid(vector<int> time, string input);								//kontroll att angiven tid �r korrekt
bool startStoppTime(string start, string stopp);									//kontroll att sluttid ska va st�rre �n starttid
bool userInputOnlyDigits(string possibleNum);										//Kontroll att angiven tid enbart �r siffror
char menyVal();																		//menyn, vill du g�ra igen?
int callTimeInMinute(string time);													//omvandlar start och sluttid till int
vector<int> splitString(string str);												//skapar en vector 
bool isTimeCorrect(vector<int> startTime, vector<int> stoppTime);					//kontroll att stopptiden �r efter starttiden 
double phoneCharge(string start, string stopp);										//R�kna ut kostnaden f�r samtalet	
//------------------------------------------------------------------------------
// main() b�rjar
//------------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, ""); //���
	//variabler
	string start, stopp;														// anv�ndarens start och stopptid
	vector <int> startTime, stoppTime;
	double userRateCosts = 0;													// lagra summan f�r vad samtalet kostar
	double calls = 0;
	char menyval;

	do																			//huvudloop, upprepas s� l�nge anv�ndaren svarar y
	{
		cout << "+ ~~~~*~~~~~~*~~~~~*~~~~*~~~~~ +";
		cout << endl << "	| RingPling2  |		" << endl;
		cout << "+ ~~~~*~~~~~~*~~~~~*~~~~*~~~~~ +" << endl << endl;
		do
		{
			do
			{
				cout << "Starttid (HH:MM eller H:MM): ";							//inmatning av anv�ndarens start tid
				getline(cin, start);
				startTime = splitString(start);										//returnerar en vector						
			} while (!isTimeFormatValid(startTime, start));

			do
			{
				cout << "Sluttid (HH:MM eller H:MM): ";								//inmatning av anv�ndarens stopp tid
				getline(cin, stopp);
				stoppTime = splitString(stopp);
			} while (!isTimeFormatValid(stoppTime, stopp));


		} while (!isTimeCorrect(startTime, stoppTime));						//anrop av en funktion som kollar att stopptiden �r st�rre �n starttiden

		//anrop av en funktion som r�knar ut samtalets kostnad 
		userRateCosts =	phoneCharge(start, stopp);

		//utskrift av samtalskostnad 
	//	cout << "Samtalet kostar " << userRateCosts << "kr" << endl;

		do																		//loop f�r att fr�ga anv�ndaren om den vill g�ra en g�ng till
		{
			menyval = menyVal();
		} while (!(menyval == 'y' || menyval == 'n'));

	} while (menyval == 'y');
	return 0;
}


//------------------------------------------------------------------------------
//Funktionsdefinitioner
//------------------------------------------------------------------------------
//splitString
//Uppgift: Skapar en vector 
//------------------------------------------------------------------------------
vector<int> splitString(string str)
{
	vector<int> hourMinute;       // skapar en vector
	int index = str.find(':');

	if (index != -1)
	{

		str[index] = ' '; // Ers�tt kolon med mellanslag f�r stringstream s� att iss kan omvandla string till ett tal
		istringstream iss(str); // Skapa str�ngstr�m av str�ngen

		int hour = 0, minute = 0;
		iss >> hour >> minute;   // Delar str�ngen till timmar och minuter

		
		// ???

		hourMinute.push_back(hour);   // index 0, timmar (add)
		hourMinute.push_back(minute); //index 1, minuter (add)
	}

	return hourMinute;
}
//------------------------------------------------------------------------------
//isTimeCorrect
//Uppgift: Kontroll att stopptiden �r efter starttiden
//------------------------------------------------------------------------------
bool isTimeCorrect(vector<int> startTime, vector<int> stoppTime)
{
	int startHour = startTime[0];
	int startMinute = startTime[1];
	int stoppHour = stoppTime[0];
	int stoppMinute = stoppTime[1];

	if (startHour < stoppHour)
	{
		return true;
	}
	else if (startHour == stoppHour && startMinute < stoppMinute)
	{
		return true;
	}
	cout << "Starttiden m�ste vara f�re stopptiden" << endl << endl;
	return false;
}

//------------------------------------------------------------------------------
//checkUserTime
//Uppgift: Kontrollera att anv�ndarens start och stopptid �r korrekt. 
//------------------------------------------------------------------------------
bool isTimeFormatValid(vector<int> time, string input)
{
	//Kolla s� tidsformatet �r fem el fyra tecken l�ngt f�r tid
	if ( (input.length() == 4 && input[1] == ':') || (input.length() == 5 && input[2] == ':') && userInputOnlyDigits(input) )
	{
		int hour = time[0];		//plockar ut v�rdet fr�n vector splitString, timmar
		int minute = time[1];

		// Kolla s� att timmar ligger mellan 0 och 23
		if (hour < 0 || hour > 23)
		{
			cout << "Du har skrivit fel format p� timmar" << endl;
			return false;
		}

		// Kolla s� att minuter ligger mellan 0 och 59
		if (minute < 0 || minute > 59)
		{
			cout << "Du har skrivit fel format p� minuter" << endl;
			return false;
		}
		return true;
	}

	// Om kolonet �r p� helt fel plats eller str�ngen �r f�r l�ng eller kort, skriv ut felmeddelande
	else
	{
		cout << "Tidsformatet du skrev �r felaktigt, ange HH:MM eller H:MM" << endl;
	}

	//startStoppTime(time);

	return false;
}

//------------------------------------------------------------------------------
//startStoppTime
//Uppgift: kontroll att start tiden �r mindre �n sluttiden 
//------------------------------------------------------------------------------
bool startStoppTime(string start, string stopp)
{

	//sluttid ska va st�rre �n starttid
	if (start > stopp)
	{
		cout << "Starttiden kan inte vara mindre �n sluttid" << endl;
	}

	return true;
}

//------------------------------------------------------------------------------
//userInputOnlyDigits
//Uppgift: Kontroll s� att tiden enbart �r i siffror
// http://www.cplusplus.com/reference/string/string/find_first_not_of/
// http://stackoverflow.com/questions/35741343/c-find-first-not-of
//------------------------------------------------------------------------------
bool userInputOnlyDigits(string input)
{
	bool ok;
	if (input != "")
	{
		ok = (input.find_first_not_of("0123456789:") == string::npos);
	}
	return ok;
}


//------------------------------------------------------------------------------
//phoneCharge
//Uppgift: R�kna ut kostnaden f�r samtalet												
//------------------------------------------------------------------------------
double phoneCharge(string start, string stopp)
{
	const double vat = 1.25;						// Moms 25%
	const double rate = 4.00;						// Ordinare taxa
	const double eavningDiscount = 0.35;			// Kv�llspris 65% rabatt
	const double callLengthDiscount = 0.85;		   	// Samtal l�ngre �n 30 min, 15% rabatt
	const string startTimeFullRate = "8:00";		// Starttid f�r fulltaxa, 8:00
	const string endTimeFullRate = "18:30";			// Stopptid f�r fulltaxa, 18:30

	//Antal minuter fr�n midnatt till n�r samtalet b�rjar
	int startMinute = callTimeInMinute(start);
	//Antal minuter fr�n midnatt till n�r samtalet slutar
	int stoppMinute = callTimeInMinute(stopp);

	//Antal minuter fr�n midnatt d�r fulltaxa b�rjar och slutar  
	int startFullRate = callTimeInMinute(startTimeFullRate);
	int stoppFullRate = callTimeInMinute(endTimeFullRate);

	int totalMinuteFullRate = 0;
	int totalMinuteDiscount = 0; 

	//Loop f�r att r�kna ut samtalsmunter till fullpris och rabatterat pris
	for (int i = startMinute; i < stoppMinute; i++)
	{
		if (i >= startFullRate && i < stoppFullRate)
			totalMinuteFullRate++;  //+1min p� fulltaxa
		else
		{
			totalMinuteDiscount++; //+1min p� rabatt
		}
	}
	//Utr�kning f�r priset f�r samtalet
	double totalPrice = (totalMinuteFullRate * rate) + (totalMinuteDiscount * rate) * eavningDiscount;

	// + moms
	totalPrice = totalPrice * vat;

	//Samtal som �r l�ngre �n 30min
	if (totalMinuteFullRate + totalMinuteDiscount > 30)
	{
		totalPrice = totalPrice * callLengthDiscount;
		
	}
	if (totalPrice > 0)
	{
		cout << "Samtalet kostar " << totalPrice << "kr" << endl;
	}
	else
	{
		cout << "Samtalet kostnade inget" << endl; 
	}

	return totalPrice;
}


//------------------------------------------------------------------------------
//callTimeInMinute
//Uppgift: R�kna ut samtalet till antal minuter
//------------------------------------------------------------------------------
int callTimeInMinute(string time)
{
	int totalMinutes = 0; // Variabel f�r att lagra antalet minuter
	int hour = 0, minute = 0; // Variabler att lagra stringstreams utdata i
	int separator = time.find(":"); // Hittade kolonets plats i str�ngen

	time[separator] = ' '; // Ers�tt kolon med mellanslag f�r stringstream

	istringstream iss(time); // Skapa str�ngstr�m av str�ngen
	iss >> hour >> minute; // Sl� is�r str�ngen till timmar och minuter

	totalMinutes = (hour * 60) + minute; // Varje timme �r 60 min

	return totalMinutes;
}

//------------------------------------------------------------------------------
//menyVal
//Uppgift: Vill du k�ra programmet en g�ng till?
//------------------------------------------------------------------------------
char menyVal()
{
	char menyval; // char f�r att lagra menyvalet

	cout << endl << "Vill du k�ra programmet igen (y/n)? ";
	cin.get(menyval); // L�s ett tecken (y eller n)
	menyval = tolower(menyval);
	cin.get(); // L�s bort retur

	return menyval;
}