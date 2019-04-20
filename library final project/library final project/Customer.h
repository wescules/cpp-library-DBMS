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
	string user, pass;
public:
	Customer(string user, string pass) {
		this->user = user;
		this->pass = pass;
	}
	void checkoutBook(int id) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].id == id) {
				books[i].status = user;
				break;
			}
		}
		writeToFile(books);
	}

	void returnBook(int id) {
		for (int i = 0; i < books.size();i++) {
			if (books[i].status == user && books[i].id == id) {
				books[i].status = "NO";
				break;
			}
		}
		writeToFile(books);
	}

	void printCheckedOutBooks() {
		cout << "Checked out Books by: " << user << endl;
		cout << left << setw(20) << "ID" << " " << setw(23) << "Title" << '\n';
		cout << "===========================================" << endl;

		for (auto i : books) {
			if (i.status == user) {
				cout << left << setw(20) << i.id << " " << setw(23) << i.title << '\n';
			}
		}
	}
};

#endif