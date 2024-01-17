// patron.cpp
#include "patron.h"

Patron::Patron(const std::string& name, const std::string& libraryCardNumber)
    : name(name), libraryCardNumber(libraryCardNumber) {}

std::string Patron::getName() const {
    return name;
}

std::string Patron::getLibraryCardNumber() const {
    return libraryCardNumber;
}

void Patron::setName(const std::string& newName) {
    name = newName;
}

void Patron::setLibraryCardNumber(const std::string& newLibraryCardNumber) {
    libraryCardNumber = newLibraryCardNumber;
}
