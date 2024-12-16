#include "../../include/menu.h"
#include "../../include/books.h"
#include "../../include/library.h"
#include "../../include/users.h"
#include <iostream>
using namespace std;

Menu::Menu() { cout << "New Menu" << endl; }

void Menu::displayHeader(const std::string &title) {

  cout << "\033[1;36m"; // Cambia el color del texto a cyan
  cout << "==============================================\n";
  cout << "              " << title << "               \n";
  cout << "==============================================\n";
  cout << "\033[0m"; // Resetea el color
}

void Menu::principalMenu() {

  displayHeader("Main Menu");
  cout << "\033[1;32m"; // Cambia el color a verde
  cout << "1. Register User\n";
  cout << "2. Register Book\n";
  cout << "3. Borrow Book\n";
  cout << "4. Return Book\n";
  cout << "5. View Users\n";
  cout << "6. View Books\n";
  cout << "0. Exit\n";
  cout << "\033[0m"; // Resetea el color
  cout << "Choose an option: ";
}

void Menu::userRegistrationMenu() {
  displayHeader("User Registration");
  cout << "Enter the user data:\n";
  cout << "Name: ";
}

void Menu::bookRegistrationMenu() {
  displayHeader("Book Registration");
  cout << "Enter the book data:\n";
  cout << "Title: ";
}
void Menu::borrowProcessMenu() {
  displayHeader("Book Borrowing Process");
  cout << "Enter the user Id:\n";
  cout << "User Id: ";
}

void Menu::returnProcessMenu() {
  displayHeader("Book Returning Process");
  cout << "Enter the user Id:\n";
  cout << "User Id: ";
}

void Menu::viewUsersMenu(const std::vector<User> &users) {
  displayHeader("Users");
}
void Menu::viewsUserDetails(const int &userId, const std::vector<User> &users) {

  displayHeader("User Details");
  cout << "Select User Id: ";
}
void Menu::viewBooksMenu(const std::vector<Book> &books) {

  displayHeader("Books");
  cout << "Select Book Id: ";
}
void Menu::viewsBookDetails(const int &ISBN, const std::vector<Book> &books) {

  displayHeader("Books Details");
  cout << "Select Book Id: ";
}
