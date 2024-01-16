#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}

    const std::string& getTitle() const {
        return title;
    }

    void setTitle(const std::string& title) {
        this->title = title;
    }

    const std::string& getAuthor() const {
        return author;
    }
    void setAuthor(const std::string& author) {
        this->author = author;
    }

    const std::string& getIsbn() const {
        return isbn;
    }

    void setIsbn(const std::string& isbn) {
        this->isbn = isbn;
        }
};
#endif