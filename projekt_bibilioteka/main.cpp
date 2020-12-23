#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

#include "struct.h"
#include "global.h"
#include "function.h"

template <typename type, type Book::*struct_el>
void ModifyBook(Book book) {
  std::cout << book.*struct_el << std::endl;
}


int main() {
  read_from_file();
  //Book a = {1, "20 pytan", "no", "hai", "popularnonaukowa", 2, 2, 2020, "mikołaj", "ewald", "bardzo fajna"};
  //Book b = {2, "21 pytan", "noah", "harari", "naukowa", 2, 2, 2020, "mikołaj", "ewald", "bardzo fajna"};
  //push(a);
  //push(b);
  //ModifyBook(1, "title");
  ModifyBook<std::string, &Book::title> (head->book);
  print_all();
  save_to_file();
  return 0;
}

