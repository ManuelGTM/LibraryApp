#ifndef USER_H
#define USER_H

#include "books.h"
#include <string>
#include <vector>

class User {

  std::string idUser;
  std::string name;
  std::vector<Book> borrowedBooks;
  char status;

public:
  User(std::string, std::string);

  void requestBorrowBook(Book b);
  void returnBook(Book &b);
  void showUser(User &u);

  // Setters
  //
  void setIdUser(std::string);
  void setName(std::string);
  void setStatus(char);

  // Getters
  std::string getIdUser();
  std::string getName();
  char getStatus();
  std::vector<Book> getBorrowedBooks();
  void showBorrowedBooks();
};

#endif
