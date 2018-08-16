// Step3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string tweet;
	int pos;
	cout << "Enter tweet: ";
	getline(cin, tweet);
	transform(tweet.begin(), tweet.end(), tweet.begin(), toupper); //not required but used to make input uppercase to keep output consistent
	tweet.resize(159);

	// cout << tweet << endl;


	// Output decoded abbreviation from tweet
	pos = tweet.find("LOL");
	if (pos >= 0) {
		tweet.replace(pos, 3, "laugh out loud");
	}

	pos = tweet.find("IRL");
	if (pos >= 0) {
		tweet.replace(pos, 3, "in real life");
	}

	pos = tweet.find("AFK");
	if (pos >= 0) {
		tweet.replace(pos, 3, "away from keyboard");
	}

	pos = tweet.find("NVM");
	if (pos >= 0) {
		tweet.replace(pos, 3, "never mind");
	}

	pos = tweet.find("BFF");
	if (pos >= 0) {
		tweet.replace(pos, 3, "best friends forever");
	}

	pos = tweet.find("FTW");
	if (pos >= 0) {
		tweet.replace(pos, 3, "for the win");
	}

	pos = tweet.find("IIRC");
	if (pos >= 0) {
		tweet.replace(pos, 4, "if I recall correctly");
	}

	pos = tweet.find("TTYL");
	if (pos >= 0) {
		tweet.replace(pos, 4, "talk to you later");
	}

	pos = tweet.find("IMHO");
	if (pos >= 0) {
		tweet.replace(pos, 4, "in my honest opiniion");
	}

	else {
		cout << "Sorry, don't know that one." << endl;
	}

	transform(tweet.begin(), tweet.end(), tweet.begin(), toupper);
	cout << tweet << endl;

	return 0;
}

