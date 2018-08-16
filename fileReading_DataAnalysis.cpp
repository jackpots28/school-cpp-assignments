// assignChap7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "person.h"
#include "person.cpp"
using namespace std;

string peopleData = "dev_people.txt";

// class 'person' moved to seperate file "person.h"
/*
// Define a Person class, including age, gender, and yearlyIncome.
class Person {
public:
	Person();
	void Print();
	void SetData(int a, string gen, int income);

	// FIXME Also set gender and yearly income
	string getGender();
	int getYearlyI();
	int GetAge();
private:
	int age;
	string gender;
	int yearlyIncome;
};
*/

// all imps of 'person' moved to seperate file
/*
// Constructor for the Person class.
Person::Person() {
	age = 0;
	gender = "default";
	yearlyIncome = 0;
	return;
}

// Print the Person class.
void Person::Print() {
	cout << "Age = " << this->age
		<< ", gender = " << this->gender
		<< ", yearly income = " << this->yearlyIncome
		<< endl;
	return;
}

// Set the age, gender, and yearlyIncome of a Person.
void Person::SetData(int a, string gen, int income) {   // FIXME Also set gender and yearly income
	this->age = a;
	this->gender = gen;
	this->yearlyIncome = income;
	return;
}

// Get the age of a Person.
int Person::GetAge() {
	return this->age;
}

string Person::getGender() {
	return this->gender;
}

int Person::getYearlyI() {
	return this->yearlyIncome;
}
*/

// Get a filename from program arguments, then make a Person for each line in the file.
bool ReadPeopleFromFile(vector<Person> &people) {
	Person tmpPrsn;
	ifstream inFS;
	int tmpAge = 0;
	string tmpGender = "";
	int tmpYI = 0;
	
	// Original code for reading the file via cmd args
	/*
	if (argc != 2) {
		cout << "\nUsage: [EXECUTABLE FILE] [TEXT DATA FILE], e.g. myprog.exe dev_people.txt" << endl;
		return true; // indicates error
	}
	*/

	cout << "Opening file " << "dev_people.txt" << ".\n";
	inFS.open(peopleData.c_str()); // Try to open file
	if (!inFS.is_open()) {
		cout << "Could not open file " << "dev_people.txt" << ".\n";
		return true; // indicates error
	}

	while (!inFS.eof()) {
		inFS >> tmpAge;
		inFS >> tmpGender;
		inFS >> tmpYI;
		tmpPrsn.SetData(tmpAge, tmpGender, tmpYI); // Fixed FIXME Also set gender and yearly income
		tmpPrsn.Print();
		people.push_back(tmpPrsn);
	}
	inFS.close();
	cout << "Finished reading file." << endl;

	return false; // indicates no error
}

// Ask user to enter age range.
void GetUserInput(int& ageLowerRange, int& ageUpperRange, string& getGenderIn, int& incomeLowerRng, int& incomeUpperRng) {
	cout << "\nEnter lower range of age: ";
	cin >> ageLowerRange;

	cout << "Enter upper range of age: ";
	cin >> ageUpperRange;

	cout << "Enter gender selection: ";
	cin >> getGenderIn;

	cout << "Enter lower range of income: ";
	cin >> incomeLowerRng;

	cout << "Enter uppper range of income: ";
	cin >> incomeUpperRng;
	return;
}

// overloaded function that only takes age as a para
void GetUserInput(int& ageLowerRange, int& ageUpperRange) {
	cout << "Enter lower range of age: ";
	cin >> ageLowerRange;
	cout << "Enter upper range of age: ";
	cin >> ageUpperRange;
	return;
}

// overloaded function that only takes gender as a para
void GetUserInput(string& getGenderIn) {
	cout << "Enter gender selection: ";
	cin >> getGenderIn;
}

// Return people within the given age range.
vector<Person> GetPeopleInAgeRange(vector<Person> ppl, int lowerRange, int upperRange) {
	unsigned int i = 0;

	vector<Person> pplInAgeRange;
	int age = 0;
	for (i = 0; i < ppl.size(); ++i) {
		age = ppl.at(i).GetAge();
		if ((age >= lowerRange) && (age <= upperRange)) {
			pplInAgeRange.push_back(ppl.at(i));
		}
	}
	return pplInAgeRange;
}


// function to return a vector containing the elements that only match the input gender/any
vector<Person> getPeopleWithSpecGender(vector<Person> ppl, string genderIN) {
	unsigned int i = 0;
	vector<Person> pplWithGender;
	
	string genEquals = "";
	for (i = 0; i < ppl.size(); ++i) {
		genEquals = ppl.at(i).getGender();
		if (genEquals == genderIN) {
			pplWithGender.push_back(ppl.at(i));
		}
		// if 'any' is presented, then both vectors should contain the same number of elements.
		// So setting the return vector to the input vector is a simple else statement.
		else
			pplWithGender = ppl;
	}
	return pplWithGender;
}


vector<Person> getPeopleInIncomeRange(vector<Person> ppl, int upperIncome, int lowerIncome) {
	unsigned int i = 0;

	vector<Person> pplInIncomeRng;
	int income = 0;
	for (i = 0; i < ppl.size(); ++i) {
		income = ppl.at(i).getYearlyI();
		if ((income >= lowerIncome) && (income <= upperIncome)) {
			pplInIncomeRng.push_back(ppl.at(i));
		}
	}
	return pplInIncomeRng;
}


int main() {
	vector<Person> ptntlCstmrs;
	bool hadError = false;
	int ageLowerRange = 0;
	int ageUpperRange = 0;
	string getGenderIn = "";
	int incomeLowerRng = 0;
	int incomeUpperRng = 0;

	hadError = ReadPeopleFromFile(ptntlCstmrs);
	if (hadError) {
		return 1; // indicates error
	}

	GetUserInput(ageLowerRange, ageUpperRange, getGenderIn, incomeLowerRng, incomeUpperRng);

	// overloaded function taking only gender as input
	//GetUserInput(getGenderIn);

	/*
	ptntlCstmrs = GetPeopleInAgeRange(ptntlCstmrs, ageLowerRange, ageUpperRange);
	*/

	//FIXME Addthefunction GetPeopleInIncomeRange
	
	// used to test the new function getPeopleWithSpecGender()
	//ptntlCstmrs = getPeopleWithSpecGender(ptntlCstmrs, getGenderIn);

	ptntlCstmrs = GetPeopleInAgeRange(ptntlCstmrs, ageLowerRange, ageUpperRange);
	ptntlCstmrs = getPeopleWithSpecGender(ptntlCstmrs, getGenderIn);
	ptntlCstmrs = getPeopleInIncomeRange(ptntlCstmrs, incomeLowerRng, incomeUpperRng);

	cout << "\nNumber of potential customers = " << ptntlCstmrs.size() << endl;

	

	return 0;
}

