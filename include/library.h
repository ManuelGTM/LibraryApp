#ifndef LIBRARY_H
#define LIBRARY_H

#include "books.h"
#include "users.h"
#include <string>
#include <vector>

class Library {

  std::vector<Book> books;
  std::vector<User> users;

public:
  void addBook(std::string, std::string, int);

  Book *checkBook(int);
  User *checkUser(int);

  bool dataValidation(Book *, User *);
  void registerUser(std::string);

  void processReturning(int, int);
  void processBorrowing(int, int);

  void showBookInfo();
  void showUserInfo();

  // getters
  std::vector<User> getUsers() const;
  std::vector<Book> getBooks() const;
};

#endif
