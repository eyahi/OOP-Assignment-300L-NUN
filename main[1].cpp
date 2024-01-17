#include "library.h"
#include <iostream>

int main()
{
    BookItem firstBook("Object oriented programming", "Shahid Mohammed", "211203027");

    Patron firstPatron("Dr Emmanuel Ali", "16th January, 2024");

    Library library;

    library.addBook(firstBook);

    library.addPatron(firstPatron);

    library.borrowBook(firstPatron, firstBook, "15th January 2024");

    library.borrowBook(firstPatron, firstBook, "20th January 2024");

    library.returnBook(firstPatron, firstBook);

    return 0;
}
