#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include iostream
#include <ctime>
#include <string>
class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    time_t dueDate;

public:
    LibraryItem(const std::string& title)
        : title(title), isCheckedOut(false), dueDate(0) {}

    const std::string& getTitle() const {
        return title;
    }

    bool getIsCheckedOut() const {
        return isCheckedOut;
    }

    time_t getDueDate() const {
        return dueDate;
    }

    void checkOut() {
        isCheckedOut = true;
       
        dueDate = time(nullptr) + 2 * 7 * 24 * 60 * 60;
    }

    void returnItem() {
        isCheckedOut = false;
        dueDate = 0;
    }
};
#endif