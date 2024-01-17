// patron_record.h
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

    // Getters
    Patron getPatron() const;
    std::string getLibraryCardNumber() const;  // Corrected return type

    // Setters
    void setPatron(const Patron& patron);

    // Other methods
    void addBook(const BookItem& book);
    void removeBook(const BookItem& book);
    std::vector<BookItem> getCheckedOutBooks() const;

    // Predicate function to check if a BookItem is equal to another BookItem
    bool isEqual(const BookItem& book1, const BookItem& book2);
};

#endif // PATRON_RECORD_H
