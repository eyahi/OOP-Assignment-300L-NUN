// library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book_item.h"
#include "patron.h"
#include "patron_record.h"

class Library {
public:
    // Other member functions
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

// Add this function definition to the library.h header file
inline bool operator==(const Patron& lhs, const Patron& rhs) {
    // Implement the comparison logic based on the Patron class's data members
    // For example, if the Patron class has a data member named 'id', you can do:
    // return lhs.id == rhs.id;
}

#endif // LIBRARY_H