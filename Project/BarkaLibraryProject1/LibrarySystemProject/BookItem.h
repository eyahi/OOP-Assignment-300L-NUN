// book_item.h
#pragma once
#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H
#include <iostream>
#include "LibraryItem.h"
using namespace std;

class BookItem : public LibraryItem {
private:
	string Author;
	string Isbn;
public:
	// Setters, getters, and constructor
	void setAuthor(string author) {
		Author = author;
	}

	string getAuthor() {
		return Author;
	}

	void setIsbn(string isbn) {
		Isbn = isbn;
	}

	string getIsbn() {
		return Isbn;
	}

	BookItem(string title, bool isCheckedOut, string dueDate, string author, string isbn)
		 : LibraryItem(title, isCheckedOut, dueDate)
	{
		Author = author;
		Isbn = isbn;
	}

	// Override checkOut() for books
	void checkOut() {
		// Perform any specific actions needed for checking out a book
		cout << "Checking out a book: " << getTitle() << " by " << Author << endl;
	}

	// Override returnItem() for books
	void returnItem() {
		// Perform any specific actions needed for returning a book
		cout << "Returning a book: " << getTitle() << " by " << Author << endl;
	}
};
#endif // BOOK_ITEM_H