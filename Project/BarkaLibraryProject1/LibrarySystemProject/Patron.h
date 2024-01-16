//patron.h
#pragma once
#ifndef PATRON_H
#define PATRON_H
using namespace std;

class Patron {
private:
	string Name;
	string libraryCardNumber;
public:
	// Setters, getters, and constructor 
	void setName(string name) {
		Name = name;
	}

	string getName() {
		return Name;
	}

	void setLibraryCardNumber(string LibraryCardNumber) {
		libraryCardNumber = LibraryCardNumber;
	}

	string getLibraryCardNumber() {
		return libraryCardNumber;
	}

	//Constructor
	Patron(string name, string LibraryCardNumber)
	{
		Name = name;
		libraryCardNumber = LibraryCardNumber;
	};

};
#endif // PATRON_H