// assignChap5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<char> normalV(26);
	vector<char> cipherV(26);
	string toDec = "";
	string beenDec = "";

	int a = 0;
	normalV.at(a) = 'a'; cipherV.at(a) = '!'; ++a;
	normalV.at(a) = 'b'; cipherV.at(a) = '^'; ++a;
	normalV.at(a) = 'c'; cipherV.at(a) = '&'; ++a;
	normalV.at(a) = 'd'; cipherV.at(a) = '*'; ++a;
	normalV.at(a) = 'e'; cipherV.at(a) = '@'; ++a;
	normalV.at(a) = 'f'; cipherV.at(a) = '('; ++a;
	normalV.at(a) = 'g'; cipherV.at(a) = ')'; ++a;
	normalV.at(a) = 'h'; cipherV.at(a) = '-'; ++a;
	normalV.at(a) = 'i'; cipherV.at(a) = '#'; ++a;
	normalV.at(a) = 'j'; cipherV.at(a) = '_'; ++a;
	normalV.at(a) = 'k'; cipherV.at(a) = '='; ++a;
	normalV.at(a) = 'l'; cipherV.at(a) = '+'; ++a;
	normalV.at(a) = 'm'; cipherV.at(a) = '['; ++a;
	normalV.at(a) = 'n'; cipherV.at(a) = '{'; ++a;
	normalV.at(a) = 'o'; cipherV.at(a) = '$'; ++a;
	normalV.at(a) = 'p'; cipherV.at(a) = ']'; ++a;
	normalV.at(a) = 'q'; cipherV.at(a) = '}'; ++a;
	normalV.at(a) = 'r'; cipherV.at(a) = ';'; ++a;
	normalV.at(a) = 's'; cipherV.at(a) = ':'; ++a;
	normalV.at(a) = 't'; cipherV.at(a) = ','; ++a;
	normalV.at(a) = 'u'; cipherV.at(a) = '%'; ++a;
	normalV.at(a) = 'v'; cipherV.at(a) = '<'; ++a;
	normalV.at(a) = 'w'; cipherV.at(a) = '.'; ++a;
	normalV.at(a) = 'x'; cipherV.at(a) = '>'; ++a;
	normalV.at(a) = 'y'; cipherV.at(a) = '/'; ++a;
	normalV.at(a) = 'z'; cipherV.at(a) = '?'; ++a;

	/*----------------------------------------------------------------------------------------------------------------------------
	I attempted several times to use a loop and iterations in place of multiple if/elseif statements but none of my methods worked.
	Feedback would be nice; to somehow clarify how that method is implemented.
	-------------------------------------------------------------------------*/

	// Get secret message
	do {
		cout << "Enter a secret message: ";
		getline(cin, toDec);
	} while (toDec.length() == 0);

	beenDec = toDec;

	// Decrypt secret message
	for (int i = 0; i < toDec.length(); i++) {
		if (toDec.at(i) == cipherV.at(0)) {
			beenDec.at(i) = normalV.at(0);
		}
		else if(toDec.at(i) == cipherV.at(1))
		{
			beenDec.at(i) = normalV.at(1);
		}
		else if (toDec.at(i) == cipherV.at(2))
		{
			beenDec.at(i) = normalV.at(2);
		}
		else if (toDec.at(i) == cipherV.at(3))
		{
			beenDec.at(i) = normalV.at(3);
		}
		else if (toDec.at(i) == cipherV.at(4))
		{
			beenDec.at(i) = normalV.at(4);
		}
		else if (toDec.at(i) == cipherV.at(5))
		{
			beenDec.at(i) = normalV.at(5);
		}
		else if (toDec.at(i) == cipherV.at(6))
		{
			beenDec.at(i) = normalV.at(6);
		}
		else if (toDec.at(i) == cipherV.at(7))
		{
			beenDec.at(i) = normalV.at(7);
		}
		else if (toDec.at(i) == cipherV.at(8))
		{
			beenDec.at(i) = normalV.at(8);
		}
		else if (toDec.at(i) == cipherV.at(9))
		{
			beenDec.at(i) = normalV.at(9);
		}
		else if (toDec.at(i) == cipherV.at(10))
		{
			beenDec.at(i) = normalV.at(10);
		}
		else if (toDec.at(i) == cipherV.at(11))
		{
			beenDec.at(i) = normalV.at(11);
		}
		else if (toDec.at(i) == cipherV.at(12))
		{
			beenDec.at(i) = normalV.at(12);
		}
		else if (toDec.at(i) == cipherV.at(13))
		{
			beenDec.at(i) = normalV.at(13);
		}
		else if (toDec.at(i) == cipherV.at(14))
		{
			beenDec.at(i) = normalV.at(14);
		}
		else if (toDec.at(i) == cipherV.at(15))
		{
			beenDec.at(i) = normalV.at(15);
		}
		else if (toDec.at(i) == cipherV.at(16))
		{
			beenDec.at(i) = normalV.at(16);
		}
		else if (toDec.at(i) == cipherV.at(17))
		{
			beenDec.at(i) = normalV.at(17);
		}
		else if (toDec.at(i) == cipherV.at(18))
		{
			beenDec.at(i) = normalV.at(18);
		}
		else if (toDec.at(i) == cipherV.at(19))
		{
			beenDec.at(i) = normalV.at(19);
		}
		else if (toDec.at(i) == cipherV.at(20))
		{
			beenDec.at(i) = normalV.at(20);
		}
		else if (toDec.at(i) == cipherV.at(21))
		{
			beenDec.at(i) = normalV.at(21);
		}
		else if (toDec.at(i) == cipherV.at(22))
		{
			beenDec.at(i) = normalV.at(22);
		}
		else if (toDec.at(i) == cipherV.at(23))
		{
			beenDec.at(i) = normalV.at(23);
		}
		else if (toDec.at(i) == cipherV.at(24))
		{
			beenDec.at(i) = normalV.at(24);
		}
		else if (toDec.at(i) == cipherV.at(25))
		{
			beenDec.at(i) = normalV.at(25);
		}
		else if (toDec.at(i) == cipherV.at(26))
		{
			beenDec.at(i) = normalV.at(26);
		}
		else
		{
			beenDec.at(i) = toDec.at(i);
		}
	}

cout << "Decrypted message: " << beenDec << endl;

return 0;
}

