#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {

  static int ISBNCounter;
  int ISBN;
  std::string title;
  std::string author;
  int quantity;
  char status;

public:
  Book(std::string, std::string, int);

  void showDetails(const Book &b) const;
  void borrowBook();
  void returnBook();
  bool isAvailable() const;

  void listInfo(const Book &b) const;

  // Setters
  void setISBN(int);
  void setTitle(std::string);
  void setAuthor(std::string);
  void setQuantity(int);
  void setStatus(char);

  // Getters
  int getId() const;
  std::string getTitle() const;
  std::string getAuthor() const;
  int getTotalQuantity() const;
  char getStatus() const;
};

#endif // !BOOK_H
