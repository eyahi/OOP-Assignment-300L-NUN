#ifndef BOOK_H #define BOOK_H

#include <string>
class Book
{
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    // Constructor, getters, and setters
    Book(std::string title, std::string author, std::string isbn)
    {
        this->title = title;
        this->author = author;
        this->isbn = isbn;
    }

    // setters
    void setTitle(std::string title)
    {
        this->title = title;
    }

    void setAuthor(std::string author)
    {
        this->author = author;
    }

    void setIsbn(std::string isbn)
    {
        this->isbn = isbn;
    }

    std::string getTitle() const
    {
        return this->title;
    }

    std::string getAuthor() const
    {
        return this->author;
    }

    std::string getIsbn() const
    {
        return this->isbn;
    }
};
#endif // BOOK_H