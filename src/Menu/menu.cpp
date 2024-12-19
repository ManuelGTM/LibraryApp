#include "../../include/menu.h"
#include "../../include/books.h"
#include "../../include/library.h"
#include "../../include/users.h"
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

void Menu::displayHeader(const std::string &title) {
  system("clear");
  cout << GREEN << "==============================================\n";
  cout << "\t     " << RED << title << GREEN << "\t                 \n";
  cout << "==============================================\n" << RESET;
}

void Menu::Title(string name) {
  cout << YELLOW << "| ID  " << "\t\t" << name << "\t\t  Status   \n";
  cout << GREEN << "==============================================\n" << RESET;
}

void Menu::Footer() {
  cout << GREEN << "==============================================\n" << RESET;
}

void Menu::principalMenu() {
  clear();
  displayHeader("Main Menu");
  cout << YELLOW;  // Cambia el color a verde
  cout << "1. Register User\n";
  cout << "2. Register Book\n";
  cout << "3. Borrow Book\n";
  cout << "4. Return Book\n";
  cout << "5. View Users\n";
  cout << "6. View Books\n";
  cout << "7. Exit\n";
  cout << RESET; // Resetea el color
  Footer();
  cout << GREEN << "Choose an option: " << RESET;
}

// TODO tomorrow
void Menu::userRegistrationMenu(Library &l) {
  displayHeader("User Registration");
  cout << YELLOW << "Enter the user data:\n" << RESET;

  string name;
  cout << WHITE << "Name: ";
  cin >> name;

  cout << endl;

  l.registerUser(name);
}

void Menu::bookRegistrationMenu(Library &l) {
  displayHeader("Book Registration");
  cout << YELLOW << "Enter the book data:\n" << RESET;

  string title, author;
  int quantity;

  cout << WHITE << "Insert Title: ";
  cin >> title;
  cout << "Insert Author: ";
  cin >> author;
  cout << "Insert the quantity: ";
  cin >> quantity;

  cout << endl;

  l.addBook(title, author, quantity);
}

void Menu::borrowProcessMenu(const vector<User> &users,
                             const std::vector<Book> &books, Library &l) {

  int userId;
  int bookId;

  displayHeader("Book Borrowing Process");
  Title("Users");
  MenuInfo(users); // Muestra la lista de usuarios
  Footer();

  cout << "\n" << GREEN << "Enter the user Id\n" << RESET;
  cout << WHITE << "User Id: ";
  cin >> userId;

  system("clear");

  displayHeader("Book Borrowing Process");
  Title("Books");
  MenuInfo(books); // Muestra la lista de libros
  Footer();

  cout << "\n" << GREEN << "Enter the book Id\n" << RESET;
  cout << WHITE << "Book Id: ";
  cin >> bookId;

  l.processBorrowing(userId, bookId);
}

void Menu::returnProcessMenu(const vector<User> &users, Library &l) {

  int userId;
  int bookId;

  displayHeader("Book Returning Process");
  Title("Users");
  MenuInfo(users); // Muestra la lista de usuarios
  Footer();

  cout << "\n" << GREEN << "Enter the user Id\n" << RESET;
  cout << WHITE << "User Id: ";
  cin >> userId;

  system("clear");

  displayHeader("Book Returning Process");
  Title("Users");
  showBorrowedBooks(users, userId);
  Footer();

  cout << "\n" << GREEN << "Enter the book Id\n" << RESET;
  cout << WHITE << "Book Id: ";
  cin >> bookId;

  l.processReturning(userId, bookId);
}

void Menu::showBorrowedBooks(const vector<User> &users, int userId) {

  for (const auto &b : users) {
    if (userId == b.getId()) {
      b.showBorrowedBooksByUser();
    }
  }
}

// Show stored data

void checkDetailsOptions(int &opt, string name) {
  cout << endl;
  cout << GREEN << "Options" << RESET << endl;
  cout << WHITE << "1. View " << name << " Details\n" << RESET;
  cout << WHITE << "2. Go back to Main Menu\n" << RESET;
  cout << WHITE << endl;

  cout << GREEN << "Choose an option: " << RESET;
  cin >> opt;
}

void Menu::viewUsersMenu(const std::vector<User> &users) {
  int opt;

  if (users.empty()) {
    cout << RED << "No users registered yet.\n" << RESET;
    return;
  }

  displayHeader("Users");
  Title("Users");

  MenuInfo(users); // Muestra la lista de usuarios
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

