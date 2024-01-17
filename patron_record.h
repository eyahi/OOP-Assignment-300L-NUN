#ifndef PATRON_RECORD_H
#define PATRON_RECORD_H

#include <vector>
#include "book_item.h"
#include "patron.h"

class PatronRecord
{
private:
    Patron patron;
    std::vector<BookItem> checkedOutBooks;

public:
    PatronRecord(const Patron &patron)
    {
        this->patron = patron;
    }
    // Functions for managing checked out books
    void addCheckedOutBook(const BookItem &book)
    {
        checkedOutBooks.push_back(book);
    }

    void removeCheckedOutBook(const BookItem &book)
    {
        for (auto it = checkedOutBooks.begin(); it != checkedOutBooks.end(); ++it)
        {
            if (it->getIsbn() == book.getIsbn())
            {
                checkedOutBooks.erase(it);
                break;
            }
        }
    }

    bool hasCheckedOutBook(BookItem book)
    {
        for (auto it = checkedOutBooks.begin(); it != checkedOutBooks.end(); ++it)
        {
            if (it->getIsbn() == book.getIsbn())
            {
                return true;
            }
        }
        return false;
    }

    Patron
    getPatron() const
    {
        return this->patron;
    }
};
#endif // PATRON_RECORD_H