#include "library.h"
int main() {
    Library library;

    library.addBook("object oriented programming", " Maimuna Ali Muhammad", "211203044");
    library.addBook("Blood of my monster", "Rina kent", "458983402");

    library.addPatron("Emmanuel Ali", 14-01-24);
    library.addPatron("krill mozorov", 26610);

    library.borrowBook(0, 1);
    library.borrowBook(1, 0);
    library.returnBook(0, 0);
    library.returnBook(1, 1);

    library.displayPatronCheckedOutBooks(0);
    library.displayPatronCheckedOutBooks(1);

    return 0;
}