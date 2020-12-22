#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>

//structs

typedef struct user {
  std::string name;
  std::string surname;
} user;

typedef struct date {
  int day;
  int month;
  int year;
} date;

typedef struct book {
  int id;
  std::string title;
  user author;
  std::string cathegory;
  date hire_date;
  user reader;
} book;

typedef struct list_of_books {
  book book;
  list_of_books* next;
  list_of_books* prev;
} list_of_books;

// global variables

list_of_books* head = NULL;

// functions

void push(book data);
void print_all();

void print_book(book data);
void save_to_file(book data);
void read_from_file();

//main

int main() {
  read_from_file();
  // book jeden;
  // jeden.id = 1;
  // jeden.title = "w pustyni";
  // jeden.author.name = "wiktor";
  // jeden.author.surname = "szymanski";
  // jeden.cathegory = "dramat";
  // jeden.hire_date.day = 1;
  // jeden.hire_date.month = 1;
  // jeden.hire_date.year = 2020;
  // jeden.reader.name = "mikołaj";
  // jeden.reader.surname = "ewald";
  // push(jeden);
  print_all();
  //save_to_file(jeden);
  return 0;
}

//functions list

void push(book data) {
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

//functions others

void print_book(book data) {
  std::cout << data.author.name << " " << data.author.surname << "\n";
}

void read_from_file() {
  std::ifstream database("database.txt");
  if (database.good()) {
    book from_database;
    std::string variable;
    while(!database.eof()) {
      //variable nie może lecieć do każdego bo wtedy to samo no i wiadomo
      std::getline(database);
      from_database.id = std::stoi(variable);
      from_database.title = variable;
      from_database.author.name = variable;
      from_database.author.surname = variable;
      from_database.cathegory = variable;
      from_database.hire_date.day = std::stoi(variable);
      from_database.hire_date.month = std::stoi(variable);
      from_database.hire_date.year = std::stoi(variable);
      from_database.reader.name = variable;
      from_database.reader.surname = variable;
      push(from_database);
    }
  } else {
    printf("nie ma bazy\n");
  }
}

void save_to_file(book data) {
  std::fstream database;
  database.open("database.txt", std::fstream::out);
  database << data.id << "\n" << data.title << "\n" << data.author.name << "\n" << data.author.surname << "\n" << data.cathegory << "\n" << data.hire_date.day << "\n" << data.hire_date.month << "\n" << data.hire_date.year << "\n" << data.reader.name << "\n" << data.reader.surname;
  database.close();
}