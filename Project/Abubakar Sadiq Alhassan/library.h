
#include <iostream>
#include <string>
#include <vector>
using namespace std;


#ifndef LIBRARY_H 
#define LIBRARY_H
#include "book_item.h"
#include "patron.h"
#include "patron_record.h"
class Library { 
 private:
 vector<BookItem> books; 
 vector<Patron> patrons;
 vector<PatronRecord> patronRecords;
 public:
    void addBook(const BookItem book);
    void addPatron(const Patron patron);
    void borrowBook( PatronRecord patron, const BookItem book);
    void returnBook( PatronRecord patron, const BookItem book);
    const vector<BookItem> getBooks() const;
    PatronRecord getPatronRecord(const Patron& patron) const;

};
#endif 
