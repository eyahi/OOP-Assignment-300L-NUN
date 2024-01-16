// book.cpp
#include "book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title(title), author(author), isbn(isbn) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

std::string Book::getISBN() const {
    return isbn;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Book::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void Book::setISBN(const std::string& newISBN) {
    isbn = newISBN;
}

// patron.cpp
#include "patron.h"

Patron::Patron(const std::string& name, const std::string& libraryCardNumber)
    : name(name), libraryCardNumber(libraryCardNumber) {}

std::string Patron::getName() const {
    return name;
}

std::string Patron::getLibraryCardNumber() const {
    return libraryCardNumber;
}

void Patron::setName(const std::string& newName) {
    name = newName;
}

void Patron::setLibraryCardNumber(const std::string& newCardNumber) {
    libraryCardNumber = newCardNumber;
}

// library_item.cpp
#include "library_item.h"
#include <iostream>

LibraryItem::LibraryItem(const std::string& title)
    : title(title), isCheckedOut(false) {}

std::string LibraryItem::getTitle() const {
    return title;
}

bool LibraryItem::getIsCheckedOut() const {
    return isCheckedOut;
}

std::string LibraryItem::getDueDate() const {
    return dueDate;
}

void LibraryItem::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void LibraryItem::setDueDate(const std::string& newDueDate) {
    dueDate = newDueDate;
}

void LibraryItem::checkOut() {
    if (!isCheckedOut) {
        isCheckedOut = true;
        std::cout << "Item checked out successfully.\n";
    } else {
        std::cout << "Item is already checked out.\n";
    }
}

void LibraryItem::returnItem() {
    if (isCheckedOut) {
        isCheckedOut = false;
        std::cout << "Item returned successfully.\n";
    } else {
        std::cout << "Item is not checked out.\n";
    }
}

// book_item.cpp
#include "book_item.h"

BookItem::BookItem(const std::string& title, const std::string& author, const std::string& isbn)
    : LibraryItem(title), author(author), isbn(isbn) {}

std::string BookItem::getAuthor() const {
    return author;
}

std::string BookItem::getISBN() const {
    return isbn;
}

void BookItem::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void BookItem::setISBN(const std::string& newISBN) {
    isbn = newISBN;
}

void BookItem::checkOut() {
    if (!getIsCheckedOut()) {
        LibraryItem::checkOut();
        // Additional functionality for books, if needed
    } else {
        std::cout << "Book is already checked out.\n";
    }
}

void BookItem::returnItem() {
    if (getIsCheckedOut()) {
        LibraryItem::returnItem();
        // Additional functionality for books, if needed
    } else {
        std::cout << "Book is not checked out.\n";
    }
}

// patron_record.cpp
#include "patron_record.h"

void PatronRecord::addCheckedOutBook(const BookItem& book) {
    checkedOutBooks.push_back(book);
}

void PatronRecord::removeCheckedOutBook(const BookItem& book) {
    // Assuming each book is unique in the record
    auto it = std::find(checkedOutBooks.begin(), checkedOutBooks.end(), book);
    if (it != checkedOutBooks.end()) {
        checkedOutBooks.erase(it);
    }
}

const std::vector<BookItem>& PatronRecord::getCheckedOutBooks() const {
    return checkedOutBooks;
}

// library.cpp
#include "library.h"
#include <algorithm>

void Library::addBook(const BookItem& book) {
    books.push_back(book);
}

void Library::addPatron(const Patron& patron) {
    patrons.push_back(patron);
    patronRecords.push_back(PatronRecord()); // Add an empty record for the new patron
}

void Library::borrowBook(const Patron& patron, const BookItem& book) {
    auto patronIt = std::find(patrons.begin(), patrons.end(), patron);
    auto bookIt = std::find(books.begin(), books.end(), book);

    if (patronIt != patrons.end() && bookIt != books.end()) {
        int index = std::distance(patrons.begin(), patronIt);
        patronRecords[index].addCheckedOutBook(book);
        book.checkOut();
    } else {
        std::cout << "Patron or book not found.\n";
    }
}

void Library::returnBook(const Patron& patron, const BookItem& book) {
    auto patronIt = std::find(patrons.begin(), patrons.end(), patron);
    auto bookIt = std::find(books.begin(), books.end(), book);

    if (patronIt != patrons.end() && bookIt != books.end()) {
        int index = std::distance(patrons.begin(), patronIt);
        patronRecords[index].removeCheckedOutBook(book);
        book.returnItem();
    } else {
        std::cout << "Patron or book not found.\n";
    }
}


#include "book_item.h"
#include "patron.h"
#include "library.h"
#include <iostream>

int main() {
    // Create instances of books
    BookItem kingDavidBook("Programming with C", "Kingdavid", "SCN/CSC/200000");

    // Create instance of patrons
    Patron drLecturer("DR.lecturer", "15th January 2024");

    // Create library
    Library library;

    // Add books to the library
    library.addBook(kingDavidBook);

    // Add patrons to the library
    library.addPatron(drLecturer);

    // Test borrowing and returning books
    library.borrowBook(drLecturer, AubaBook);
     library.returnBook(drLecturer, AubaBook);

    return 0;
}