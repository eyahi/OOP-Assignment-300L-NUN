//library 
#ifndef LIBRARY_H
#define LIBRARY_H

#include iostream
#include <vector>
#include "book_item.h"
#include "patron.h"
#include "patron_record.h"
class Library {
private:
    std::vector<BookItem> books;
    std::vector<Patron> patrons;
    std::vector<PatronRecord> patronRecords;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
        books.emplace_back(title, author, isbn);
    }

    void addPatron(const std::string& name, int libraryCardNumber) {
        patrons.emplace_back(name, libraryCardNumber);
        patronRecords.emplace_back();
    }

    void borrowBook(int patronIndex, int bookIndex) {
        if (patronIndex < 0 || patronIndex >= patrons.size() || bookIndex < 0 || bookIndex >= books.size()) {
            std::cout << "Invalid patron or book index.\n";
            return;
        }

        BookItem& book = books[bookIndex];
        PatronRecord& patronRecord = patronRecords[patronIndex];
 if (!book.getIsCheckedOut()) {
            book.checkOut();
            patronRecord.addBook(&book);
            std::cout << "Book '" << book.getTitle() << "' has been borrowed by " << patrons[patronIndex].getName() << ".\n";
        } else {
            std::cout << "Book '" << book.getTitle() << "' is already checked out.\n";
        }
    }

    void returnBook(int patronIndex, int bookIndex) {
        if (patronIndex < 0 || patronIndex >= patrons.size() || bookIndex < 0 || bookIndex >= books.size()) {
            std::cout << "Invalid patron or book index.\n";
            return;
        }

        BookItem& book = books[bookIndex];
        PatronRecord& patronRecord = patronRecords[patronIndex];

        if (book.getIsCheckedOut()) {
            book.returnItem();
            patronRecord.removeBook(&book);
            std::cout << "Book '" << book.getTitle() << "' has been returned by " << patrons[patronIndex].getName() << ".\n";
        } else {
            std::cout << "Book '" << book.getTitle() << "' is not checked out.\n";
        }
    }

    void displayPatronCheckedOutBooks(int patronIndex) const {
        if (patronIndex < 0 || patronIndex >= patrons.size()) {
            std::cout << "Invalid patron index.\n";
             return;
        }

        patronRecords[patronIndex].displayCheckedOutBooks();
        }

};
#endif