#include <iostream>
#include "book_item.h"
#include "patron.h"
#include "library.h"

int main() {
    // Create a library
    Library library;

    // Add books to the library
    BookItem book1("Introduction to C++", "Haruna Sani Haruna", "211293073");
    BookItem book2("Object-Oriented Programming in C++", "Pogba", "211203000");

    library.addBook(book1);
    library.addBook(book2);

    // Add patrons to the library
    Patron patron1("Dr Emmanuel Ali", "16-01-2024");
    Patron patron2("Juventus", "11-10-2015");

    library.addPatron(patron1);
    library.addPatron(patron2);

    // Display available books
    std::cout << "Available books in the library:" << std::endl;
    for (const auto& book : library.getBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    // Patron1 borrows book1
    library.borrowBook(patron1, book1);

    // Display checked-out books for Patron1
    std::cout << "Books checked out by " << patron1.getName() << ":" << std::endl;
    for (const auto& book : library.getPatronRecord(patron1).getCheckedOutBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    // Patron2 borrows book2
    library.borrowBook(patron2, book2);

    // Display checked-out books for Patron2
    std::cout << "Books checked out by " << patron2.getName() << ":" << std::endl;
    for (const auto& book : library.getPatronRecord(patron2).getCheckedOutBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    // Patron1 returns book1
    library.returnBook(patron1, book1);

    // Display checked-out books for Patron1 after returning
    std::cout << "Books checked out by " << patron1.getName() << " after returning a book:" << std::endl;
    for (const auto& book : library.getPatronRecord(patron1).getCheckedOutBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    return 0;
}
