#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>

//all functions 

void push(Book data);
void del_book(int index);
void print_all();

void print_book(Book data);
void save_to_file();
void read_from_file();
void add_book();
std::string string_input();

//list functions

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

void del_book(int index) {
  if (index == 0) {
    list_of_books* element = head;
    head = element->next;
    delete element;
  } else {
    list_of_books* current = head;
    list_of_books* tmp;
    int i = 0;
    while (i < index - 1) {
      current = current->next;
      i++;
    }
    tmp = current->next;
    current->next = tmp->next;
    if (current->next != NULL) {
      current->next->prev = current;
    }
    delete tmp;
  }
}

void print_all() {
  list_of_books* element = head;
  std::cout << std::left << std::setw(10) << "id" << std::setw(25) << "tytul" << std::setw(15) << "imie autora" << std::setw(20) << "nazwisko autora" << std::setw(12) << "kategoria" << std::endl;
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
    database << element->book.id << "\n" << element->book.title << "\n" << element->book.author.name << "\n" << element->book.author.surname << "\n" << element->book.cathegory << "\n" << element->book.hire_date.day << "\n" << element->book.hire_date.month << "\n" << element->book.hire_date.year << "\n" << element->book.reader.name << "\n" << element->book.reader.surname << "\n" << element->book.others;
    if (element->next != NULL) {
      database << "\n";
    }
    element = element->next;
  }
  database.close();
}

//other functions

void print_book(Book data) {
  std::cout << std::left << std::setw(10) << data.id << std::setw(25) << data.title << std::setw(15) << data.author.name << std::setw(20) << data.author.surname << std::setw(12) << data.cathegory << std::endl;
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

std::string string_input(std::string what) {
  std::string output;
  do {
    std::cout << "Podaj " << what << ": ";
    std::getline(std::cin, output);
  } while(output == "");
  return output;
}

void add_book() {
  auto book_map_copy = map_of_book;
  for (auto &member : book_map_copy) {
    member.second = string_input(member.first);
  }
  Book book = { std::stoi(book_map_copy.at("id")), book_map_copy.at("tytul"), book_map_copy.at("imie autora"), book_map_copy.at("nazwisko autora"), book_map_copy.at("kategoria"), std::stoi(book_map_copy.at("dzien")), std::stoi(book_map_copy.at("miesiac")), std::stoi(book_map_copy.at("rok")), book_map_copy.at("imie czytelnika"), book_map_copy.at("nazwisko czytelnika"), book_map_copy.at("inne")};
  push(book);
  //alfabetycznie leci a nie chce tak
}