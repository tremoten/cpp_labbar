//------------------------------------------------------------------- 
// Lab1 upg2.cpp 
// Program med logiska fel och syntaxfel 
// Anna-Malin Joshammar
//------------------------------------------------------------------- 

#include <iostream>	 // cout, cin												//logiskt saknades
using namespace std;															//logiskt saknades
//------------------------------------------------------------------- 

int main()
{
	//Variabler och konstanter    
	double radie, omkrets, area;															//logiskt int   
	const double PI = 3.14;                                                           // syntax & logiskt  const float 3,14

	//Inmatning av en cirkels radie    
	cout << "Ange cirkelns radie: ";
	cin >> radie;																	//syntax cin = radie;

	//Algoritm som beräknar omkrets (2*PI*r) och area (PI*r*r)    
	omkrets = PI * radie * radie;
	area = 2 * PI * radie;														//syntax pi

	//Utskrift av resultatet    
	cout << "En cirkel med radien " << radie << " har";					//syntax " har
	cout << " omkretsen " << omkrets << " och arean " << area << endl; 	//syntax  & logiskt       omkretsen "<< omkrets << " och arean " << area << endl; 

	// Kontrollera x    
	int x = 0;				//tilldela x ett värde
	cin >> x;

	if (x = 100)
	{																	//syntax  {} saknades i if
		cout << "x \x84r lika med 100" << endl;    // ä
	}

	else if (x > 0)													// syntax ; ska bort
	{
		cout << "x \x84r st\x94rre \x84n noll" << endl;  // logiskt ä & ö  & if saknade {} 
	}

	switch (x){
	case 5:
		cout << "x \x84r 5 " << endl;         // logiskt ä & radbrytning saknades
		break;									//break saknades
	case 10:
		cout << "x \x84r 10" << endl;     //logiskt radbrytning saknades
		break;								//break saknades
	default:
		cout << "x \x84r varken 5 eller 10" << endl; //logiskt radbrytning saknades
	}                                                               // syntax saxknades }
	return 0;
}
//End main 