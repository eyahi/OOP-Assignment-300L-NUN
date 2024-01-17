
#ifndef PATRON_RECORD_H
#define PATRON_RECORD_H

#include "patron.h"
#include "book_item.h"
#include <vector>

class PatronRecord {
private:
    Patron patron;
    std::vector<BookItem> checkedOutBooks;

public:
    PatronRecord(const Patron& patron);

    
    Patron getPatron() const;
    std::string getLibraryCardNumber() const;  
    void setPatron(const Patron& patron);

    
    void addBook(const BookItem& book);
    void removeBook(const BookItem& book);
    std::vector<BookItem> getCheckedOutBooks() const;

    
    bool isEqual(const BookItem& book1, const BookItem& book2);
};

#endif
