#include "book.h"

Book::Book( string title, string author, int isbn)
    : title(title), author(author), isbn(isbn) {}

void Book::getb() const{
   cout<<"Title: "<<title<<"\nAuthor: "<<author<<"\nISBN: "<<isbn<<'\n';   
}
void Book::settitle(const string newtitle) {
    title = newtitle;
}

void Book::setauthor(const string newauthor) {
    author = newauthor;
}

void Book::setisbn(int newisbn) {
    isbn = newisbn;
}