// Library.cpp
#include "LibrarySystem.h"
#include <iostream>

void Library::addBook(const BookItem& book) {
    books.push_back(book);
}

void Library::addPatron(const Patron& patron) {
    patrons.push_back(patron);
}

void Library::borrowBook(const Patron& patron, const BookItem& book) {
    // Check if the book is available
    auto bookIt = std::find_if(books.begin(), books.end(),
        [book](const BookItem& b) { return b.getTitle() == book.getTitle() && !b.getIsCheckedOut(); });

    if (bookIt != books.end()) {
        // Book is available, check out the book and update patron records
        bookIt->checkOut();
        PatronRecord record;
        record.checkedOutBooks.push_back(*bookIt);
        auto patronIt = std::find_if(patronRecords.begin(), patronRecords.end(),
            [patron](const PatronRecord& pr) { return pr.patron.getLibraryCardNumber() == patron.getLibraryCardNumber(); });

        if (patronIt != patronRecords.end()) {
            // Patron already has records, update the record
            patronIt->checkedOutBooks.push_back(*bookIt);
        } else {
            // Create a new record for the patron
            PatronRecord newRecord;
            newRecord.patron = patron;
            newRecord.checkedOutBooks.push_back(*bookIt);
            patronRecords.push_back(newRecord);
        }

        std::cout << "Book '" << book.getTitle() << "' borrowed by Patron '" << patron.getName() << "'." << std::endl;
    } else {
        std::cout << "Book '" << book.getTitle() << "' is not available for borrowing." << std::endl;
    }
}

void Library::returnBook(const Patron& patron, const BookItem& book) {
    // Find the patron's record
    auto patronIt = std::find_if(patronRecords.begin(), patronRecords.end(),
        [patron](const PatronRecord& pr) { return pr.patron.getLibraryCardNumber() == patron.getLibraryCardNumber(); });

    if (patronIt != patronRecords.end()) {
        // Find the book in the patron's checked-out books
        auto bookIt = std::find_if(patronIt->checkedOutBooks.begin(), patronIt->checkedOutBooks.end(),
            [book](const BookItem& b) { return b.getTitle() == book.getTitle(); });

        if (bookIt != patronIt->checkedOutBooks.end()) {
            // Book found in patron's checked-out books, return the book
            bookIt->returnItem();
            patronIt->checkedOutBooks.erase(bookIt);
            std::cout << "Book '" << book.getTitle() << "' returned by Patron '" << patron.getName() << "'." << std::endl;
        } else {
            std::cout << "Patron '" << patron.getName() << "' does not have book '" << book.getTitle() << "' checked out." << std::endl;
        }
    } else {
        std::cout << "Patron '" << patron.getName() << "' does not have any books checked out." << std::endl;
    }
}

void Library::displayLibraryStatus() const {
    std::cout << "Library Status:" << std::endl;

    // Display available books
    std::cout << "\nAvailable Books:\n";
    for (const auto& book : books) {
        if (!book.getIsCheckedOut()) {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
        }
    }

    // Display checked-out books
    std::cout << "\nChecked-out Books:\n";
    for (const auto& record : patronRecords) {
        for (const auto& book : record.checkedOutBooks) {
            std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << " (Checked out by Patron: " << record.patron.getName() << ")\n";
        }
    }
    std::cout << std::endl;
}
