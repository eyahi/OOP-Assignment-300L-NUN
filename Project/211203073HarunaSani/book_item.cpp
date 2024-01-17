// book_item.cpp
#include "book_item.h"

BookItem::BookItem(const std::string& title, const std::string& author, const std::string& isbn)
    : LibraryItem(title), author(author), isbn(isbn) {}

std::string BookItem::getAuthor() const {
    return author;
}

std::string BookItem::getISBN() const {
    return isbn;
}

void BookItem::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

void BookItem::setISBN(const std::string& newISBN) {
    isbn = newISBN;
}

void BookItem::checkOut() {
    LibraryItem::checkOut();
    // Additional logic specific to checking out a book.
}

void BookItem::returnItem() {
    LibraryItem::returnItem();
    // Additional logic specific to returning a book.
}
