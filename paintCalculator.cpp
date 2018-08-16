// chap 2 C++.cpp : Defines the entry point for the console application.
// Jack Sims (May 2, 2018)

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double width = 0.0;
	double height = 0.0;
	double area = 0.0;
	double paintCost = 0.0;

	cout << "Enter the width of the wall in feet: ";
	cin >> width;

	cout << "Enter the height of the wall in fee: ";
	cin >> height; // FIXME Get height as user input (Fixed)

				   // Calculate and output area of wall
	area = height * width;
	cout << "Total area to paint in square feet: "
		<< area
		<< endl;

	/* FIXME */ cout << "Total number of gallons of paint needed: " << ceil(area / 350) << endl;

	paintCost = ceil(area / 350) * 27;

	/* FIXME */ cout << "Total cost of paint in dollars: " << paintCost << endl;

	/* FIXME */ cout << "Total time to paint in hours: " << area / 100 << endl;

	return 0;
}

