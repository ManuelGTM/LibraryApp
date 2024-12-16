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
  Library();

  void addBook(std::string title, std::string author, int quantity);

  Book *checkBook(int ISBN);
  User *checkUser(int idUser);

  bool dataValidation(Book *b, User *u);
  void registerUser(std::string);

  void processReturning(int idUser, int ISBN);
  void processBorrowing(int _idUser, int ISBN);

  void showBookInfo();
  void showUserInfo();

  // getters
  std::vector<User> getUsers();
  std::vector<Book> getBooks();
};

#endif
