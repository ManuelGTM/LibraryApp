#include "../include/library.h"
#include "../include/books.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Message for tomorrow me:
// TODO
// Finish the returning method
// Implement the book Class
// The borrowBook method actually!!
// Do some testing of the classes to see
// if they work
// Byee im going to sleep!!

// Library Methods

// Book registration
void Library::addBook(string ISBN, string title, string author, int quantity) {

  Book *tempBook = checkBook(ISBN);

  if (tempBook != nullptr) {
    cout << "Error: The book already exists" << endl;
  }

  if (ISBN.empty() || title.empty() || author.empty() || quantity <= 0) {
    cout << "Error: invalid book details" << endl;
    return;
  }

  Book newBook(ISBN, title, author, quantity);
  books.push_back(newBook);
  cout << "Book added successfully: " << title << " (" << quantity << " copies)"
       << endl;
}

// User registration
void Library::registerUser(string idUser, string name) {

  Book *tempUser = checkBook(idUser);

  // Data validation
  if (tempUser != nullptr) {
    cout << "Error: The user already exists" << endl;
  }

  if (idUser.empty() || name.empty()) {
    cout << "Error: invalid users details" << endl;
    return;
  }

  // User data validated and registration process
  User newUser(idUser, name);
  users.push_back(newUser);
  cout << "User added successfully: Id( " << idUser << " ) " << "name ( "
       << name << " )" << endl;
}

// Library Operations

// Borrow operation
void Library::processBorrowing(string idUser, string ISBN) {

  User *tempUser = checkUser(idUser);
  Book *tempBook = checkBook(ISBN);

  // Data Valitation (if book quantity > 0)
  if (!tempBook->isAvailable()) {
    cout << "The book is not available" << endl;
    return;
  }

  if (tempUser == nullptr) {
    cout << "Error: User not found" << endl;
  }

  if (tempBook == nullptr) {
    cout << "Error: Book not found" << endl;
  }

  // Borrowing process validated
  tempUser->requestBorrowBook(*tempBook);
  tempBook->borrowBook();
  cout << "The borrowing was successful" << endl;
}

// User existence check
User *Library::checkUser(string idUser) {

  User *tempUser = nullptr;

  // Check if the users exists
  for (User &u : users) {
    if (idUser == u.getIdUser()) {
      tempUser = &u;
      break;
    }
  }

  return tempUser;
}

// Book existence check
Book *Library::checkBook(string ISBN) {

  Book *tempBook = nullptr;

  for (Book &b : books) {
    if (ISBN == b.getISBN()) {
      tempBook = &b;
      break;
    }
  }
  return tempBook;
}

// Returning operation
/*void Library::processReturning(string idUser, string ISBN) {*/
/**/
/**/
/**/
/**/
/**/
/**/
/*}*/

// Showing the books information
void Library::showBookInfo() {
  for (Book &n : books) {
    n.showInfo(n);
  }
}

void Library::showUserInfo() {

  for (User &u : users) {
    u.showUser(u);
  }
}
