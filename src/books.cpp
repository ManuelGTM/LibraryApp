#include "../include/books.h"
#include <iostream>
using namespace std;

// Book Constructor
Book::Book(string ISBN, string title, string author, int quantity)
    : ISBN(ISBN), title(title), author(author), quantity(quantity),
      status('A') {}

// Book Info
void Book::showInfo(Book &b) {
  cout << "---------------------------------------------" << endl;
  cout << "Titulo: " << b.getTitle() << endl;
  cout << "Author: " << b.getAuthor() << endl;
  cout << "ISBN: " << b.getISBN() << endl;
  cout << "Remaining Copies: " << b.getTotalQuantity() << endl;
  cout << "Total Copies: " << b.getTotalQuantity() << endl;
  cout << "---------------------------------------------" << endl;
};

// Borrow book fuctions
void Book::borrowBook() {

  if (quantity > 0) {
    --quantity;
  }

  return;
};

void Book::returnBook() { ++quantity; }

bool Book::isAvailable() const { return quantity > 0; }

// Setters
void Book::setISBN(std::string _ISBN) { ISBN = _ISBN; }
void Book::setTitle(std::string _title) { title = _title; };
void Book::setAuthor(std::string _author) { author = _author; }
void Book::setQuantity(int _quantity) { quantity = _quantity; };
void Book::setStatus(char _status) { status = _status; };

// Getters
std::string Book::getISBN() { return ISBN; };
std::string Book::getTitle() { return title; };
std::string Book::getAuthor() { return author; };
int Book::getTotalQuantity() { return quantity; };
char Book::getStatus() { return status; };
