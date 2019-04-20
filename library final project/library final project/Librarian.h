#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Users.h"
using namespace std;
#ifndef LIBRARIAN_H 
#define LIBRARIAN_H

class Librarian : public Users {
private:
	vector<book> books = getBooks();
public:
	void updateBook(int id) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].id == id) {
				string line;
				
				cout << "Old Title:" << books[i].title << endl;
				cout << "New Title: "; getline(cin, line); books[i].title = line;

				cout << "Old Author:" << books[i].authors << endl;
				cout << "New Author: "; getline(cin, line); books[i].authors = line;

				cout << "Old ISBN:" << books[i].ISBN << endl;
				cout << "New ISBN: "; getline(cin, line); books[i].ISBN = line;

				cout << "Old Publication Year:" << books[i].publicationYear << endl;
				cout << "New Publication Year: "; getline(cin, line); books[i].publicationYear = line;

				cout << "Old Publisher:" << books[i].publisher << endl;
				cout << "New Publisher: "; getline(cin, line); books[i].publisher = line;
				books[i].status = "NO";

				break;
			}
		}
		writeToFile(books);
	}
	void addBook() {
		int largestID = books[books.size() - 1].id;
		book n;
		string title, publheryear, publisher, isbn, status, authors;
		cout << "Enter the following information to add book: ";
		getline(cin, title);
		cout << "\nTitle: "; getline(cin, title);
		cout << "\nAuthor: "; getline(cin, authors);
		cout << "\nISBN: "; getline(cin, isbn);
		cout << "\nPublication Year: "; getline(cin, publheryear);
		cout << "\nPublisher: "; getline(cin, publisher);
		n.id = largestID + 1;
		n.title = title;
		n.ISBN = isbn;
		n.status = "NO";
		n.publicationYear = publheryear;
		n.publisher = publisher;
		n.authors = authors;
		books.push_back(n);
		writeToFile(books);
	}

	void deleteBook(int id) {
		int j = 0;
		for (auto i : books) {
			if (i.id == id) {
				books.erase(books.begin() + j);
				break;
			}
			j++;
		}
		writeToFile(books);
	}
	void printAllBooks() {
		const char separator = ' ';
		const int nameWidth = 6;
		const int numWidth = 8;
		cout << left << setw(10) << "ID" << " " << left << setw(20) << "Title" << " " << setw(23) << "Checked Out" << '\n';
		cout << "===========================================" << endl;
		for (auto i : books) {
			cout << left << setw(10) << i.id << " " << left << setw(20) << i.title << " " << setw(23) << i.status << '\n';
		}
	}
};

#endif