// Main.cpp
#include "LibrarySystem.h"
#include <iostream>

int main() {
    // Create some books
    BookItem book1("OOP PROJECT SOLUTIONS", "SULE FAIZAH ELE-OJO", "211203067");
    BookItem book2("To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4");
    BookItem book3("1984", "George Orwell", "978-0-452-28423-4");

    // Create some patrons
    Patron patron1("Dr,Emmanuel Ali", "P12345");
    Patron patron2("Jane Smith", "P67890");

    // Create a library
    Library library;

    // Add books to the library
    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    // Add patrons to the library
    library.addPatron(patron1);
    library.addPatron(patron2);

    // Display library status
    std::cout << "Initial Library Status:\n";
    library.displayLibraryStatus();

    // Perform some library operations
    library.borrowBook(patron1, book1);
    library.borrowBook(patron1, book2);
    library.borrowBook(patron2, book2);

    // Display library status after borrow operations
    std::cout << "\nLibrary Status After Borrow Operations:\n";
    library.displayLibraryStatus();

    // Perform some return operations
    library.returnBook(patron1, book1);
    library.returnBook(patron1, book2);

    // Display library status after return operations
    std::cout << "\nLibrary Status After Return Operations:\n";
    library.displayLibraryStatus();

    return 0;
}
