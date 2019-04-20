#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Library.h"
using namespace std;
#ifndef USERS_H 
#define USERS_H

class Users : public Library{
	string user, type;
	vector<book> books = getBooks();
public:
	bool login(string username, string pass) {
		//store in plaintext ez access
		ifstream infile("login.txt");
		string line;
		int i = 0;
		while (getline(infile, line)) {
			string password;
			stringstream ss(line);
			ss >> user >> password >> type;
			if (user == username && password == pass)
				return true;
		}
		return false;
	}

	void printAllAvalibleBooks() {
		cout << left << setw(10) << "ID" << " " << setw(23) << "Title" << '\n';
		cout << "===========================================" << endl;
		for (auto i : books) {
			if (i.status == "NO")
				cout << left << setw(10) << i.id << " " << setw(23) << i.title << '\n';
		}
	}

	void writeToFile(vector<book> books) {
		this->books = books;
		ofstream outfile("books.txt");
		int j = 0;
		int size = books.size();
		for (auto i : books) {
			outfile << "ID:" << i.id << endl;
			outfile << "Title:" << i.title << endl;
			outfile << "Author(s):" << i.authors << endl;
			outfile << "ISBN:" << i.ISBN << endl;
			outfile << "Publication Year:" << i.publicationYear << endl;
			outfile << "Publisher:" << i.publisher << endl;
			outfile << "Checked Out: " << i.status << endl;
			if (j != books.size() - 1) {
				outfile << endl;
			}
			j++;
		}

		outfile.close();
	}


	string getUser() {
		return user;
	}
	string getType() {
		return type;
	}
};

#endif