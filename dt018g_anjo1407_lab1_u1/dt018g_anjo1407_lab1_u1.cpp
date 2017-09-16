//------------------------------------------------------------------- 
// Lab3 u1.cpp 
// Uppgift 1 - Byt ut ord i en l�ngre str�ng
// Anna-Malin Joshammar
//------------------------------------------------------------------- 
#include <iostream>		// cout endl
#include <iomanip>      // setw
#include <string>      // string-klassen
#include <sstream>       //istringstream os
using namespace std;	//cout cin 
//-------------------------------------------------------------------

int main(){
	setlocale(LC_ALL, ""); //���
	//variabler 

	string const inText1 = "Foten �r en kroppsdel som f�rekommer mycket i v�ra uttryck.";
	string const inText2 = "P� st�ende fot betyder omedelbart, utan f�rberedelse.";
	string const inText3 = "F�rs�tta p� fri fot betyder att ge n�gon friheten.";
	string const inText4 = "S�tta foten i munnen betyder att g�ra bort sig.";
	string const inText5 = "F� om bakfoten betyder att missuppfatta n�got.";
	string const inText6 = "Skrapa med foten betyder att visa sig underd�nig eller �dmjuk.";
	string const inText7 = "Stryka p� foten betyder att tvingas ge upp.";
	string const inText8 = "Leva p� stor fot betyder att f�ra ett dyrbart eller sl�saktigt leverne.";
	string const inText9 = "Varf�r fick du foten???";

	string str = inText1 + inText2 + inText3 + inText4 + inText5 + inText6 + inText7 + inText8 + inText9;

	//Byt ut Fot med versal.
	while (str.find("Fot") != string::npos)
	{
		str.replace(str.find("Fot"), 3, "Hand");
	}

	//Byt ut fot med gemen.
	while (str.find("fot") != string::npos)
	{
		str.replace(str.find("fot"), 3, "hand");
	}

	string text = "";
	//Skriv ut och radbryt vid punkt.
	for (int i = 0; i <= str.size(); i++)
	{
		char tempChar = str[i];
		text += tempChar;

		if (str[i] == '.')
		{
			cout << text << endl;
			text = "";
		}
	}

	return 0;
}


/*
\x86 = �
\x84 = �
\x94 = �

*/


/*
string replaceText(string text, string search, string replace){
string::size_type idx = 0;
while ((idx = text.find(search)) != string::npos) // Skriv �ver 'fot' med hand
{
if (idx != string::npos)
{
text.replace(idx, search.size(), replace);
}
}
return text;
}

int main(){

string newStr = replaceText(str, "fot", "hand");
newStr = replaceText(newStr, "Fot", "Hand");

cout << newStr;

return 0;
}

*/