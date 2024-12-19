#include "../include/books.h"
#include "../include/library.h"
#include "../include/menu.h"
#include "../include/users.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

void pause();
void clear();
void getOpt(int &opt);

int main() {

  Menu menu;
  Library library;

  int opt = 0;

  do {
    clear();
    menu.principalMenu();
    getOpt(opt);
    switch (opt) {
    case 1:
      menu.userRegistrationMenu(library);
      pause();
      break;
    case 2:
      menu.bookRegistrationMenu(library);
      pause();
      break;
    case 3:
      menu.borrowProcessMenu();
      pause();
      break;
    case 4:
      menu.returnProcessMenu();
      pause();
      break;
    case 5:
      menu.viewUsersMenu(library.getUsers());
      pause();
      break;
    case 6:
      menu.viewBooksMenu(library.getBooks());
      pause();
      break;
    case 7:
      break;
    default:
      cout << "Incorrect Option ";
      pause();
    }
    clear();
  } while (opt != 7);
  return 0;
}

void pause() {
  cout << "\nPresione Enter para continuar...";
  cin.ignore(); // Ignora el último salto de línea en el buffer
  cin.get();    // Espera que se presione Enter
}

void clear() { system("clear"); }
void getOpt(int &opt) { cin >> opt; };
