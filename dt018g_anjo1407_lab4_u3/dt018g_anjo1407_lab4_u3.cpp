//-----------------------------------------------------------------------------
// Lab4 Uppgift 3
// Uppgift 3 - Menysystem 
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include <iostream> 
#include <string> 
using namespace std;

#include "H_dt018g_anjo1407_lab4u1.h"
#include "H_dt018g_anjo1407_lab4u2.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Funktionsprototyp
//------------------------------------------------------------------------------
void showMenu();   // Skriver ut menyalternativen 

//------------------------------------------------------------------------------
// main() börjar
//------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, ""); //ÅÄÖ
	bool again = true;
	do
	{
		for (int i = 0; i < 25; i++)
		{
			i++;
			cout << '\n';
		}

		showMenu();                    // Visa menyalternativ
		char ch;
		cin >> ch;                      // Användaren gör sitt val 
		switch (ch)
		{                              // Kör valt delprogram       
		case '1': 
			rollDice();
			break;
		case '2': 
			teleTaxa();
			break;
		case '3':                     // Sluta med 3, q eller Q 
		case 'q':
		case 'Q': again = false;
		}
	} while (again);
	return 0;
}

//------------------------------------------------------------------------------
//Funktionsdefinitioner
//------------------------------------------------------------------------------
void showMenu()
{
	cout << endl;
	cout << " ***** MENU *****" << endl << endl;
	cout << "   1. Kasta tärning" << endl;
	cout << "   2. RingPling" << endl;
	cout << "   3. Avsluta" << endl;
}




