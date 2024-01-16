#ifndef PATRON_H
#define PATRON_H

#include <iostream>
#include string
class Patron {
private:
    std::string name;
    int libraryCardNumber;

public:
    Patron(const std::string& name, int libraryCardNumber)
        : name(name), libraryCardNumber(libraryCardNumber) {}

    const std::string& getName() const {
        return name;
    }

    int getLibraryCardNumber() const {
        return libraryCardNumber;
    }
};
#endif