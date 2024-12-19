#include "../../include/users.h"
#include <iostream>
#include <vector>
using namespace std;

// Color codes
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

// Variable Global
int User::idCounter = 0;

// User Constructor
User::User(string name) : name(name), borrowedBooks(), status('A') {
  idUser = ++idCounter;
}

// User Operations
void User::requestBorrowBook(Book b) { borrowedBooks.push_back(b); };

void User::returnBook(Book &b) {

  // Prop borrowedBooks Reference
  vector<Book> &borrowedBooks = this->borrowedBooks;
  vector<Book>::iterator it; // iterator declaration

  // Iterator       Inicio                 Final        Incremento
  for (it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {

    if (b.getId() == it->getId()) { // check if the book exists
      borrowedBooks.erase(it);      // Removing the element from the list
      return;                       // exiting from the function
    }
  }
  cout << RED << "Error: The book was not found in borrowed books." << RESET << endl;
};

void User::showBorrowedBooks() const {

  if (borrowedBooks.empty()) {
    cout << YELLOW << "Borrowed Books: No borrowed books" << RESET << endl;
    return;
  }

  cout << GREEN << "Borrowed Books: " << RESET;

  for (size_t i = 0; i < borrowedBooks.size(); i++) {
    cout << GREEN << borrowedBooks[i].getTitle() << RESET;

    if (i < borrowedBooks.size() - 1) {
      cout << ", ";
    }

    if (i == 4) {
      cout << endl;
      cout << "\t\t ";
    }
  }
  cout << endl;
}

void User::showBorrowedBooksByUser() const {

  if (borrowedBooks.empty()) {
    cout << YELLOW << "No borrowed books" << RESET << endl;
    return;
  }

  for (size_t i = 0; i < borrowedBooks.size(); i++) {
    cout << "| " << borrowedBooks[i].getId() << "\t| "
         << borrowedBooks[i].getTitle() << "\t| "
         << borrowedBooks[i].getAuthor() << "\t| "
         << borrowedBooks[i].getStatus() << "\t|" << endl;
  }
}

void User::showDetails(const User &u) const {
  cout << GREEN << "==============================================\n" << RESET;
  cout << "\t          " << "User" << endl;
  cout << GREEN << "==============================================\n" << RESET;
  cout << WHITE << "IdUser: " << u.getId() << endl;
  cout << "Name: " << u.getName() << endl;
  showBorrowedBooks();
  cout << WHITE << "\nStatus: " << u.getStatus() << endl;
  cout << GREEN << "==============================================\n" << RESET;
};

void User::listInfo(const User &u) const {
  cout << YELLOW << "| " << u.getId() << "\t    |  " << u.getName() << "\t\t|  "
       << u.getStatus() << "\t     |" << endl;
}

// Setters
void User::setIdUser(int _idUser) { idUser = _idUser; };
void User::setName(std::string _name) { name = _name; }
void User::setStatus(char _status) { status = _status; };

// Getters
int User::getId() const { return idUser; };
std::string User::getName() const { return name; };
char User::getStatus() const { return status; };

std::vector<Book> User::getBorrowedBooks() const { return borrowedBooks; };

