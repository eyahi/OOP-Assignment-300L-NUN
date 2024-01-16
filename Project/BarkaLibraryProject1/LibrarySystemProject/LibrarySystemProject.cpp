// LibrarySystemProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include "BookItem.h"
#include "patron.h"
#include "PatronRecord.h"
#include "Library.h"
#include "LibraryItem.h"
#include "Book.h"
#include <iostream>
using namespace std;


int main() {
	//implementatin functions for patron record header file
	// 
	//Book.h Objects
	Book book1 = Book("The Ocean", "Dr. Manhattan", "987654321");
	Book book2 = Book("The Wind", "Sam Bright", "123456789");

	//Patron.h Objects
	Patron patron1 = Patron("Dr. Emmanual", "15-01-2024");
	Patron patron2 = Patron("Micheal Oliver", "700");

	//LibraryItem.h Objects
	LibraryItem libItem1 = LibraryItem("The trenches", false, "20-01-2024");
	LibraryItem libItem2 = LibraryItem("The Ocean", false, "15-01-2024");

	//BookItem Objects
	BookItem bookItem1 = BookItem("Intro To OOP", false, "15-01-2024", "Barka Peter", "211203012");
	BookItem bookItem2 = BookItem("Life In Tinubu Era",false,"22-01-2024", "Sapa Sr.", "024681359");
	BookItem bookItem3 = BookItem("No Gree For Anybody", false, "16-01-2024", "Shege Sr.", "224466880");
	
	Library theLibrary;

	theLibrary.addBooks(bookItem1);
	theLibrary.addBooks(bookItem2);

	PatronRecord pRecord1;
	theLibrary.addPatrons(700, pRecord1);

	string duedate = "15-01-2024";
	//
	//
	/*if (bookItem1.getDueDate() != duedate) {
		bkIt1->checkOut();
	}
	else {
		bkIt1->returnItem();
	}
	if (bookItem2.getDueDate() != duedate) {
		bkIt2->checkOut();
	}
	else {
		bkIt2->returnItem();
	} */

	// Borrow a book
	if (theLibrary.borrowBook("15-01-2024", "211203012")) {
		cout << "Book borrowed successfully." << endl;
	}
	else {
		cout << "Book borrowing failed." << endl;
	}

	// Return a book
	if (theLibrary.returnBook("700", "123456789")) {
		cout << "Book returned successfully." << endl;
	}
	else {
		cout << "Book return failed." << endl;
	}

	return 0;

}
	

	

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
