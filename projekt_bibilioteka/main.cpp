#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

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
  int Id;
  std::string title;
  std::string author_name;
  std::string author_surname;
  std::string category;
  date hire_date;
  user user;
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
void print_book(book data);
void print_all();

int main() {
  book jeden;
  jeden.Id = 1;
  jeden.title = "w pustyni";
  jeden.author_name = "wiktor";
  jeden.author_surname = "szymanski";
  jeden.category = "dramat";
  jeden.hire_date.day = 1;
  jeden.hire_date.month = 1;
  jeden.hire_date.year = 2020;
  jeden.user.name = "mikołaj";
  jeden.user.surname = "ewald";
  push(jeden);
  print_all();
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
  std::cout << data.author_name << " " << data.author_surname << "\n";
}