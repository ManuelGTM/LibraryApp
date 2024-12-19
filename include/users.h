#ifndef USER_H
#define USER_H

#include "books.h"
#include <string>
#include <vector>

class User {

  static int idCounter;
  int idUser;
  std::string name;
  std::vector<Book> borrowedBooks;
  char status;

public:
  User(std::string);

  void requestBorrowBook(Book b);
  void returnBook(Book &b);

  void showBorrowedBooks() const;
  void showBorrowedBooksByUser() const;
  void listInfo(const User &u) const;
  void showDetails(const User &u) const;

  // Setters
  //
  void setIdUser(int);
  void setName(std::string);
  void setStatus(char);

  // Getters
  int getId() const;
  std::string getName() const;
  char getStatus() const;
  std::vector<Book> getBorrowedBooks() const;
};

#endif
