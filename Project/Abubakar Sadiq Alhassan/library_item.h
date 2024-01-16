
#include <iostream>
#include <string>
using namespace std;

// library_item.h
#ifndef LIBRARY_ITEM_H 
#define LIBRARY_ITEM_H
class LibraryItem { 
 private:
  string title; 
  bool ischeckedout; 
  string dueDate;
 public:
  LibraryItem(string title ,string dueDate );
  void getL() const;
  bool getischeckedout()const;
  void settitle(const string newtitle);
  void setdueDate(const string newdueDate);

   virtual void checkout()  = 0;
   
   virtual void returnItem() = 0;
   
   
};
#endif // LIBRARY_ITEM_H