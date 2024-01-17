// library_item.cpp
#include "library_item.h"

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

void LibraryItem::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void LibraryItem::setDueDate(const std::string& newDueDate) {
    dueDate = newDueDate;
}

void LibraryItem::checkOut() {
    isCheckedOut = true;
    // You can add additional logic here, like updating due date.
}

void LibraryItem::returnItem() {
    isCheckedOut = false;
    // You can add additional logic here.
}
