// BookItem.cpp
#include "LibrarySystem.h"

BookItem::BookItem(const std::string& title, const std::string& author, const std::string& isbn)
    : LibraryItem(title), author(author), isbn(isbn) {}

std::string BookItem::getAuthor() const {
    return author;
}

std::string BookItem::getISBN() const {
    return isbn;
}
