#include <iostream>
#include "book_item.h"
#include "patron.h"
#include "library.h"

int main() {
    // Create a library
    Library library;

    // Add books to the library
    BookItem book1("Introduction to C++", "dr ali", "987654321");
    BookItem book2("Object-Oriented Programming in C++", "Muhammad Hussein Mukhtar", "211203058");

    library.addBook(book1);
    library.addBook(book2);

    // Add patrons to the library
    Patron patron1("alameen", "c130f");
    Patron patron2("moh", "y567k");

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
