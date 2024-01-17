#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>
class LibraryItem
{
private:
    std::string title;
    bool isCheckedOut;
    std::string dueDate;

public:
    // Constructor, getters, setters, checkOut(), returnItem()
    LibraryItem(std::string title, bool isCheckedOut = false, std::string dueDate = "")
    {
        this->title = title;
        this->isCheckedOut = isCheckedOut;
        this->dueDate = dueDate;
    }

    void setTitle(std::string title)
    {
        this->title = title;
    }

    void checkOut(std::string dueDate)
    {
        this->isCheckedOut = true;
        this->dueDate = dueDate;
    }

    void returnItem()
    {
        this->isCheckedOut = false;
        this->dueDate = "";
    }

    // getters
    std::string getTitle() const
    {
        return this->title;
    }

    bool getIsCheckedOut() const
    {
        return this->isCheckedOut;
    }

    std::string getDueDate() const
    {
        return this->dueDate;
    }
};
#endif // LIBRARY_ITEM_H