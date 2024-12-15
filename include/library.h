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
  void addBook(std::string ISBN, std::string title, std::string author,
               int quantity);
  Book *checkBook(std::string ISBN);
  User *checkUser(std::string idUser);
  void registerUser(std::string, std::string);
  void processReturning();
  void processBorrowing(std::string _idUser, std::string ISBN);
  void showBookInfo();
  void showUserInfo();
};

#endif
