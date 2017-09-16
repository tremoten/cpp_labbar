//-----------------------------------------------------------------------------
// Lab5 u2.cpp
// Uppgift 2 - Binärsökning i en C-array
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include <iostream>     // cout endl
#include <random>       // random
#include <iomanip>    // setw()
using namespace std;   //cout cin
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// main() börjar
//------------------------------------------------------------------------------

int main(){
	setlocale(LC_ALL, ""); //ÅÄÖ

	const size_t SIZE = 10;    //storlek på array
	int arr[SIZE],
		startNum,
		midNum,
		endNum,
		i,
		n,
		myNum;

	cout << endl << "Skriv in 10 tal i vilken ordning du vill: ";

	for (i = 0; i < SIZE; i++) {
		cin >> arr[i];
	}


	//Sortera arrayen stigande med bubble sort

	for (size_t pass = 0; pass < SIZE - 1; pass++)		//Stega igenom arrayen SIZE-1 ggr   
		for (size_t i = 0; i < SIZE - 1; i++)		    // Jämför elementen parvis     
			if (arr[i] > arr[i + 1])				   // Byt plats om fel ordning     
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
			}

	startNum = 0;
	endNum = SIZE - 1;

	cout << "Vilket av de 10 tal du skrev in vill du söka efter: ";
	cin >> myNum;

	while (startNum <= endNum) {
		midNum = (startNum + endNum) / 2;

		if (arr[midNum] == myNum)
		{
			for (size_t i = 0; i < SIZE; i++)
			{
				cout << setw(4) << arr[i];
			}
			cout << endl;
			cout << "Talet " << myNum << " finns på plats " << (midNum + 1) << endl;
			exit(0);
		}

		else if (myNum > arr[midNum])
		{
			startNum = midNum + 1;
		}

		else if (myNum < arr[midNum])
		{
			endNum = midNum - 1;
		}
	}

	cout << "Talet " << myNum << " hittades inte." << endl;

	return 0;
}