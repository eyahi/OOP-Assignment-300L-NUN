// library_system.h
#ifndef LIBRARY_SYSTEM_H
#define LIBRARY_SYSTEM_H

#include <iostream>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string &title, const std::string &author, const std::string &isbn);
    // Getters and setters
    const std::string &getTitle() const;
    const std::string &getAuthor() const;
    const std::string &getISBN() const;
};

class Patron {
private:
    std::string name;
    std::string libraryCardNumber;

public:
    Patron(const std::string &name, const std::string &libraryCardNumber);
    // Getters and setters
    const std::string &getName() const;
    const std::string &getLibraryCardNumber() const;
};

class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    std::string dueDate;

public:
    LibraryItem(const std::string &title);
    // Getters and setters
    const std::string &getTitle() const;
    bool getIsCheckedOut() const;
    const std::string &getDueDate() const;
    void setDueDate(const std::string &date);
    void checkOut();
    void returnItem();
};

class BookItem : public LibraryItem {
private:
    std::string author;
    std::string isbn;

public:
    BookItem(const std::string &title, const std::string &author, const std::string &isbn);
    // Getters and setters
    const std::string &getAuthor() const;
    const std::string &getISBN() const;
};

class PatronRecord {
private:
    std::vector<BookItem> checkedOutBooks;

public:
    // Functions for managing checked out books
    void addCheckedOutBook(const BookItem &book);
    void removeCheckedOutBook(const BookItem &book);
    const std::vector<BookItem> &getCheckedOutBooks() const;
};

class Library {
private:
    std::vector<BookItem> books;
    std::vector<Patron> patrons;
    std::vector<PatronRecord> patronRecords;

public:
    // Functions for managing books and patrons, borrowing and returning books
    void addBook(const BookItem &book);
    void addPatron(const Patron &patron);
    void borrowBook(const Patron &patron, const BookItem &book);
    void returnBook(const Patron &patron, const BookItem &book);
};

#endif // LIBRARY_SYSTEM_H
