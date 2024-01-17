// patron.h
#ifndef PATRON_H
#define PATRON_H

#include <string>
#include "book_item.h"

class Patron {
private:
    std::string name;
    std::string libraryCardNumber;

public:
    Patron(const std::string& name, const std::string& libraryCardNumber);

    // Getters
    std::string getName() const;
    std::string getLibraryCardNumber() const;

    // Setters
    void setName(const std::string& name);
    void setLibraryCardNumber(const std::string& libraryCardNumber);
};

#endif // PATRON_H
