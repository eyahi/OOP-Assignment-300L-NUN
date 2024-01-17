#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include "book_item.h"
#include "patron.h"
#include "patron_record.h"

class Library
{
private:
    std::vector<BookItem> books;
    std::vector<Patron> patrons;
    std::vector<PatronRecord> patronRecords;

public:
    // Functions for managing books and patrons, borrowing and returning books
    void addBook(const BookItem &book)
    {
        books.push_back(book);
    }

    void addPatron(const Patron &patron)
    {
        patrons.push_back(patron);
        PatronRecord patronRecord = PatronRecord(patron);
        patronRecords.emplace_back(patronRecord);
    }

    void borrowBook(Patron patron, BookItem book, std::string dueDate)
    {
        if (!book.getIsCheckedOut())
        {
            book.checkOut(dueDate);

            auto it = std::find_if(patronRecords.begin(), patronRecords.end(),
                                   [&patron](const PatronRecord &record)
                                   {
                                       return record.getPatron().getLibraryCardNumber() == patron.getLibraryCardNumber();
                                   });

            if (it != patronRecords.end())
            {
                it->addCheckedOutBook(book);
                std::cout << "Book '" << book.getTitle() << "' has been borrowed by " << patron.getName() << "\n Due Date is: " << dueDate << std::endl;
            }
            else
            {
                std::cerr << "Error: Patron record not found for " << patron.getName() << std::endl;
            }
        }
        else
        {
            std::cout << "Book '" << book.getTitle() << "' is already checked out." << std::endl;
        }
    }

    void returnBook(Patron patron, BookItem book)
    {
        auto it = std::find_if(patronRecords.begin(), patronRecords.end(),
                               [&patron](const PatronRecord &record)
                               {
                                   return record.getPatron().getLibraryCardNumber() == patron.getLibraryCardNumber();
                               });

        if (it != patronRecords.end())
        {
            if (it->hasCheckedOutBook(book))
            {
                book.returnItem();
                it->removeCheckedOutBook(book);
                std::cout << "Book '" << book.getTitle() << "' has been returned by " << patron.getName() << std::endl;
            }
            else
            {
                std::cerr << "Error: " << patron.getName() << " has not borrowed the book '" << book.getTitle() << "'" << std::endl;
            }
        }
        else
        {
            std::cerr << "Error: Patron record not found for " << patron.getName() << std::endl;
        }
    }
};
#endif // LIBRARY_H