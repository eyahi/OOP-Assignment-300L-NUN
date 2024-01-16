
#include <iostream>
#include <string>
#include <vector>
using namespace std;


// patron_record.h
#ifndef PATRON_RECORD_H 
#define PATRON_RECORD_H 
#include "book_item.h"
#include "patron.h"
class PatronRecord { 
 private:
  vector<BookItem> checkedOutBooks;
   Patron patron;
 public:
  PatronRecord(const Patron patron);
  Patron getPatron() const;
  void setPatron(const Patron patron);


 void addcheckedOutBooks(BookItem book);
 void removecheckedOutBooks( BookItem book);
 vector<BookItem> getcheckedOutBooks();
};
#endif // PATRON_RECORD_H