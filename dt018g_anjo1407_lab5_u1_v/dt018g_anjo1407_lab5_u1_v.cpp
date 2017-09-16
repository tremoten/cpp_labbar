//-----------------------------------------------------------------------------
// Lab5 u1.cpp
// Uppgift 1 - Sök och sortera en array Std::vector
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include <iostream>     // cout endl
#include <random>		// random
#include <iomanip>    // setw()
#include <vector>		//stl::vector
#include <algorithm>       // std::sort() count
using namespace std;   //cout cin
//------------------------------------------------------------------------------

// Funktionsprototyp
//------------------------------------------------------------------------------
int random();

//------------------------------------------------------------------------------
// main() börjar
//------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, ""); //ÅÄÖ

	//Skapa två constanta variabler, plats för 600 tal och storleken anges med en konstant.
	const size_t max600 = 600; // Antal platser i array

	//Skapar en vector med 600 platser
	vector<int> integers1(max600);

	//Slumpa tal till vectorn. Talen ska ligga i intervallet 1..100 
	//Fyll vector med slumpade siffror
	int count1 = 1;
	for (auto &e: integers1)
	{
		e = random();
	}

	//Skriv ut array
	cout << "Osorterad array" << endl;  
	for (size_t i = 0; i < max600; i++)  
		cout << setw(4) << integers1[i];

	//Skapar en vector och kopierar integers1 till den
	vector<int> integers2 = integers1;

	//Sortera arrayen 
	sort(integers2.begin(), integers2.end());

	//Skriv ut hela arrayen på skärmen
	cout << endl << endl << "Sorted array" << endl;  

	//Skriv ut alla talen i arrayen/vectorn med alla ettor på en rad, alla tvåor på en ny rad och så vidare till alla 99:or på en rad och alla tal 100 på en rad. 
	int recent = integers2[0]; 
	for (int i = 0; i < integers2.size(); i++)
	{
		int temp = integers2[i];
		if (temp != recent)
		{
			cout << endl;
			recent = temp;
		}
		cout << temp << " ";
	}
	cout << endl << endl; 

	//Beräkna medelvärdet, största och minsta tal i arrayen 
	//Beräkna summan och medelvärde för arrayen
	int sum = 0;
	for (auto e : integers2)
	{
		sum += e;
	}
	float avereage = float(sum) / integers2.size();

	int max = *(max_element(integers2.begin(), integers2.end()));
	int min = *(min_element(integers2.begin(), integers2.end()));

	cout << "Minsta talet i arrayen är: " << min << endl;
	cout << "Största talet i arrayen är: " << max << endl;   
	cout << "Medelvärdet är: " << avereage << endl;

	//Beräkna vilket tal det finns flest av i arrayen.
	max = 0;
	int maxIndex = integers2[0];
	int numCount = 0;

	for (auto i : integers2)
	{
		numCount = (int)count(integers2.begin(), integers2.end(), integers2[i]);
		if (numCount > max)
		{
			max = numCount;
			maxIndex = integers2[i];
		}
	}
	// Skriv ut resultat
	cout << "Talet med flest förekomster är: " << maxIndex << " och förekommer " << max << " gånger." << endl << endl;
	
	//Beräkna hur många förekomster det finns i arrayen av ett tal som användaren anger 
	int number = 0, counter = 0;

	cout << "Ange ett tal att söka efter: ";
	cin >> number;

	// Sök och räkna träffar, skriv ut resultat
	counter = count(integers2.begin(), integers2.end(), number);
	cout << "Talet " << number << " fanns " << counter << " gånger." << endl << endl;
	return 0;
}

//------------------------------------------------------------------------------
//Funktionsdefinitioner
//------------------------------------------------------------------------------
//Slumpar
//Uppgift: Slumpar tal mellan 1-100
//------------------------------------------------------------------------------
int random()
{
	random_device rd; 
	default_random_engine generator(rd()); //rd seeds generator 
	uniform_int_distribution<int> random1(1, 100);
	int result = random1(generator); // Variabel för att lagra slumptalet
	return result;
}