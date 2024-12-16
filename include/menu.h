#ifndef MENU_H
#define MENU_H

#include <vector>

#include "library.h"

class Menu {
  Library library;

public:
  Menu();

  void displayHeader(const std::string &title);
  void principalMenu();

  void userRegistrationMenu();
  void bookRegistrationMenu();

  void borrowProcessMenu();
  void returnProcessMenu();

  void viewUsersMenu(const std::vector<User> &users);
  void viewsUserDetails(const int &userId, const std::vector<User> &users);

  void viewBooksMenu(const std::vector<Book> &books);
  void viewsBookDetails(const int &ISBN, const std::vector<Book> &books);
};

#endif
