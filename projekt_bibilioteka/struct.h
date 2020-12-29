#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

struct User {
  std::string name;
  std::string surname;
};

struct Date {
  int day;
  int month;
  int year;
};

struct Book {
  int id;
  std::string title;
  struct User author;
  std::string cathegory;
  bool status;
  struct Date hire_date;
  struct User reader;
  std::string others;
};

struct list_of_books {
  struct Book book;
  list_of_books* next;
  list_of_books* prev;
};