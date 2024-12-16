#include "../../include/menu.h"
#include "../../include/books.h"
#include "../../include/users.h"
#include <iostream>
using namespace std;

void Menu::displayHeader(const std::string &title) {

  cout << "==============================================\n";
  cout << "|\t          " << title << "\t                     | \n";
  cout << "==============================================\n";
}

void Menu::Title(string name) {

  cout << "| ID  " << "\t\t" << name << "\t\t  Status     |\n";
  cout << "==============================================\n";
}

void Menu::Footer() {
  cout << "==============================================\n";
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

// TODO tomorrow
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

// Users Table
void Menu::viewUsersMenu(const std::vector<User> &users) {
  displayHeader("Users");
  Title("Users");
  MenuInfo(users);
  Footer();
  cout << endl;
  cout << "Select Book Id: ";
}

// Books Table
void Menu::viewBooksMenu(const std::vector<Book> &books) {

  displayHeader("Books");
  Title("Book");
  MenuInfo(books);
  Footer();
  cout << endl;
  cout << "Select Book Id: ";
}

/*void Menu::viewsBookDetails(const int &ISBN, const std::vector<Book> &books)
 * {*/
/*  displayHeader("Books Details");*/
/**/
/*  cout << "Select Book Id: ";*/
/*}*/
