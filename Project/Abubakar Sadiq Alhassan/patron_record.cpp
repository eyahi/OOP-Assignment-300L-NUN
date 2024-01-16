#include "patron_record.h"
void PatronRecord::addcheckedOutBooks( BookItem book) {
    checkedOutBooks.push_back(book);
}
void PatronRecord::removecheckedOutBooks( BookItem book) {
     auto found= find(checkedOutBooks.begin(),checkedOutBooks.end(),book);
    if (found!= checkedOutBooks.end()){
        checkedOutBooks.erase(found);
    }
}

std::vector<BookItem> PatronRecord::getcheckedOutBooks() {
    return checkedOutBooks;
};

PatronRecord::PatronRecord(const Patron patron) : patron(patron){}