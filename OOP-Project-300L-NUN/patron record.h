//patron_record.h 
#ifndef PATRON_RECORD_H
#define PATRON_RECORD_H

#include iostream
#include string
#include <vector>
#include "book_item.h"
class PatronRecord {
private:
    std::vector<BookItem*> checkedOutBooks;

public:
    void addBook(BookItem* book) {
        checkedOutBooks.push_back(book);
    }

    
  void removeBook(BookItem* book) {
        checkedOutBooks.erase(
            std::remove_if(checkedOutBooks.begin(), checkedOutBooks.end(),
                           [book](BookItem* b) { return b == book; }),
            checkedOutBooks.end());
    }
    void displayCheckedOutBooks() const {
        std::cout << "Checked Out Books:\n";
        for (const auto& book : checkedOutBooks) {
            std::cout << "- " << book->getTitle() << "\n";
        }
        std::cout << std::endl;
        }    
};
#endif