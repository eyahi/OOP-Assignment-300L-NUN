#include "library.h"
#include <iostream>
#include <algorithm> 
void Library::addBook(const BookItem book) {
    books.push_back(book);
}

void Library::addPatron(const Patron patron) {
    patrons.push_back(patron);
}

void Library::borrowBook( PatronRecord patron, const BookItem book) {
      
        patron.addcheckedOutBooks(book);
}
void Library::returnBook( PatronRecord patron, const BookItem book) {
      
        patron.removecheckedOutBooks(book);
}

const std::vector<BookItem> Library::getBooks() const {
    return books;
}
PatronRecord Library::getPatronRecord(const Patron& patron) const {
                               return patron;
}

