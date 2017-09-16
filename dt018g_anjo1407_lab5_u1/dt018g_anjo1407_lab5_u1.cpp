//-----------------------------------------------------------------------------
// Lab5 u1.cpp
// Uppgift 1 - S�k och sortera en array C-array
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include <iostream>     // cout endl
#include <random>		// random
#include <iomanip>    // setw()
using namespace std;   //cout cin
//------------------------------------------------------------------------------
// Funktionsprototyp
//------------------------------------------------------------------------------
int random();

//------------------------------------------------------------------------------
// main() b�rjar
//------------------------------------------------------------------------------
int main()
{
	setlocale(LC_ALL, ""); //���

	// Skapa en heltalsarray med plats f�r 600 tal. Storleken anges med en konstant. 
	const size_t max600 = 600; // Antal platser i array
	const int frek = 100; // Platser i frekvensarray och slumpgeneratorns max

	//Skapar en array med 600 platser
	int arr[max600] = { 0 };

	//Slumpa tal till arrayen. Talen ska ligga i intervallet 1..100 
	//Fyll array med slumpade siffror
	for (size_t i = 0; i < max600; i++)
	{
		arr[i] = random();
	}

	//Skriv ut array
	cout << "Osorterad array med 600 tal mellan 1-100" << endl;
	for (size_t i = 0; i < max600; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Skapar en array till f�r att kopiera till 
	int arr2[max600] = {};

	//Kopiera arrayen till en ny array
	//Kopiera arr --> arr2
	for (auto i = 0; i < max600; i++)
	{
		arr2[i] = arr[i];
	}

	//Sortera arrayen stigande med bubble sort
	for (size_t pass = 0; pass < max600 - 1; pass++)	//Stega igenom arrayen SIZE-1 ggr   
		for (size_t i = 0; i < max600 - 1; i++)        // J�mf�r elementen parvis     
			if (arr2[i] > arr2[i + 1])				    // Byt plats om fel ordning     
			{
				int tmp = arr2[i];
				arr2[i] = arr2[i + 1];
				arr2[i + 1] = tmp;
			}

	//Skriv ut alla talen i arrayen/vectorn med alla ettor p� en rad, alla tv�or p� en ny rad och s� vidare till alla 99:or p� en rad och alla tal 100 p� en rad. 
	for (int i = 0; i < max600; i++)
	{
		int temp = arr2[i];
		cout << arr2[i] << " ";

		if (arr2[i + 1] != temp)
			cout << endl;
	}

	//Ber�kna medelv�rdet, st�rsta och minsta tal i arrayen 
	//Ber�kna summan och medelv�rde f�r arrayen
	int sum = 0;
	float average = 0;
	for (auto i = 0; i < max600; i++)
	{
		sum += arr2[i];
	}
	average = static_cast<float>(sum) / max600;

	//Tar reda p� minsta och st�rsta v�rdet i arrayen
	int max = arr2[0];
	int min = arr2[0];

	for (auto i = 0; i < max600; i++)
	{
		if (arr2[i] > max)  // Leta det st�rsta v�rdet    
		{
			max = arr2[i];
		}
		if (arr2[i] < min)  // Leta det minsta v�rdet  
		{
			min = arr2[i];
		}
	}
	//Skriv ut medelv�rde, max och min fr�n array
	cout << "Medelv�rdet �r: " << average << endl;
	cout << "St�rsta talet i arrayen �r: " << max << endl;
	cout << "Minsta talet i arrayen �r: " << min << endl;

	//Ber�kna hur m�nga f�rekomster det finns i arrayen av ett tal som anv�ndaren anger 
	int userNumber = 0;
	int counter = 0;
	cout << "Ange ett nummer mellan 1-100 f�r att s�ka efter: ";
	cin >> userNumber;

	// S�k efter det inmatade talet
	for (auto i = 0; i < max600; i++)
		if (arr2[i] == userNumber)
			counter++;

	// Skriv ut antal f�rekomster f�r det inmatade talet
	cout << "Nummret " << userNumber << " fanns " << counter << " g�nger." << endl << endl;

	//Ber�kna vilket tal det finns flest av i arrayen.
	int mostNumberInArray = 0;
	int tmp = 0;
	counter = 0; 

	for (auto i = 0; i < max600; i++)
	{
		tmp = arr2[i];
		int tmpCounter = 0;
		int tmpMostNumberInArray = 0;
		for (auto j = 0; j < max600; j++)
		{
			if (tmp == arr2[j])
			{
				tmpCounter++;
			}
		}
		if (tmpCounter > counter)
		{
			counter = tmpCounter;
			mostNumberInArray = arr2[i];
		}
	}
	cout << "Nummret som f�rekomster flest g�nger �r: " << mostNumberInArray << " och finns " << counter << " g�nger." << endl;

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
	int result = random1(generator); // Variabel f�r att lagra slumptalet
	return result;
}




