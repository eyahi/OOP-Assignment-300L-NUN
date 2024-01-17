#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

class LibraryItem {
private:
    std::string title;
    bool isCheckedOut;
    time_t dueDate;

public:
    LibraryItem(const std::string& _title) : title(_title), isCheckedOut(false), dueDate(0) {}

    std::string getTitle() const {
        return title;
    }

    bool getIsCheckedOut() const {
        return isCheckedOut;
    }

    time_t getDueDate() const {
        return dueDate;
    }

    void checkOut() {
        if (!isCheckedOut) {
            isCheckedOut = true;
            dueDate = std::time(0) + 14 * 24 * 60 * 60;
            std::cout << title << " checked out successfully.\n";
        } else {
            std::cout << title << " is already checked out.\n";
        }
    }

    void returnItem() {
        if (isCheckedOut) {
            isCheckedOut = false;
            dueDate = 0;
            std::cout << title << " returned successfully.\n";
        } else {
            std::cout << title << " is not checked out.\n";
        }
    }
};

class BookItem : public LibraryItem {
private:
    std::string author;
    std::string isbn;

public:
    BookItem(const std::string& _title, const std::string& _author, const std::string& _isbn)
        : LibraryItem(_title), author(_author), isbn(_isbn) {}

    std::string getAuthor() const {
        return author;
    }

    std::string getIsbn() const {
        return isbn;
    }

    void displayBookInfo() const {
        std::cout << "Title: " << getTitle() << "\nAuthor: " << author << "\nISBN: " << isbn << "\n";
    }
};

class Patron {
private:
    std::string name;
    int libraryCardNumber;

public:
    Patron(const std::string& _name, int _libraryCardNumber) : name(_name), libraryCardNumber(_libraryCardNumber) {}

    std::string getName() const {
        return name;
    }

    int getLibraryCardNumber() const {
        return libraryCardNumber;
    }
};

class PatronRecord {
private:
    std::vector<BookItem*> checkedOutBooks;

public:
    void addBook(BookItem* book) {
        checkedOutBooks.push_back(book);
    }

    void removeBook(BookItem* book) {
        auto it = std::find(checkedOutBooks.begin(), checkedOutBooks.end(), book);
        if (it != checkedOutBooks.end()) {
            checkedOutBooks.erase(it);
        }
    }

    void displayCheckedOutBooks() const {
        std::cout << "Checked Out Books:\n";
        for (const auto& book : checkedOutBooks) {
            std::cout << "- " << book->getTitle() << "\n";
        }
    }
};

class Library {
private:
    std::vector<BookItem> books;
    std::vector<Patron> patrons;
    std::vector<PatronRecord> patronRecords;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& isbn) {
        books.emplace_back(title, author, isbn);
    }

    void addPatron(const std::string& name, int libraryCardNumber) {
        patrons.emplace_back(name, libraryCardNumber);
        patronRecords.emplace_back(); 
    }

    BookItem* findBookByTitle(const std::string& title) {
        auto it = std::find_if(books.begin(), books.end(),
                               [&](const BookItem& book) { return book.getTitle() == title; });
        return (it != books.end()) ? &(*it) : nullptr;
    }

    Patron* findPatronByCardNumber(int libraryCardNumber) {
        auto it = std::find_if(patrons.begin(), patrons.end(),
                               [&](const Patron& patron) { return patron.getLibraryCardNumber() == libraryCardNumber; });
        return (it != patrons.end()) ? &(*it) : nullptr;
    }

    void borrowBook(const std::string& title, int libraryCardNumber) {
        BookItem* book = findBookByTitle(title);
        Patron* patron = findPatronByCardNumber(libraryCardNumber);

        if (book && patron) {
            if (!book->getIsCheckedOut()) {
                book->checkOut();
                patronRecords[libraryCardNumber].addBook(book);
                std::cout << "Borrowed successfully.\n";
            } else {
                std::cout << "Book is already checked out.\n";
            }
        } else {
            std::cout << "Book or patron not found.\n";
        }
    }

    void returnBook(const std::string& title, int libraryCardNumber) {
        BookItem* book = findBookByTitle(title);
        Patron* patron = findPatronByCardNumber(libraryCardNumber);

        if (book && patron) {
            if (book->getIsCheckedOut()) {
                book->returnItem();
                patronRecords[libraryCardNumber].removeBook(book);
                std::cout << "Returned successfully.\n";
            } else {
                std::cout << "Book is not checked out.\n";
            }
        } else {
            std::cout << "Book or patron not found.\n";
        }
    }

    void displayCheckedOutBooks(int libraryCardNumber) const {
        patronRecords[libraryCardNumber].displayCheckedOutBooks();
    }
};

int main() {
    Library library;

    library.addBook("the red pyramid", "Rick Riordan", "2939485798403");
    library.addBook("the serpent's shadow", "Rick Riordan", "2939485798404");
    library.addBook("the throne of fire", "Rick Riordan", "2939485798405");

    library.addPatron("Seyi Makinde", 1234);
    library.addPatron("Sofie Alexa", 5678);

    library.borrowBook("the red pyramid", 1234);
    library.borrowBook("the serpent's shadow", 5678);

    library.displayCheckedOutBooks(1234);
    library.displayCheckedOutBooks(5678);

    library.returnBook("the red pyramid", 1234);
    library.returnBook("the serpent's shadow", 5678);

    return 0;
}