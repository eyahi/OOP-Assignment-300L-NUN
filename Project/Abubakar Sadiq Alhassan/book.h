#include <iostream>
#include <string>
using namespace std;

// book.h
#ifndef BOOK_H 
#define BOOK_H
class Book { 
 private:
    string title;
    string author;
    int isbn;
 public:
  Book( string title, string author, int isbn);
    void getb() const;
   
    void settitle(const string newtitle );
    void setauthor(const string newauthor);
    void setisbn(int newisbn);
};
#endif // BOOK_H