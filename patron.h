#ifndef PATRON_H
#define PATRON_H

#include <string>

class Patron
{
private:
    std::string name;
    std::string libraryCardNumber;

public:
    // Constructor, getters, and setters
    Patron() : name(""), libraryCardNumber("") {}

    Patron(std::string name, std::string libraryCardNumber)
    {
        this->name = name;
        this->libraryCardNumber = libraryCardNumber;
    }

    // setters
    void setName(std::string name)
    {
        this->name = name;
    }

    void setLibraryCardNumber(std::string libraryCardNumber)
    {
        this->libraryCardNumber = libraryCardNumber;
    }

    // getters
    std::string getName() const
    {
        return this->name;
    }

    std::string getLibraryCardNumber() const
    {
        return this->libraryCardNumber;
    }
};
#endif // PATRON_H