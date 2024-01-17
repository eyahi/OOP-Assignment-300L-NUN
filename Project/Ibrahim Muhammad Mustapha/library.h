
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book_item.h"
#include "patron.h"
#include "patron_record.h"

class Library {
public:
    
    void addBook(const BookItem& book);
    void addPatron(const Patron& patron);
    void borrowBook(Patron& patron, BookItem& book);
    void returnBook(Patron& patron, BookItem& book);

    const std::vector<BookItem>& getBooks() const;
    const PatronRecord& getPatronRecord(const Patron& patron) const;

private:
    std::vector<BookItem> books;
    std::vector<PatronRecord> patronRecords;
};


inline bool operator==(const Patron& lhs, const Patron& rhs) {
    
}

#endif 