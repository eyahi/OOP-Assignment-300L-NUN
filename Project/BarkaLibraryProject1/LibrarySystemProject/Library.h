//Library.h
#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <vector>
#include "BookItem.h"
#include <unordered_map>
#include "PatronRecord.h"
using namespace std;

class Library {
private:
	vector<BookItem> Books;
	std::unordered_map<int, PatronRecord> patronRecord;
public:
	void addBooks(BookItem book) {
		Books.push_back(book);
	}

	void addPatrons(int libraryCardNumber, PatronRecord records) {
		patronRecord[libraryCardNumber] = records;
	}

	bool borrowBook(string libraryCardNumber, string isbn) {
		return 0;
	}

	bool returnBook(string libraryCardNumber, string isbn)
	{
		return 0;
	}
};
#endif // LIBRARY_H