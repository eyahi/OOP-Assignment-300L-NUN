// book.h
#pragma once
#ifndef BOOK_H
#define BOOK_H
using namespace std;

class Book {
private:
	string Title;
	string Author;
	string Isbn; // Iternational standard book number
public:
	// Setters, getters, and constructor 
	void setTitle(string title) {
		Title = title;
	}

	string getTitle() {
		return Title;
	}

	void setAuthor(string author) {
		Author = author;
	}

	string getAuthor() {
		return Author;
	}

	void setIsbn(string isbn) {
		Isbn = isbn;
	}

	string getIsbn() {
		return Isbn;
	}

	//Constructor
	Book(string title, string author, string isbn)
	{
		Title = title;
		Author = author;
		Isbn = isbn;
	};
};
#endif // BOOK_H