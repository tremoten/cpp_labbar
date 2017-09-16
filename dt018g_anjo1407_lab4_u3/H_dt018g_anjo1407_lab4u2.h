//-----------------------------------------------------------------------------
// Lab4 Uppgift 3
// Uppgift 3 - Menysystem - RingPling
// Anna-Malin Joshammar
//-----------------------------------------------------------------------------
#include <iostream>     // cout endl
#include <sstream>		// iss
#include <iomanip>     // setw
#include <string>      // string-klassen
#include <vector>	   // vector
using namespace std;   //cout cin
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
// Funktionsprototyp
//------------------------------------------------------------------------------
#ifndef H_dt018g_anjo1407_lab4u2H
#define H_dt018g_anjo1407_lab4u2H
void teleTaxa(); 
bool isTimeFormatValid(vector<int> time, string input);								//kontroll att angiven tid �r korrekt
bool startStoppTime(string start, string stopp);									//kontroll att sluttid ska va st�rre �n starttid
char menyVal();																		//menyn, vill du g�ra igen?
int callTimeInMinute(string time);													//omvandlar start och sluttid till int
vector<int> splitString(string str);												//skapar en vector 
bool isTimeCorrect(vector<int> startTime, vector<int> stoppTime);					//kontroll att stopptiden �r efter starttiden 
double phoneCharge(string start, string stopp);										//R�kna ut kostnaden f�r samtalet	
#endif