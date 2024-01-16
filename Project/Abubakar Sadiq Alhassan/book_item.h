
#include <iostream>
#include <string>
#include <vector>
using namespace std;


#ifndef BOOK_ITEM_H 
#define BOOK_ITEM_H 
#include "library_item.h"
class BookItem : public LibraryItem { 
 private:
  string author; 
  int isbn;
 public:
 BookItem(string title, string dueDate, string author,int isbn);
 void getB() const;
 void setauthor(const string newauthor);
 void setisbn(const int newisbn);
 void returnItem() override;
 void checkout() override;
 bool operator==(const BookItem& other) const; 
};
#endif 