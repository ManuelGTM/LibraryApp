#include "../../include/library.h"
#include "../../include/books.h"
#include "../../include/users.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Book registration
void Library::addBook(string title, string author, int quantity) {

  Book newBook(title, author, quantity);

  Book *tempBook = checkBook(newBook.getId());

  if (tempBook != nullptr) {
    cout << "Error: The book already exists with ID:" << newBook.getId()
         << endl;
    return;
  }

  if (title.empty() || author.empty() || quantity <= 0) {
    cout << "Error: invalid book details" << endl;
    return;
  }

  books.push_back(newBook);
  cout << "Book added successfully: " << title << " (" << quantity << " copies)"
       << endl;
}

// User registration
void Library::registerUser(string name) {

  User newUser(name);
  User *tempUser = checkUser(newUser.getId());

  // Data validation
  if (tempUser != nullptr) {
    cout << "Error: The user already exists" << endl;
    return;
  }

  if (name.empty()) {
    cout << "Error: invalid users details" << endl;
    return;
  }

  // User data validated and registration process
  users.push_back(newUser);
  cout << "User added successfully: Id( " << newUser.getId() << " ) "
       << "name ( " << name << " )" << endl;
}

// Library Operations

// Borrow operation
void Library::processBorrowing(int idUser, int ISBN) {

  User *tempUser = checkUser(idUser);
  Book *tempBook = checkBook(ISBN);

  // Data validation
  if (!dataValidation(tempBook, tempUser)) {
    return;
  }

  // Borrowing process
  tempUser->requestBorrowBook(*tempBook);
  tempBook->borrowBook();
  cout << "The borrowing was successful" << endl;
}

// Returning operation
void Library::processReturning(int idUser, int ISBN) {

  User *tempUser = checkUser(idUser);
  Book *tempBook = checkBook(ISBN);

  // Data validation
  if (!dataValidation(tempBook, tempUser)) {
    return;
  }

  // Borrowing process validated
  tempUser->returnBook(*tempBook);
  tempBook->returnBook();
  cout << "The returning was successful" << endl;
}

// Borrowing and Returning Error Handling
bool Library::dataValidation(Book *b, User *u) {

  // Data Valitation
  if (u == nullptr && b == nullptr) {
    cout << "Error: Both user and book not found" << endl;
    return false;
  }

  if (b == nullptr) {
    cout << "Error: Book not found" << endl;
    return false;
  }

  if (u == nullptr) {
    cout << "Error: User not found" << endl;
    return false;
  }

  if (!b->isAvailable()) {
    cout << "The book is not available for borrowing" << endl;
    return false;
  }
  return true;
}

// User existence check
User *Library::checkUser(int idUser) {
  for (User &u : users) {
    if (idUser == u.getId()) {
      return &u;
    }
  }

  return nullptr;
}

// Book existence check
Book *Library::checkBook(int ISBN) {
  for (Book &b : books) {
    if (ISBN == b.getId()) {
      return &b;
    }
  }
  return nullptr;
}

// Showing the books information
void Library::showBookInfo() {
  for (Book &n : books) {
    n.listInfo(n);
  }
}

void Library::showUserInfo() {
  for (User &u : users) {
    u.listInfo(u);
  }
}

std::vector<User> Library::getUsers() const { return users; }
std::vector<Book> Library::getBooks() const { return books; }
