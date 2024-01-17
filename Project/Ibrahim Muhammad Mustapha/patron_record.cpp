// patron_record.cpp
#include <algorithm>
#include "patron_record.h"

void PatronRecord::addBook(const BookItem& book) {
    checkedOutBooks.push_back(book);
}
void PatronRecord::removeBook(const BookItem& book) {
    checkedOutBooks.erase(
        std::remove_if(checkedOutBooks.begin(), checkedOutBooks.end(),
                       [this, book](const BookItem& b) { return isEqual(b, book); }),
        checkedOutBooks.end());
}

std::vector<BookItem> PatronRecord::getCheckedOutBooks() const {
    return checkedOutBooks;
}

bool PatronRecord::isEqual(const BookItem& book1, const BookItem& book2) {
    return book1.getISBN() == book2.getISBN();
}