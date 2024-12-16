#include "../../include/users.h"
#include <iostream>
#include <vector>
using namespace std;

// Variable Global

int User::idCounter = 0;

// User Contructor

User::User(string name) : name(name), borrowedBooks(), status('A') {
  idUser = ++idCounter;
}

// User information
void User::showUser(User &u) {
  cout << "---------------------------------------------" << endl;
  cout << "IdUser: " << u.getIdUser() << endl;
  cout << "Name: " << u.getName() << endl;
  showBorrowedBooks();
  cout << "\nStatus: " << u.getStatus() << endl;
  cout << "---------------------------------------------" << endl;
};

// User Operations
void User::requestBorrowBook(Book b) { borrowedBooks.push_back(b); };

void User::returnBook(Book &b) {

  // Prop borrowedBooks Reference
  vector<Book> &borrowedBooks = this->borrowedBooks;
  vector<Book>::iterator it; // iterator declaration

  // Iterator       Inicio                 Final        Incremento
  for (it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {

    if (b.getISBN() == it->getISBN()) { // check if the book exists
      borrowedBooks.erase(it);          // Removing the element from the list
      return;                           // exiting from the function
    }
  }
  cout << "Error: The book was not found in borrowed books." << endl;
};

// Setters
//
void User::setIdUser(int _idUser) { idUser = _idUser; };
void User::setName(std::string _name) { name = _name; }
void User::setStatus(char _status) { status = _status; };

// Getters
int User::getIdUser() { return idUser; };
std::string User::getName() { return name; };
char User::getStatus() { return status; };

std::vector<Book> User::getBorrowedBooks() { return borrowedBooks; };

void User::showBorrowedBooks() {

  if (borrowedBooks.empty()) {
    cout << "Borrowed Books: No borrowed books";
    return;
  }

  cout << "Borrowed Books: ";

  for (size_t i = 0; i < borrowedBooks.size(); i++) {
    cout << borrowedBooks[i].getTitle();

    if (i < borrowedBooks.size() - 1) {
      cout << ", ";
    }
  }
}
