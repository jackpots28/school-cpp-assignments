// assign6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

const double pi = 3.14159265;
const double grav = 9.8; // Earth gravity (m/s^2)
// Moved local varibles from main() to global to that PrintUpdate() / Trajectory() could use them
double t = 1.0;
double fowlX = 0.0;
double fowlY = 0.0;
double beforeSwineX = 0.0;

						 // Given time, angle, velocity, and gravity
						 // Update x and y values
void Trajectory(double t, double a, double v,
	double& x, double& y) {
	x = v * t * cos(a);
	y = v * t * sin(a) - 0.5 * grav * t * t;
	return;
}

// convert degree value to radians
double DegToRad(double deg) {
	return ((deg * pi) / 180.0);
}

// print time, x, and y values
void PrintUpdate(double t, double x, double y) {
	cout << "Time " << fixed << setprecision(0)
		<< setw(3) << t << "   x = " << setw(3)
		<< x << "   y = " << setw(3) << y << endl;
	return;
}


//---prints intro-- "plain and simple"
void printIntro() {
	cout << "Welcome to Upset Fowl!" << endl << "The objective is to hit the Mean Swine by launching an Upset Fowl." << endl;
	return;
}

//---returns referenced parameters after user input
void getUsrInpt(double& x, double& y, double& meanSwine) {
	cout << "The mean swine is " << meanSwine << " meters away." << endl;
	cout << "Enter fowl launch anlge (deg): "; cin >> x;
	x = DegToRad(x);
	cout << "Enter fowl launch velocity (m/s): "; cin >> y;
	return;
}

//--uses referenced varibles 'angle' and 'vel' as input for fowlAngle and fowlVel. uses print and trajectory funtions and returns the last 'x' position
double launchFowl(double& angle, double& vel) {
	do {
		PrintUpdate(t, fowlX, fowlY);
		Trajectory(t, angle, vel, fowlX, fowlY);
		t = t + 1.0;
	} while (fowlY > 0.0);
	PrintUpdate(t, fowlX, fowlY);

	return fowlX;
}

//--tests if landing of launchFowl is within the range of swinex. returns true if within -30 of swinex else returns false
bool DtrminIfHit(double& swineLandX, double& swinePosX) {
	if ((swineLandX <= swinePosX) && (swineLandX >= beforeSwineX)) {
		cout << "Hit'em!!!" << endl;
		return true;
	}
	else {
		cout << "Missed'em..." << endl;
		return false;
	}
}


int main() {
	//double t = 1.0; // time (s)
	//double fowlY = 0.0; // object's height above ground (m)
	double fowlAngle = 0.0; // angle of launch of fowl (rad)
	double fowlVel = 0.0; // velocity of fowl (m/s)
	//double fowlX = 0.0; // object's horiz. dist. from start (m)
	double fowlLandingX = 0.0; // fowl’s horiz. dist. from start (m)
	double swineX = 0.0; // distance to swine (m)
	//double beforeSwineX = 0.0; // distance before swine that is acceptable as a hit (m)
	bool didHitSwine = false; // did hit the swine?

	srand(time(0));
	//swineX = (rand() % 201) + 50;

	//--set swineX to a static value to test against known results
	swineX = 84;

	// FIXME Make into a function called PrintIntro
	// Fixed
	/*
	cout << "Welcome to Upset Fowl!\n";
	cout << "The objective is to hit the Mean Swine by launching an Upset Fowl.\n";
	*/
	printIntro();
	
	for (int i = 0; i <= 4; i++) {
		do {
			getUsrInpt(fowlAngle, fowlVel, swineX);
			fowlLandingX = launchFowl(fowlAngle, fowlVel);
			didHitSwine = DtrminIfHit(fowlLandingX, swineX);
		}while (didHitSwine != true);
		if (didHitSwine = true) {
			i = 4;
		}
	};

	/*Program work for up to the number of loops "4" but has modified values after the 
	  first loop if "true" isnt achieved with the first iteration. Each function works
	  as intended until a loop is used with them.*/


	/*
	// FIXME Make into a function called GetUsrInpt
	// Fixed
	getUsrInpt(fowlAngle, fowlVel, swineX);

	----used to test return of "getUsrInpt" function-----
	cout << "fowlAngle: " << fowlAngle << endl;
	cout << "fowlVel: " << fowlVel << endl;
	-----------------------------------------------------

	// FIXME Make into a function called LaunchFowl
	// Fixed

	do {
	PrintUpdate(t, fowlX, fowlY);
	Trajectory(t, fowlAngle, fowlVel, fowlX, fowlY);
	t=t+1.0;
	} while ( fowlY > 0.0 ); // while above ground
	PrintUpdate(t, fowlX, fowlY);
	
	fowlLandingX = launchFowl(fowlAngle, fowlVel);

	// FIXME Make into a function called DtrmnIfHit
	// Fixed
	didHitSwine = DtrminIfHit(fowlLandingX, swineX);
	*/

    return 0;
}

