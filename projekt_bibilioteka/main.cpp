#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

//structs

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
  struct Date hire_date;
  struct User reader;
  std::string others;
};

struct list_of_books {
  struct Book book;
  list_of_books* next;
  list_of_books* prev;
};

// global variables

list_of_books* head = NULL;

// functions

void push(Book data);
void print_all();

void print_book(Book data);
void save_to_file();
void read_from_file();

//main

int main() {
  read_from_file();
  // Book a = {1, "20 pytan", "no", "hai", "popularnonaukowa", 2, 2, 2020, "mikołaj", "ewald", "bardzo fajna"};
  // Book b = {2, "21 pytan", "noah", "harari", "naukowa", 2, 2, 2020, "mikołaj", "ewald", "bardzo fajna"};
  //push(a);
  //push(b);
  print_all();
  save_to_file();
  return 0;
}

//functions list

void push(Book data) {
  if (head == NULL) {
    list_of_books* element = new list_of_books;
    element->book = data;
    element->prev = NULL;
    element->next = NULL;
    head = element;
  } else {
    list_of_books* curr = head;

    while(curr->next != NULL) {
      curr = curr->next;
    }

    list_of_books* element = new list_of_books;
    element->book = data;
    element->prev = curr;
    element->next = NULL;
    curr->next = element;
  }
}

void print_all() {
  list_of_books* element = head;
  while(element != NULL) {
    print_book(element->book);
    element = element->next;
  }
}

void save_to_file() {
  std::fstream database;
  database.open("database.txt", std::fstream::out);
  list_of_books* element = head;
  while(element != NULL) {
    database << element->book.id << "\n" << element->book.title << "\n" << element->book.author.name << "\n" << element->book.author.surname << "\n" << element->book.cathegory << "\n" << element->book.hire_date.day << "\n" << element->book.hire_date.month << "\n" << element->book.hire_date.year << "\n" << element->book.reader.name << "\n" << element->book.reader.surname << "\n" << element->book.others << "\n";
    element = element->next;
  }
  database.close();
}

//functions others

void print_book(Book data) {
  std::cout << data.author.name << " " << data.author.surname << "\n";
}

void read_from_file() {
  std::ifstream database("database.txt");
  if (database.good()) {
    std::string tab[11];
    int i = 0;
    while(!database.eof()) {
      for (auto &value : tab) {
        getline(database, value);
      }
      Book temporary = { std::stoi(tab[0]), tab[1], tab[2], tab[3], tab[4], std::stoi(tab[5]), std::stoi(tab[6]), std::stoi(tab[7]), tab[8], tab[9], tab[10]};
      push(temporary);
    }
  } else {
    printf("nie ma bazy\n");
  }
}