// LibraryItem.cpp
#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& title)
    : title(title), isCheckedOut(false), dueDate("") {}

std::string LibraryItem::getTitle() const {
    return title;
}

bool LibraryItem::getIsCheckedOut() const {
    return isCheckedOut;
}

std::string LibraryItem::getDueDate() const {
    return dueDate;
}

void LibraryItem::checkOut() {
    if (!isCheckedOut) {
        isCheckedOut = true;
       
        dueDate = "2023-12-31";
        std::cout << "Book checked out successfully. Due date: " << dueDate << std::endl;
    } else {
        std::cout << "Book is already checked out." << std::endl;
    }
}

void LibraryItem::returnItem() {
    if (isCheckedOut) {
        isCheckedOut = false;
        
        dueDate = "";
        std::cout << "Book returned successfully." << std::endl;
    } else {
        std::cout << "Book is not checked out." << std::endl;
    }
}
