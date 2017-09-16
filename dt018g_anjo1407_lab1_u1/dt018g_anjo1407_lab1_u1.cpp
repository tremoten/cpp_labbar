//------------------------------------------------------------------- 
// Lab3 u1.cpp 
// Uppgift 1 - Byt ut ord i en längre sträng
// Anna-Malin Joshammar
//------------------------------------------------------------------- 
#include <iostream>		// cout endl
#include <iomanip>      // setw
#include <string>      // string-klassen
#include <sstream>       //istringstream os
using namespace std;	//cout cin 
//-------------------------------------------------------------------

int main(){
	setlocale(LC_ALL, ""); //ÅÄÖ
	//variabler 

	string const inText1 = "Foten är en kroppsdel som förekommer mycket i våra uttryck.";
	string const inText2 = "På stående fot betyder omedelbart, utan förberedelse.";
	string const inText3 = "Försätta på fri fot betyder att ge någon friheten.";
	string const inText4 = "Sätta foten i munnen betyder att göra bort sig.";
	string const inText5 = "Få om bakfoten betyder att missuppfatta något.";
	string const inText6 = "Skrapa med foten betyder att visa sig underdånig eller ödmjuk.";
	string const inText7 = "Stryka på foten betyder att tvingas ge upp.";
	string const inText8 = "Leva på stor fot betyder att föra ett dyrbart eller slösaktigt leverne.";
	string const inText9 = "Varför fick du foten???";

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
\x86 = å
\x84 = ä
\x94 = ö

*/


/*
string replaceText(string text, string search, string replace){
string::size_type idx = 0;
while ((idx = text.find(search)) != string::npos) // Skriv över 'fot' med hand
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