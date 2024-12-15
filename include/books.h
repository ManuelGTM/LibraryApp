#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {

  std::string ISBN;
  std::string title;
  std::string author;
  int quantity;
  char status;

public:
  Book(std::string, std::string, std::string, int);

  void showInfo(Book &b);
  void borrowBook();
  void returnBook();
  bool isAvailable() const;

  // Setters
  //
  void setISBN(std::string);
  void setTitle(std::string);
  void setAuthor(std::string);
  void setQuantity(int);
  void setStatus(char);

  // Getters
  std::string getISBN();
  std::string getTitle();
  std::string getAuthor();
  int getTotalQuantity();
  char getStatus();
};

#endif // !BOOK_H
