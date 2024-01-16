#include <iostream>
#include "book_item.h"
#include "patron.h"
#include "library.h"
#include "book.h"
#include "library_item.h"
#include "patron_record.h"
using namespace std;
 
int main() {
    
    Library library;
     
    BookItem book1("computer engineering","15/01/2024", "Abubakar Sadiq ALhassan",211203056);
    BookItem book2("Object-Oriented Programming in C++","16/01/2024", "Dr. Emmanuel Ali", 12345678);

    library.addBook(book1);
    library.addBook(book2);

    Patron patron1("Dr Ali", 301);
    Patron patron2("Dr Opeyemi", 302);

    library.addPatron(patron1);
    library.addPatron(patron2);

    cout << "Available books in the library:" << endl;
    for (const auto& book : library.getBooks()) {
      book.getB();
    }


    library.borrowBook(patron1, book1);

    cout << "Books checked out by "<< patron1.getn() << ":" << endl;
    for (const auto& book : library.getPatronRecord(patron1).getcheckedOutBooks()) {
    book.getB();
    }
  
    library.borrowBook(patron2, book2);

  
    std::cout << "Books checked out by "<<patron2.getn() << ":" << std::endl;
    for (const auto& book : library.getPatronRecord(patron2).getcheckedOutBooks()) {
        book.getB();
    }

    
    library.returnBook(patron1, book1);

    std::cout << "Books checked out by " << patron1.getn() << " after returning a book:" << std::endl;
    for (const auto& book : library.getPatronRecord(patron1).getcheckedOutBooks()) {
     book.getB();
    }

    return 0;
}
