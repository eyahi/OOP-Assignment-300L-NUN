#include "library_item.h"

LibraryItem::LibraryItem(string title,string dueDate)
    : title(title), ischeckedout(false), dueDate(dueDate) {}

void LibraryItem::getL() const {
    cout<<"title:"<<title<<"\nduedate:"<<dueDate<<"\n";
}

bool LibraryItem::getischeckedout() const {
    return ischeckedout;
}

void LibraryItem::settitle(const string newtitle) {
    title = newtitle;
}

void LibraryItem::setdueDate(const string newdueDate) {
    dueDate = newdueDate;
}

void LibraryItem::checkout() {
    ischeckedout = true;
    
}

void LibraryItem::returnItem() {
    ischeckedout = false;
    
}


