#include "../../include/menu.h"
#include "../../include/books.h"
#include "../../include/library.h"
#include "../../include/users.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void Menu::displayHeader(const std::string &title) {

  system("clear");
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

void Menu::principalMenu(int &opt) {
  displayHeader("Main Menu");
  cout << "\033[1;32m"; // Cambia el color a verde
  cout << "1. Register User\n";
  cout << "2. Register Book\n";
  cout << "3. Borrow Book\n";
  cout << "4. Return Book\n";
  cout << "5. View Users\n";
  cout << "6. View Books\n";
  cout << "7. Exit\n";
  cout << "\033[0m"; // Resetea el color
  cout << "Choose an option: ";
  cin >> opt;
}

// TODO tomorrow
void Menu::userRegistrationMenu(Library &l) {
  displayHeader("User Registration");
  cout << "Enter the user data:\n";

  string name;
  cout << "Name: ";
  cin >> name;

  l.registerUser(name);
}

void Menu::bookRegistrationMenu(Library &l) {
  displayHeader("Book Registration");
  cout << "Enter the book data:\n";

  string title, author;
  int quantity;

  cout << "Insert Title: ";
  cin >> title;
  cout << "Insert Author: ";
  cin >> author;
  cout << "Insert the quantity: ";
  cin >> quantity;

  l.addBook(title, author, quantity);
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

// Show stored data

void checkDetailsOptions(int &opt, string name) {
  cout << endl;
  cout << "\033[1;32m"; // Cambia el color a verde
  cout << "Choose an option\n";
  cout << "1. View " << name << " Details\n";
  cout << "2. Go back to Main Menu\n";
  cout << "\033[0m"; // Resetea el color
  cout << endl;

  cin >> opt;
}

// Users Table
void Menu::viewUsersMenu(const std::vector<User> &users) {
  int opt;

  displayHeader("Users");
  Title("Users");

  MenuInfo(users);
  Footer();

  checkDetailsOptions(opt, "User");
  checkForDetails(opt, "User", users);
}

// Books Table
void Menu::viewBooksMenu(const std::vector<Book> &books) {
  int opt;

  displayHeader("Books");
  Title("Book");

  MenuInfo(books);
  Footer();

  checkDetailsOptions(opt, "Book");
  checkForDetails(opt, "Book", books);
}

// void Menu::viewsBookDetails(const int &ISBN, const std::vector<Book> &books)
// {
//   displayHeader("Books Details");
//   cout << "Select Book Id: ";
// }
