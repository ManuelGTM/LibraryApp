#include "../include/users.h"
#include <iostream>
#include <vector>
using namespace std;

// User Contructor

User::User(string idUser, string name)
    : idUser(idUser), name(name), borrowedBooks(), status('A') {}

// User information
void User::showUser(User &u) {
  cout << "---------------------------------------------" << endl;
  cout << "IdUser: " << u.getIdUser() << endl;
  cout << "Name: " << u.getName() << endl;
  cout << "\nStatus: " << u.getStatus() << endl;
  cout << "---------------------------------------------" << endl;
};

// User Operations
void User::requestBorrowBook(Book b) { borrowedBooks.push_back(b); };

void User::returnBook(Book &b) {

  vector<Book> borrowedBooks = getBorrowedBooks();
  vector<Book>::iterator it; // iterator declaration

  // Iterator       Inicio                 Final        Incremento
  for (it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {

    if (b.getISBN() == it->getISBN()) { // check if the book exists

      Book returnedBook = *it; // capturing the book object
      borrowedBooks.erase(it); // Removing the element from the list
    }
  }
  cout << "Error: The book was not found in borrowed books." << endl;
};

// Setters
//
void User::setIdUser(std::string _idUser) { idUser = _idUser; };
void User::setName(std::string _name) { name = _name; }
void User::setStatus(char _status) { status = _status; };

// Getters
std::string User::getIdUser() { return idUser; };
std::string User::getName() { return name; };
char User::getStatus() { return status; };

std::vector<Book> User::getBorrowedBooks() { return borrowedBooks; };

void User::showBorrowedBooks() { // TODO

  for (Book &b : borrowedBooks) {
    cout << "Borrowed books: " << b.getTitle() << ", ";
  }
}
