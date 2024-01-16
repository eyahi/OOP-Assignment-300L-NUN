//book_item.h 
#ifndef BOOK_ITEM_H
#define BOOK_ITEM_H
#include "library_item.h"
class BookItem : public LibraryItem {
private:
    std::string author;
    std::string isbn;

public:
    BookItem(const std::string& title, const std::string& author, const std::string& isbn)
        : LibraryItem(title), author(author), isbn(isbn) {}

    const std::string& getAuthor() const {
        return author;
    }

    const std::string& getIsbn() const {
        return isbn;
    }

    void displayBookInfo() const {
        std::cout << "Title: " << getTitle() << "\nAuthor: " << author << "\nISBN: " << isbn << std::endl;
        }
        
};
#endif