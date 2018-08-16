// chap4Assign.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include <iostream>

using namespace std;

int main() {
	int trunkWidth;
	int trunkHeight;
	int leavesWidth;
	double x{ 0.0 };

	cout << "Enther trunk height: ";
	cin >> trunkHeight;

	cout << "Enther trunk width: ";
	cin >> trunkWidth;

	cout << "Enther leaves width: ";
	cin >> leavesWidth;
	
	

	for (int c = 1; c <= leavesWidth; c = c + 2) {
		for (int d = 0; d < (leavesWidth - c) / 2; ++d) {
			cout << " ";
		}
		for (int e = 0; e < c; e++) {
			cout << "*";
		}
		cout << endl;
	}

	if (leavesWidth % trunkWidth > 1)
		x = 0.125;
	else
		x = 0.25;
	
	for (int i = 0; i < trunkHeight; ++i) {
		for (double a = 0; a < leavesWidth * x; ++a) {
			cout << " ";
		}
		for (int b = 0; b < trunkWidth; ++b) {
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;
}

