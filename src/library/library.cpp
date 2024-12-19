#include "../../include/library.h"
#include "../../include/books.h"
#include "../../include/users.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Color codes
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

// Book registration
void Library::addBook(string title, string author, int quantity) {

  Book newBook(title, author, quantity);

  Book *tempBook = checkBook(newBook.getId());

  if (tempBook != nullptr) {
    cout << RED << "Error: The book already exists with ID:" << newBook.getId()
         << RESET << endl;
    return;
  }

  if (title.empty() || author.empty() || quantity <= 0) {
    cout << RED << "Error: invalid book details" << RESET << endl;
    return;
  }

  books.push_back(newBook);
  cout << GREEN << "Book added successfully: " << title
       << " (" << quantity << " copies)" << RESET << endl;
}

// User registration
void Library::registerUser(string name) {

  User newUser(name);
  User *tempUser = checkUser(newUser.getId());

  // Data validation
  if (tempUser != nullptr) {
    cout << RED << "Error: The user already exists" << RESET << endl;
    return;
  }

  if (name.empty()) {
    cout << RED << "Error: invalid users details" << RESET << endl;
    return;
  }

  // User data validated and registration process
  users.push_back(newUser);
  cout << GREEN << "User added successfully: Id( "
       << newUser.getId() << " ) "
       << "name ( " << name << " )" << RESET << endl;
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
  cout << GREEN << "The borrowing was successful" << RESET << endl;
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
  cout << GREEN << "The returning was successful" << RESET << endl;
}

// Borrowing and Returning Error Handling
bool Library::dataValidation(Book *b, User *u) {

  // Data Valitation
  if (u == nullptr && b == nullptr) {
    cout << RED << "Error: Both user and book not found" << RESET << endl;
    return false;
  }

  if (b == nullptr) {
    cout << RED << "Error: Book not found" << RESET << endl;
    return false;
  }

  if (u == nullptr) {
    cout << RED << "Error: User not found" << RESET << endl;
    return false;
  }

  if (!b->isAvailable()) {
    cout << RED << "The book is not available for borrowing" << RESET << endl;
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

