#include "../../include/books.h"
#include <iostream>
using namespace std;

// Variable global

int Book::ISBNCounter = 0;

// Book Constructor
Book::Book(string title, string author, int quantity)
    : title(title), author(author), quantity(quantity), status('A') {

  ISBN = ++ISBNCounter;
}

// Book Info
void Book::showDetails(const Book &b) const {
  cout << "==============================================\n";
  cout << "\t          " << "Book" << endl;
  cout << "==============================================\n";
  cout << "ISBN: " << b.getId() << endl;
  cout << "Title: " << b.getTitle() << endl;
  cout << "Author: " << b.getAuthor() << endl;
  cout << "Remaining Copies: " << b.getTotalQuantity() << endl;
  cout << "Total Copies: " << b.getTotalQuantity() << endl;
  cout << "==============================================\n";
};

void Book::listInfo(const Book &b) const {
  cout << "| " << b.getId() << "\t     | " << b.getTitle() << "\t\t|     "
       << b.getStatus() << "\t     |" << endl;
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
