// PatronRecord.cpp
#include "PatronRecord.h"

void PatronRecord::addCheckedOutBook(const BookItem& book) {
    checkedOutBooks.push_back(book);
}

void PatronRecord::removeCheckedOutBook(const BookItem& book) {
    // Find and remove the book from the checkedOutBooks vector
    auto it = std::find(checkedOutBooks.begin(), checkedOutBooks.end(), book);
    if (it != checkedOutBooks.end()) {
        checkedOutBooks.erase(it);
    }
}

std::vector<BookItem> PatronRecord::getCheckedOutBooks() const {
    return checkedOutBooks;
}
