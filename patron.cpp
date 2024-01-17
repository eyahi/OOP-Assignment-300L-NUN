// Patron.cpp
#include "LibrarySystem.h"

Patron::Patron(const std::string& name, const std::string& libraryCardNumber)
    : name(name), libraryCardNumber(libraryCardNumber) {}

std::string Patron::getName() const {
    return name;
}

std::string Patron::getLibraryCardNumber() const {
    return libraryCardNumber;
}
