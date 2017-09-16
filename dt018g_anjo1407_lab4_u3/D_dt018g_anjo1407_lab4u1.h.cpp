//-----------------------------------------------------------------------------
// Lab4 Uppgift 3
// Uppgift 3 - Menysystem - Kasta tärning
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include "H_dt018g_anjo1407_lab4u1.h" // inkluderar min headerfil
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//Funktionsdefinitioner
//------------------------------------------------------------------------------
//Kasta tärningen
//Uppgift: Kastar tärningen lika många gånger som användaren matar in.
//------------------------------------------------------------------------------

void rollDice(void)
{
	cout << "Hur många gånger vill du kasta tärningen? ";
	int rolls = 0;                                                                                  // Antal kast användaren matar in
	cin >> rolls;

	// olika tärningarnas alternativ
	int one = 0, two = 0, three = 0, four = 0, five = 0, six = 0;                                   // 1-6 på tärningen
	int numberOfRolls = 0;																			// Räknare för att lagra antalet tärningskast 
	int result = 0;																					// Resultat av kastad tärning

	cout << "+ ~~~*~~~*~~~~ +";
	cout << endl << "| Tärningskast |" << endl;
	cout << "+ ~~~*~~~*~~~~ +" << endl;

	//loop för att kasta tärningen
	for (int i = 0; i < rolls; i++)
	{
		numberOfRolls++;
		result = diceRandom(rolls);

		cout << setw(7) << "Kast " << numberOfRolls << ": " << result << endl;

		if (result == 1)
		{
			one++;
		}
		else if (result == 2)
		{
			two++;
		}
		else if (result == 3)
		{
			three++;
		}
		else if (result == 4)
		{
			four++;
		}
		else if (result == 5)
		{
			five++;
		}
		else if (result == 6)
		{
			six++;
		}

	}
	cout << "+ ~~~*~~~ +";
	cout << endl << "|  Antal  |" << endl;
	cout << "+ ~~~*~~~ +" << endl;
	cout << setw(7) << "1:or " << one << endl
		<< setw(7) << "2:or " << two << endl
		<< setw(7) << "3:or " << three << endl
		<< setw(7) << "4:or " << four << endl
		<< setw(7) << "5:or " << five << endl
		<< setw(7) << "6:or " << six << endl;


	cout << "+ ~~~~*~~~~~~*~~~~~*~~~~*~~~~~*~~~~*~~~~~ +";
	cout << endl << "| Relativ frekvens i % för tärningskasten |" << endl;
	cout << "+ ~~~~*~~~~~~*~~~~~*~~~~*~~~~~*~~~~*~~~~~ +";

	cout << endl << setw(10) << "1:or %: " << (double)one / (double)numberOfRolls * 100 << endl
		<< setw(10) << "2:or %: " << (double)two / (double)numberOfRolls * 100 << endl
		<< setw(10) << "3:or %: " << (double)three / (double)numberOfRolls * 100 << endl
		<< setw(10) << "4:or %: " << (double)four / (double)numberOfRolls * 100 << endl
		<< setw(10) << "5:or %: " << (double)five / (double)numberOfRolls * 100 << endl
		<< setw(10) << "6:or %: " << (double)six / (double)numberOfRolls * 100 << endl;

}

//------------------------------------------------------------------------------
//Slumpar
//Uppgift: Slumpar tal mellan 1-6
//------------------------------------------------------------------------------
int diceRandom(int result)
{
	//slumpgenerator
	default_random_engine generator(random_device{}());
	uniform_int_distribution<int> random1(1, 6);
	result = random1(generator); // Variabel för att lagra slumptalet

	return result;
}