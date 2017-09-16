
//-------------------------------------------------------------------
// Lab2 u1.cpp
// Uppgift 2 - Uppgift 1 Pytagoreiska trianglar
// Anna-Malin Joshammar
//-------------------------------------------------------------------
#include <iostream>
using namespace std;
//-------------------------------------------------------------------

int main(){
	//variabler
	int triangels = 0;

	//Uträkning av alla
	for (int a2 = 1; a2 <= 500; a2++)
	{
		for (int b2 = a2; b2 <= 500; b2++)
		{
			int c2 = sqrt((a2*a2) + (b2*b2));

			if ((a2*a2) + (b2*b2) == (c2*c2) && c2 <= 500)
			{
				triangels++;

				if (c2 % 100 == 0)
				{
					cout << "Triangeln med sidorna" << endl << "A: " << a2 << endl << "B: " << b2 << endl << "C: " << c2 << endl;
				}
			}
		}
	}
	cout << "Det ar totalt: " << triangels << endl;
	return 0;
}

