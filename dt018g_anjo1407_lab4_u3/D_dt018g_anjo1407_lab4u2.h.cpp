//-----------------------------------------------------------------------------
// Lab4 Uppgift 3
// Uppgift 3 - Menysystem - RingPling
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include "H_dt018g_anjo1407_lab4u2.h" // inkluderar min headerfil
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//Funktionsdefinitioner
//------------------------------------------------------------------------------

//teleTaxa
//Uppgift: Ring Pling 
//------------------------------------------------------------------------------
void teleTaxa()
{
	//variabler
	setlocale(LC_ALL, ""); //ÅÄÖ
	string start, stopp;														// användarens start och stopptid
	vector <int> startTime, stoppTime;
	double userRateCosts = 0;													// lagra summan för vad samtalet kostar
	double calls = 0;
	char menyval;

	do																			//huvudloop, upprepas så länge användaren svarar y
	{
		cout << "+ ~~~~*~~~~~~*~~~~~*~~~~*~~~~~ +";
		cout << endl << "	| RingPling2  |		" << endl;
		cout << "+ ~~~~*~~~~~~*~~~~~*~~~~*~~~~~ +" << endl << endl;
		do
		{
			do
			{
				cout << "Starttid (HH:MM eller H:MM): ";							//inmatning av användarens start tid
				getline(cin, start);
				startTime = splitString(start);										//returnerar en vector						
			} while (!isTimeFormatValid(startTime, start));

			do
			{
				cout << "Sluttid (HH:MM eller H:MM): ";								//inmatning av användarens stopp tid
				getline(cin, stopp);
				stoppTime = splitString(stopp);
			} while (!isTimeFormatValid(stoppTime, stopp));


		} while (!isTimeCorrect(startTime, stoppTime));						//anrop av en funktion som kollar att stopptiden är större än starttiden

		//anrop av en funktion som räknar ut samtalets kostnad 
		userRateCosts = phoneCharge(start, stopp);

		//utskrift av samtalskostnad 
		//	cout << "Samtalet kostar " << userRateCosts << "kr" << endl;

		do																		//loop för att fråga användaren om den vill göra en gång till
		{
			menyval = menyVal();
		} while (!(menyval == 'y' || menyval == 'n'));

	} while (menyval == 'y');
}
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

		str[index] = ' '; // Ersätt kolon med mellanslag för stringstream så att iss kan omvandla string till ett tal
		istringstream iss(str); // Skapa strängström av strängen

		int hour = 0, minute = 0;
		iss >> hour >> minute;   // Delar strängen till timmar och minuter


		hourMinute.push_back(hour);   // index 0, timmar (add)
		hourMinute.push_back(minute); //index 1, minuter (add)
	}

	return hourMinute;
}
//------------------------------------------------------------------------------
//isTimeCorrect
//Uppgift: Kontroll att stopptiden är efter starttiden
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
	cout << "Starttiden måste vara före stopptiden" << endl << endl;
	return false;
}

//------------------------------------------------------------------------------
//checkUserTime
//Uppgift: Kontrollera att användarens start och stopptid är korrekt. 
//------------------------------------------------------------------------------
bool isTimeFormatValid(vector<int> time, string input)
{
	//Kolla så tidsformatet är fem el fyra tecken långt för start
	if ((input.length() == 4 && input[1] == ':') || (input.length() == 5 && input[2] == ':'))
	{
		int hour = time[0];		//plockar ut värdet från vector splitString, timmar
		int minute = time[1];

		// Kolla så att timmar ligger mellan 0 och 23
		if (hour < 0 || hour > 23)
		{
			cout << "Du har skrivit fel format på timmar" << endl;
			return false;
		}

		// Kolla så att minuter ligger mellan 0 och 59
		if (minute < 0 || minute > 59)
		{
			cout << "Du har skrivit fel format på minuter" << endl;
			return false;
		}
		return true;
	}

	// Om kolonet är på helt fel plats eller strängen är för lång eller kort, skriv ut felmeddelande
	else
	{
		cout << "Tidsformatet du skrev är felaktigt, ange HH:MM eller H:MM" << endl;
	}

	//startStoppTime(time);

	return false;
}

//------------------------------------------------------------------------------
//startStoppTime
//Uppgift: kontroll att start tiden är mindre än sluttiden 
//------------------------------------------------------------------------------
bool startStoppTime(string start, string stopp)
{

	//sluttid ska va större än starttid
	if (start > stopp)
	{		
		cout << "Starttiden kan inte vara mindre än sluttid" << endl;
	}

	return true;
}
//------------------------------------------------------------------------------
//phoneCharge
//Uppgift: Räkna ut kostnaden för samtalet												
//------------------------------------------------------------------------------
double phoneCharge(string start, string stopp)
{
	const double vat = 1.25;						// Moms 25%
	const double rate = 4.00;						// Ordinare taxa
	const double eavningDiscount = 0.35;			// Kvällspris 65% rabatt
	const double callLengthDiscount = 0.85;		   	// Samtal längre än 30 min, 15% rabatt
	const string startTimeFullRate = "8:00";		// Starttid för fulltaxa, 8:00
	const string endTimeFullRate = "18:30";			// Stopptid för fulltaxa, 18:30

	//Antal minuter från midnatt till när samtalet börjar
	int startMinute = callTimeInMinute(start);
	//Antal minuter från midnatt till när samtalet slutar
	int stoppMinute = callTimeInMinute(stopp);

	//Antal minuter från midnatt där fulltaxa börjar och slutar  
	int startFullRate = callTimeInMinute(startTimeFullRate);
	int stoppFullRate = callTimeInMinute(endTimeFullRate);

	int totalMinuteFullRate = 0;
	int totalMinuteDiscount = 0;

	//Loop för att räkna ut samtalsmunter till fullpris och rabatterat pris
	for (int i = startMinute; i < stoppMinute; i++)
	{
		if (i >= startFullRate && i < stoppFullRate)
			totalMinuteFullRate++;  //+1min på fulltaxa
		else
		{
			totalMinuteDiscount++; //+1min på rabatt
		}
	}
	//Uträkning för priset för samtalet
	double totalPrice = (totalMinuteFullRate * rate) + (totalMinuteDiscount * rate) * eavningDiscount;

	// + moms
	totalPrice = totalPrice * vat;

	//Samtal som är längre än 30min
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
//Uppgift: Räkna ut samtalet till antal minuter
//------------------------------------------------------------------------------
int callTimeInMinute(string time)
{
	int totalMinutes = 0; // Variabel för att lagra antalet minuter
	int hour = 0, minute = 0; // Variabler att lagra stringstreams utdata i
	int separator = time.find(":"); // Hittade kolonets plats i strängen

	time[separator] = ' '; // Ersätt kolon med mellanslag för stringstream

	istringstream iss(time); // Skapa strängström av strängen
	iss >> hour >> minute; // Slå isär strängen till timmar och minuter

	totalMinutes = (hour * 60) + minute; // Varje timme är 60 min

	return totalMinutes;
}

//------------------------------------------------------------------------------
//menyVal
//Uppgift: Vill du köra programmet en gång till?
//------------------------------------------------------------------------------
char menyVal()
{
	char menyval; // char för att lagra menyvalet

	cout << endl << "Vill du köra programmet igen (y/n)? ";
	cin.get(menyval); // Läs ett tecken (y eller n)
	menyval = tolower(menyval);
	cin.get(); // Läs bort retur

	return menyval;
}