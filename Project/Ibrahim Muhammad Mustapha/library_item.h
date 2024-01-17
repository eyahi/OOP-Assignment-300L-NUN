
#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H

#include <string>

class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    std::string dueDate;

public:
    LibraryItem(const std::string& title);

    
    std::string getTitle() const;
    bool getIsCheckedOut() const;
    std::string getDueDate() const;

    
    void setTitle(const std::string& title);
    void setDueDate(const std::string& dueDate);

    
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;

};

#endif 
