#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
#ifndef LIBRARY_H 
#define LIBRARY_H

struct book {
	int id;
	string title, authors, status;
	string publisher, publicationYear, ISBN;
};

class Library {
private:
	vector<book> books;
public:
	Library() {
		readDB();
	}

	void readDB() {
		ifstream infile("books.txt");
		string line;
		int i = 0;
		while (getline(infile, line)) {
			books.push_back(book());
			books[i].id = stoi(line.substr(line.find(":") + 1)); getline(infile, line);
			books[i].title = line.substr(line.find(":") + 1); getline(infile, line);
			books[i].authors = line.substr(line.find(":") + 1); getline(infile, line);
			books[i].ISBN = line.substr(line.find(":") + 1); getline(infile, line);
			books[i].publicationYear = line.substr(line.find(":") + 1); getline(infile, line);
			books[i].publisher = line.substr(line.find(":") + 1); getline(infile, line);
			books[i].status = line.substr(line.find(":") + 2); getline(infile, line);
			i++;
		}
	}
	void printAllAvalibleBooks() {
		for (auto i : books) {
			if (i.status != "NO")
				cout << i.id << " " << i.title << endl;
		}
	}

	vector<book> getBooks() {
		return books;
	}
	
};

#endif