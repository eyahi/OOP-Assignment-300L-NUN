#include "book_item.h"

BookItem::BookItem(string title,string dueDate, string author,int isbn)
    : LibraryItem(title,dueDate), author(author), isbn(isbn) {}

void BookItem::getB() const {
    LibraryItem::getL();
    cout<<"author:"<<author<<"\nISBN:"<<isbn;
}
void BookItem::setauthor(const string newauthor){
    author = newauthor;
 }
 void BookItem::setisbn(const int newisbn){
    isbn = newisbn;
 }
  
bool BookItem::operator==(const BookItem& other) const {
    
    return 0; 
}
 