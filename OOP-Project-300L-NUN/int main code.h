//int main 
#include "library.h"
int main() {
    Library library;

    library.addBook("Object Oriented Programming", "Aisha Nagode", "211203023");
    library.addBook("Geek Girl", "Holly Smalle", "0123456789");

    library.addPatron("Emmanuel Ali", 160124);
    library.addPatron("Becoming", 120721 );

    library.borrowBook(0, 1);
    library.borrowBook(1, 0);
    library.returnBook(0, 0);
    library.returnBook(1, 1);

    library.displayPatronCheckedOutBooks(0);
    library.displayPatronCheckedOutBooks(1);
    return 0;
}