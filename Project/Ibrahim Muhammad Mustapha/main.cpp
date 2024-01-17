#include <iostream>
#include "book_item.h"
#include "patron.h"
#include "library.h"

int main() {
    
    Library library;

    
    BookItem bk1("Matlab", "Ibrahim Muhammad Mustapha", "211203069");
    BookItem bk2("OOP in C++", "Dr Emmanual", "61309261");

    library.addBook(bk1);
    library.addBook(bk2);

    
    Patron patron1("Oji", "A1");
    Patron patron2("Krang", "A22");

    library.addPatron(patron1);
    library.addPatron(patron2);

    
    std::cout << "Available books in the library:" << std::endl;
    for (const auto& book : library.getBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

   
    library.borrowBook(patron1, bk1);

   
    std::cout << "Books checked out by " << patron1.getName() << ":" << std::endl;
    for (const auto& book : library.getPatronRecord(patron1).getCheckedOutBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    
    library.borrowBook(patron2, bk2);

    
    std::cout << "Books checked out by " << patron2.getName() << ":" << std::endl;
    for (const auto& book : library.getPatronRecord(patron2).getCheckedOutBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    
    library.returnBook(patron1, bk1);

    
    std::cout << "Books checked out by " << patron1.getName() << " after returning a book:" << std::endl;
    for (const auto& book : library.getPatronRecord(patron1).getCheckedOutBooks()) {
        std::cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << std::endl;
    }

    return 0;
}
