#include <iostream>
#include <string>
#include "Library.h"
#include "Customer.h"
#include "Librarian.h"
using namespace std;

void customerMenu(Customer u, Library l) {

	int choice, id;
	string str;
	cout << "\n=======LIBRARY MENU=======" << endl;
	cout << "1. Display all avalible Books" << endl;
	cout << "2. Check Out Book" << endl;
	cout << "3. Display Checked out books" << endl;
	cout << "4. Return a Book" << endl;
	cout << "5. Search for a book" << endl;
	cout << "6. Exit" << endl << endl;
	cin >> choice;
	switch (choice)
	{
	case 1 :
		u.printAllAvalibleBooks();
		customerMenu(u, l);
	case 2:
		u.printAllAvalibleBooks();
		cout << "Enter ID of book you want to check out: ";
		cin >> id;
		u.checkoutBook(id);
		customerMenu(u, l);
	case 3:
		u.printCheckedOutBooks();
		customerMenu(u, l);
	case 4:
		u.printCheckedOutBooks();
		cout << "Enter ID of book you want to return: ";
		cin >> id;
		u.returnBook(id);
		customerMenu(u, l);
	case 5:
		cout << "Enter a string to search for: ";
		cin >> str;
		u.search(str);
		customerMenu(u, l);
	case 6:
		exit(1);
	default:
		customerMenu(u, l);
	}
}

void LibrarianMenu(Librarian u, Library l) {

	int choice, id;
	cout << "\n=======ADMIN LIBRARY MENU=======" << endl;
	cout << "1. Display all checked-in Books" << endl;
	cout << "2. Display all Books" << endl;
	cout << "3. Add new book" << endl;
	cout << "4. Edit Book Details" << endl;
	cout << "5. Delete a book" << endl;
	cout << "6. Exit" << endl << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:
		u.printAllAvalibleBooks();
		LibrarianMenu(u, l);
	case 2:
		u.printAllBooks();
		LibrarianMenu(u, l);
	case 3:
		u.addBook();
		LibrarianMenu(u, l);
	case 4:
		u.printAllBooks();
		cout << "Enter the ID of the book you want to edit: ";
		cin >> id;
		u.updateBook(id);
		LibrarianMenu(u, l);
	case 5:
		u.printAllBooks();
		cout << "Enter the ID of the book you want to delete: ";
		cin >> id;
		u.deleteBook(id);
		LibrarianMenu(u, l);
	case 6:
		exit(1);
	default:
		LibrarianMenu(u, l);
	}
}


int main() {
	Users u;

	int loginAttempts = 1;
	bool loggedIn = false;
	string user, pass;
	do {
		cout << "Please Login:" << endl;
		cout << "Username: ";
		cin >> user;
		cout << "Password: ";
		cin >> pass;
		if (u.login(user, pass)) {
			loggedIn = true;
			break;
		}
		loginAttempts++;
	} while (loginAttempts <= 3);

	if (!loggedIn)
		exit(1);
	else if(u.getType() == "C"){
		Customer u;
		Library l;
		customerMenu(u, l);
	}
	else if (u.getType() == "L") {
		Librarian u;
		Library l;
		LibrarianMenu(u, l);
	}

	system("pause");
	return 0;
}