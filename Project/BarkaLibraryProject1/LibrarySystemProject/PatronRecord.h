// patron_record.h
#pragma once
#ifndef PATRON_RECORD_H
#define PATRON_RECORD_H
#include <vector>
#include "BookItem.h"
using namespace std;

class PatronRecord  {
private:
	vector<BookItem>checkedOutBooks;
public:
    
	void addToCheckedOutBook(BookItem& book) {
		checkedOutBooks.push_back(book);
	}

	bool removeCheckedOutBook(string& isbn) {
		for (auto it = checkedOutBooks.begin(); it != checkedOutBooks.end(); ++it) {
			if (it->getIsbn() == isbn) {
				checkedOutBooks.erase(it);
				return true;
			}
		}
		return false;
	}
	
};
#endif // PATRON_RECORD_H