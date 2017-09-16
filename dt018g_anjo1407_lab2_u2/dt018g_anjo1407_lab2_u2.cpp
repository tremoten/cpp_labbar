//------------------------------------------------------------------- 
// Lab2 u2.cpp 
// Uppgift 2 - Uppgift 1 ASCII tabell
// Anna-Malin Joshammar
//------------------------------------------------------------------- 
#include <iostream>		// cout endl
#include <iomanip>      // setw
using namespace std;	//cout cin 
//-------------------------------------------------------------------

int main(){

	int asciiVal = 32;  //start at 32
	int tempAsciiVal = asciiVal;

	cout << endl;
	cout << "ASCII-Tabell" << endl;
	for (int row = 0; row < 32; row++)  // 32 rows
	{
		for (int col = 0; col < 7; col++) // 7 colums
		{
			cout << right << setw(3) << tempAsciiVal << " ";   // 
			cout << left << setw(4) << (char)tempAsciiVal;

			tempAsciiVal += 32;;                     // skip 32 in every column
		}
		cout << endl;
		asciiVal++;
		tempAsciiVal = asciiVal;
	}


	//Alt 2 


	/*
	
	   int tecken = 32; // ++ after each r loop
    int t; // changable
 
    cout << endl <<  "**********************  ASCII-tabell  *********************" << endl << endl;
 
    for (int r = 0; r < 14; r++) {  //  rows
        t = tecken;
 
        for (int c = 0; c < 7; c++) {  //  columns
            if (t > 127)
            {
                break;
            }
            cout << left << setw(4) << t << left << setw(5) << (char)t;
            t += 14;
 
        }
 
        tecken ++;
        cout << endl;
    }              
	
	
	
	
	
	*/


	/* ref: http://www.sweclockers.com/forum/trad/481933-c-program-for-ascii-tabell
	for (int i = 32; i <= 255; i++)
	{
	cout << i << " " << char(i) << "\t";
	}
	------------------------------------------------------------------------------*/
	return 0;

}