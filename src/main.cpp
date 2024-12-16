#include "../include/books.h"
#include "../include/library.h"
#include "../include/menu.h"
#include "../include/users.h"
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {

  vector<Book> book = {
      Book("C++", "Manuel", 5),
      Book("C++", "Manuel", 5),
      Book("C++", "Manuel", 5),
      Book("C++", "Manuel", 5),
  };

  vector<User> user = {
      User("Manuel"),
      User("Manuel"),
      User("Manuel"),
      User("Manuel"),
  };

  Menu menu1;
  Library library1;
  User user1("Kevin Duran Almonte");
  Book book1("C++", "Manuel", 5);
  Book book3("Python", "Manuela", 3);
  Book book4("Rust", "Manases", 3);

  user1.requestBorrowBook(book1);
  user1.requestBorrowBook(book1);
  user1.requestBorrowBook(book3);
  user1.requestBorrowBook(book4);

  /*user1.showDetails(user1);*/
  /*book1.showDetails(book1);*/

  menu1.viewDetails(1, book);

  /*menu.principalMenu();*/
  /*menu.userRegistrationMenu();*/
  /*library1.addBook("C++", "Manuel", 5);*/
  /*library1.addBook("Python", "Manuela", 3);*/
  /*library1.addBook("Rust", "Manases", 3);*/
  /*library1.addBook("Go", "Yordy", 5);*/
  /*library1.registerUser("Manuel");*/
  /*library1.registerUser("Yordy");*/
  /*library1.registerUser("Manases");*/
  /*library1.registerUser("Manases");*/
  /*library1.registerUser("Manases");*/
  /*library1.registerUser("Manases");*/
  /**/
  /*menu.viewUsersMenu(library1.getUsers());*/

  /*menu.viewBooksMenu(library1.getBooks());*/

  // Todo for tomorrow
  // Finish the menus Boring :(

  /*int opt;*/
  /**/
  /*do {*/
  /**/
  /*  switch (opt) {*/
  /*  case 1:*/
  /*    break;*/
  /*  case 2:*/
  /*    break;*/
  /*  case 3:*/
  /*    break;*/
  /*  case 4:*/
  /*    break;*/
  /*  case 5:*/
  /*    break;*/
  /*  case 6:*/
  /*    break;*/
  /*  case 7:*/
  /*    break;*/
  /*  case 8:*/
  /*    break;*/
  /*  case 9:*/
  /*    break;*/
  /**/
  /*  default:*/
  /*    cout << "Incorrect Option";*/
  /*  }*/
  /*} while (opt != 9);*/

  return 0;
}
