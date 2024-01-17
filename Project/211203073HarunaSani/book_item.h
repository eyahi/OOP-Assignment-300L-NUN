// book_item.h
#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H

#include "library_item.h"

class BookItem : public LibraryItem {
private:
    std::string author;
    std::string isbn;

public:
    BookItem(const std::string& title, const std::string& author, const std::string& isbn);

    // Getters
    std::string getAuthor() const;
    std::string getISBN() const;

    // Setters
    void setAuthor(const std::string& author);
    void setISBN(const std::string& isbn);

    // Override functions
    void checkOut() override;
    void returnItem() override;
};

#endif // BOOK_ITEM_H
