#ifndef MENU_H
#define MENU_H

#include "books.h"
#include "library.h"
#include "users.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class Menu {

public:
  void displayHeader(const std::string &title);
  void Title(std::string);
  void Footer();

  void principalMenu(int &opt);

  void userRegistrationMenu(Library &l);
  void bookRegistrationMenu(Library &l);

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
    int pos = 0;

    for (size_t i = 0; i < items.size(); i++) {
      if (Id == items[i].getId()) {
        pos = i;
        break;
      } else {
        pos = -1;
      }
    }

    if (pos != -1) {
      items[pos].showDetails(items[pos]);
      std::cout << "\nPresione Enter para continuar...";
      std::cin.ignore(); // Ignora el último salto de línea en el buffer
      std::cin.get();
      viewDetails(Id, items);
    }
  }

  template <typename T>
  void checkForDetails(int opt, std::string name, const std::vector<T> &data) {
    if (opt == 1) {
      system("clear");

      displayHeader(name);
      Title(name);
      MenuInfo(data);
      Footer();
      std::cout << std::endl;

      int id;
      std::cout << "Select " << name << " Id to see details: ";
      std::cin >> id;

      system("clear");

      viewDetails(id, data);
    }
    principalMenu(opt);
  }
};

#endif
