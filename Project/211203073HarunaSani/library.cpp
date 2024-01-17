// library.cpp
#include "library.h"
#include <algorithm>
#include <stdexcept> // Include the <stdexcept> library

// Implement other functions as needed

const std::vector<BookItem>& Library::getBooks() const {
    return books;
}

const PatronRecord& Library::getPatronRecord(const Patron& patron) const {
    auto it = std::find_if(patronRecords.begin(), patronRecords.end(),
                           [&patron](const PatronRecord& record) {
                               return record.getPatron() == patron;
                           });
    if (it != patronRecords.end()) {
        return *it;
    }
    // Handle the case when the patron record is not found.
    // For simplicity, let's throw an exception.
    throw std::runtime_error("Patron record not found in the library");
}

// Implement other functions as needed