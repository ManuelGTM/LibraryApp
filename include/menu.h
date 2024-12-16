#ifndef MENU_H
#define MENU_H

#include "books.h"
#include "library.h"
#include "users.h"
#include <string>
#include <vector>

class Menu {

public:
  void displayHeader(const std::string &title);
  void Title(std::string);
  void Footer();

  void principalMenu();

  void userRegistrationMenu();
  void bookRegistrationMenu();

  void borrowProcessMenu();
  void returnProcessMenu();

  void viewUsersMenu(const std::vector<User> &users);
  void viewBooksMenu(const std::vector<Book> &books);

  // Generic Functions

  template <typename T> void MenuInfo(const std::vector<T> &items) const {
    for (const auto &item : items) {
      item.listInfo(item);
    }
  }

  template <typename G>
  void viewDetails(const int &Id, const std::vector<G> &items) {
    for (size_t i = 0; i < items.size(); i++) {
      if (Id == items[i].getId()) {
        items[i].showDetails(items[i]);
      }
    }
  }
};

#endif
