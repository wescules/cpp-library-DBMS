#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Users.h"
using namespace std;
#ifndef CUSTOMER_H 
#define CUSTOMER_H

class Customer : public Users {
private:
	vector<book> books = getBooks();
public:
	void checkoutBook(int id) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].id == id) {
				books[i].status = getUser();
				break;
			}
		}
		writeToFile(books);
	}

	void search(string str) {
		cout << left << setw(10) << "ID" << " " << setw(23) << "Title" << '\n';
		cout << "===========================================" << endl;
		bool used = false;
		for (int i = 0; i < books.size(); i++) {
			if ((books[i].title.find(str) != string::npos) || (books[i].authors.find(str) != string::npos) || (books[i].publisher.find(str) != string::npos)) {
				cout << left << setw(10) << books[i].id << " " << setw(23) << books[i].title << '\n';
				used = true;
			}
		}
		if (!used)
			cout << "No results found\n";
	}
	void returnBook(int id) {
		for (int i = 0; i < books.size();i++) {
			if (books[i].status == getUser() && books[i].id == id) {
				books[i].status = "NO";
				break;
			}
		}
		writeToFile(books);
	}

	void printCheckedOutBooks() {
		cout << "Checked out Books by: " << getUser() << endl;
		cout << left << setw(20) << "ID" << " " << setw(23) << "Title" << '\n';
		cout << "===========================================" << endl;

		for (auto i : books) {
			if (i.status == getUser()) {
				cout << left << setw(20) << i.id << " " << setw(23) << i.title << '\n';
			}
		}
	}
};

#endif