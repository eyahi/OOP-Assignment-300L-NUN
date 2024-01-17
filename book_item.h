#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H

#include "library_item.h"

class BookItem : public LibraryItem
{
private:
    std::string author;
    std::string isbn;

public:
    // Constructor, getters, setters
    BookItem(std::string title, std::string author, std::string isbn) : LibraryItem(title)
    {
        this->author = author;
        this->isbn = isbn;
    }

    std::string getIsbn() const
    {
        return this->isbn;
    }
};
#endif // BOOK_ITEM_H