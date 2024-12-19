#ifndef MENU_H
#define MENU_H

#include "books.h"
#include "library.h"
#include "users.h"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

class Menu {

public:
  void displayHeader(const std::string &title);
  void Title(std::string);
  void Footer();

  void principalMenu();

  void userRegistrationMenu(Library &l);
  void bookRegistrationMenu(Library &l);

  void borrowProcessMenu(const std::vector<User> &users,
                         const std::vector<Book> &books, Library &l);
  void returnProcessMenu(const std::vector<User> &users, Library &l);

  void showBorrowedBooks(const std::vector<User> &users, int userId);
  void viewUsersMenu(const std::vector<User> &users);
  void viewBooksMenu(const std::vector<Book> &books);

  // Generic Functions

  template <typename T> void MenuInfo(const std::vector<T> &items) const {
    for (const auto &item : items) {
      item.listInfo(item);
    }
  }

  // Show User and Book details
  template <typename G>
  void viewDetails(const int &Id, const std::vector<G> &items) {
    int pos = -1; // Inicializa en -1
    for (size_t i = 0; i < items.size(); i++) {
      if (Id == items[i].getId()) {
        pos = i; // Encuentra la posición
        break;
      }
    }

    clear();

    if (pos >= 0) {                       // Si el índice es válido
      items[pos].showDetails(items[pos]); // Muestra los detalles
      std::cout << "\n"
                << YELLOW << "Press any key to return to the main menu..."
                << RESET;
      pause();
    } else {
      std::cout << RED << "User not found.\n" << RESET;
      pause();
    }
  }

  template <typename T>
  void checkForDetails(int opt, const std::string &name,
                       const std::vector<T> &data) {
    switch (opt) {
    case 1:
      clear();

      displayHeader(name);
      Title(name);
      MenuInfo(data);
      Footer();

      std::cout << "\n" << GREEN << "Enter the " << name << " ID: " << RESET;
      int id;
      std::cin >> id;

      viewDetails(id, data);
      break;

    case 2:
      std::cout << YELLOW << "Returning to main menu...\n" << RESET;
      principalMenu();
      break;

    default:
      std::cout << RED << "Invalid option. Try again.\n" << RESET;
      break;
    }
  }

  void pause() {
    std::cin.ignore();
    std::cin.get(); // Espera entrada del usuario
  }
  void clear() { system("clear"); }
};

#endif
