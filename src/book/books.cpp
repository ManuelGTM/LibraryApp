#include "../../include/books.h"
#include <iostream>
using namespace std;

// Color codes
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define WHITE "\033[1;37m"
#define RED "\033[1;31m"
#define RESET "\033[0m"
// Variable global

int Book::ISBNCounter = 0;

// Book Constructor
Book::Book(string title, string author, int quantity)
    : title(title), author(author), quantity(quantity), status('A') {

  ISBN = ++ISBNCounter;
}

// Book Info
void Book::showDetails(const Book &b) const {
  // Fondo gris claro, texto oscuro
  cout << "\033[1;37m\033[48;5;235m============================================"
          "==\033[0m\n"; // Fondo gris claro, texto blanco
  cout << "\033[1;32m\t          " << "Book"
       << "\033[0m\n"; // Texto verde claro
  cout << "\033[1;37m\033[48;5;235m============================================"
          "==\033[0m\n"; // Fondo gris claro, texto blanco

  // Detalles con texto amarillo suave
  cout << "\033[1;33mISBN:\033[0m " << b.getId()
       << endl; // Texto amarillo suave
  cout << "\033[1;33mTitle:\033[0m " << b.getTitle()
       << endl; // Texto amarillo suave
  cout << "\033[1;33mAuthor:\033[0m " << b.getAuthor()
       << endl; // Texto amarillo suave
  cout << "\033[1;33mRemaining Copies:\033[0m " << b.getTotalQuantity()
       << endl; // Texto amarillo suave

  // Fondo gris claro, texto blanco
  cout << "\033[1;37m\033[48;5;235m============================================"
          "==\033[0m\n"; // Fondo gris claro, texto blanco
};

void Book::listInfo(const Book &b) const {
  cout << YELLOW << "| " << b.getId() << "\t     | " << b.getTitle()
       << "\t\t|     " << b.getStatus() << "\t     |" << endl;
}

// Borrow book fuctions
void Book::borrowBook() {

  if (quantity >= 0) {
    --quantity;
  }

  return;
};

void Book::returnBook() { ++quantity; }

bool Book::isAvailable() const { return quantity > 0; }

// Setters
void Book::setISBN(int _ISBN) { ISBN = _ISBN; }
void Book::setTitle(std::string _title) { title = _title; };
void Book::setAuthor(std::string _author) { author = _author; }
void Book::setQuantity(int _quantity) { quantity = _quantity; };
void Book::setStatus(char _status) { status = _status; };

// Getters
int Book::getId() const { return ISBN; };
std::string Book::getTitle() const { return title; };
std::string Book::getAuthor() const { return author; };
int Book::getTotalQuantity() const { return quantity; };
char Book::getStatus() const { return status; };
