#pragma once
// library_item.h
#ifndef LIBRARY_ITEM_H
#define LIBRARY_ITEM_H
using namespace std;

class LibraryItem {
private:
	string Title;
	bool IsCheckedOut;
	string DueDate;
public:
	// // Setters, getters, constructor, checkOut(), returnItem()
	void setTitle(string title) {
		Title = title;
	}

	string getTitle() {
		return Title;
	}

	void setIsCheckedOut(bool isCheckedOut) {
		IsCheckedOut = isCheckedOut;
	}

	bool getIsCheckedOut() {
		return IsCheckedOut;
	}

	void setDueDate(string dueDate) {
		DueDate = dueDate;
	}

	string getDueDate() {
		return DueDate;
	}

	//Constructr
	LibraryItem(string title, bool isCheckedOut, string dueDate)
	{
		Title = title;
		IsCheckedOut = isCheckedOut;
		DueDate = dueDate;
	};

	virtual void checkOut() {
		IsCheckedOut = true;
		DueDate = DueDate;
	}

	virtual void returnItem() {
		IsCheckedOut = false;
		DueDate = ""; // Clear the due date when the item is returned
	}
};
#endif // LIBRARY_ITEM_H