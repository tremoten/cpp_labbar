#include <iostream>
#include <string>
using namespace std;
int main()
{
	//variabler 
	string userText;
	int rot13 = 13;
	int rot7 = 7;
	int key = rot13; 

	cout << "----------------------------------------------" << endl;
	cout << "Kryptering" << endl << "Skriv den text du vill ha krypterad" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Text: ";
	getline(cin, userText);

	//Krytera text enligt rot7
	string encryptText = userText;

	int counter = 0; 
	for (int i = 0; i < encryptText.length(); i++) 
	{
		if ((counter = ((i % 5) == 0)) && (i != 0) && (key == rot13))  
		{
			key = rot7;
		}
		else if ((counter = ((i % 5) == 0)) && (i != 0) && (key == rot7)) 
		{
			key = rot13;
		}
		encryptText[i] += key;
	}
	
	cout << "Krypterad text: " << encryptText << endl;  

	key = rot13; 

	//Dekryptera text 
	string decryptText = encryptText; // -

	for (int i = 0; i < encryptText.length(); i++)
	{
		if ((counter = ((i % 5) == 0)) && (i != 0) && (key == rot13))
		{
			key = rot7;
		}
		else if ((counter = ((i % 5) == 0)) && (i != 0) && (key == rot7))
		{
			key = rot13;
		}
		encryptText[i] -= key;
	}

	cout << "Dekrypterad text: " << encryptText << endl;

	return 0;
}
