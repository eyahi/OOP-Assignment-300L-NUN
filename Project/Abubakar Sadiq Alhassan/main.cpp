#include <iostream>
#include "book_item.h"
#include "patron.h"
#include "library.h"
#include "book.h"
#include "library_item.h"
#include "patron_record.h"
using namespace std;
 
int main() {
    // Create a library
    Library library;
     
    
    // Add books to the library
    BookItem book1("Introduction to C++","677i", "John Doe",123456789);
    BookItem book2("Object-Oriented Programming in C++","gdag", "Jane Smith", 987654321);

    library.addBook(book1);
    library.addBook(book2);

    // Add patrons to the library
    Patron patron1("Alice", 123);
    Patron patron2("Bob", 456);

    library.addPatron(patron1);
    library.addPatron(patron2);

    // Display available books
    cout << "Available books in the library:" << endl;
    for (const auto& book : library.getBooks()) {
      book.getB();
    }

    // Patron1 borrows book1
    library.borrowBook(patron1, book1);

    // Display checked-out books for Patron1
    cout << "Books checked out by "<< patron1.getn() << ":" << endl;
    for (const auto& book : library.getPatronRecord(patron1).getcheckedOutBooks()) {
    book.getB();
    }
    // Patron2 borrows book2
    library.borrowBook(patron2, book2);

    // Display checked-out books for Patron2
    std::cout << "Books checked out by "<<patron2.getn() << ":" << std::endl;
    for (const auto& book : library.getPatronRecord(patron2).getcheckedOutBooks()) {
        book.getB();
    }

    // Patron1 returns book1
    library.returnBook(patron1, book1);

    // Display checked-out books for Patron1 after returning
    std::cout << "Books checked out by " << patron1.getn() << " after returning a book:" << std::endl;
    for (const auto& book : library.getPatronRecord(patron1).getcheckedOutBooks()) {
     book.getB();
    }

    return 0;
}
