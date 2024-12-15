#include "../include/books.h"
#include "../include/library.h"
#include "../include/users.h"
#include <iostream>
using namespace std;

int main() {

  Library library;
  User user1("01", "Manuel");
  Book book1("001", "C++development", "Manuel", 5);

  library.addBook("001", "C++development", "Manuel", 5);
  library.registerUser("01", "Manuel");

  library.showBookInfo();
  library.showUserInfo();

  library.processBorrowing("01", "001");
  library.showBookInfo();
  library.showUserInfo();

  /*cout << user1.getName() << endl;*/

  return 0;
}
