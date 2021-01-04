#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <limits>
#include <array>

//all functions 



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

void del_book() {
  //jakby cos nie dzialalo to commit z dnia 29.12.2020
  if (modified->next !=NULL && modified->prev == NULL) {
    modified->next->prev = NULL;
    head = modified->next;
  } else if (modified->next == NULL && modified->prev != NULL) {
    modified->prev->next = NULL;
  } else if (modified->next != NULL && modified->prev != NULL) {
    modified->prev->next = modified->next;
    modified->next->prev = modified->prev;
  } else if (modified->next == NULL && modified->prev == NULL) {
    head = NULL;
  }
  delete modified;
  modified = NULL;
}

void print_all() {
  list_of_books* element = head;
  std::cout << std::left << std::setw(10) << "id" << std::setw(25) << "tytul" << std::setw(15) << "imie autora" << std::setw(20) << "nazwisko autora" << std::setw(12) << "kategoria" << std::endl;
  while (element != NULL) {
    print_book(element->book);
    element = element->next;
  }
}

void save_to_file() {
  std::fstream database;
  database.open("database.txt", std::fstream::out);
  list_of_books* element = head;
  while(element != NULL) {
    database << element->book.id << "\n" << element->book.title << "\n" << element->book.author.name << "\n" << element->book.author.surname << "\n" << element->book.cathegory << "\n" << element->book.status << "\n" << element->book.hire_date.day << "\n" << element->book.hire_date.month << "\n" << element->book.hire_date.year << "\n" << element->book.reader.name << "\n" << element->book.reader.surname << "\n" << element->book.others;
    if (element->next != NULL) {
      database << "\n";
    }
    element = element->next;
  }
  database.close();
}

//simple functions

std::string string_input(std::string what) {
  std::string output;
  do {
    std::cout << "Podaj " << what << ": ";
    std::getline(std::cin, output);
  } while(output == "");
  return output;
}

int int_input(std::string what, int from, int to) {
  int output;
  do {
    std::cout << "Podaj " << what << ": ";
    while (!(std::cin >> output)) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Podaj " << what << ": ";
    }
  } while (output < from || output > to);
  return output;
}

bool find_in_list(std::string value) {
  list_of_books* element = head;
  int id = -1;
  try {
    id = std::stoi(value);
  } catch(...) {}
  while (element != NULL) {
    if (element->book.id == id || element->book.title == value) {
      modified = element;
      return true;
    }
    element = element->next;
  }
  return false;
}

//other functions

void print_book(Book data) {
  std::cout << std::left << std::setw(10) << data.id << std::setw(25) << data.title << std::setw(15) << data.author.name << std::setw(20) << data.author.surname << std::setw(12) << data.cathegory << std::endl;
}

void read_from_file() {
  std::ifstream database("database.txt");
  if (database.good()) {
    std::string tab[12];
    int i = 0;
    while(!database.eof()) {
      for (auto &value : tab) {
        getline(database, value);
      }
      last_id = tab[0];
      Book temporary = { std::stoi(tab[0]), tab[1], tab[2], tab[3], tab[4], std::stoi(tab[5]), std::stoi(tab[6]), std::stoi(tab[7]), std::stoi(tab[8]), tab[9], tab[10], tab[11]};
      push(temporary);
    }
  } else {
    printf("nie ma bazy\n");
  }
}

void add_book() {
  std::pair <std::string, std::string> holder_cp[11];
  for (int i = 0; i < 11; i++) {
    holder_cp[i] = book_holder[i];
  }
  for (auto &member : holder_cp) {
    if (member.first != "id" && member.first != "status" && member.first != "dzien" && member.first != "miesiac" && member.first != "rok" && member.first != "imie czytelnika" && member.first != "nazwisko czytelnika") {
      member.second = string_input(member.first);
    }
  }
  int id = std::stoi(last_id) + 1;
  last_id = std::to_string(id);
  if (find_in_list(holder_cp[1].second)) {
    std::cout << "ksiazka juz widnieje w bazie i nie zostanie dodana ponownie" << std::endl;
    modified = NULL;
  } else {
    Book book = { id, holder_cp[1].second, holder_cp[2].second, holder_cp[3].second, holder_cp[4].second, std::stoi(holder_cp[5].second) , std::stoi(holder_cp[6].second), std::stoi(holder_cp[7].second), std::stoi(holder_cp[8].second), holder_cp[9].second, holder_cp[10].second, holder_cp[11].second };
    push(book);
  }
}

void edit_book_switch() {
  int i = 1;
  std::cout << "Co chcesz edytowac?" << std::endl;
  for (const auto& member : book_holder) {
    if (member.first != "id" && member.first != "status" && member.first != "dzien" && member.first != "miesiac" && member.first != "rok" && member.first != "imie czytelnika" && member.first != "nazwisko czytelnika") {
      std::cout << i++ << ". " << member.first << std::endl;
    }
  }
  int choice = int_input("liczbe", 1, 5);
  std::cin.ignore();
  switch (choice)
  {
  case 1:
    modified->book.title = string_input("tytul");
    break;

  case 2:
    modified->book.author.name = string_input("imie autora");
    break;

  case 3:
    modified->book.author.surname = string_input("nazwisko autora");
    break;

  case 4:
    modified->book.cathegory = string_input("kategorie");
    break;

  case 5:
    modified->book.others = string_input("inne dane");
    break;
    
  default:
    break; 
  }
}

//program

void add_option () {
  bool end = true;
  int choice = 0;
  std::cout << "# Dodawanie ksiazek #" << std::endl;
  while (end) {
    add_book();
    std::cout << "Czy chcesz dodawac dalej? \n1. tak \n2.nie" << std::endl;
    choice = int_input("liczbe", 1, 2);
    if (choice == 2) {
      end = false;
    }
  }
}

void del_option () {
  bool end = true;
  int choice = 0;
  std::string title_or_id = "";
  std::cout << "# Usuwanie ksiazek #" << std::endl;
  while (end) {
    print_all();
    title_or_id = string_input("id albo tytul");
    if (find_in_list(title_or_id)) {
      del_book();
      std::cout << "Czy chcesz usuwac dalej? \n1. tak \n2.nie" << std::endl;
      choice = int_input("liczbe", 1, 2);
      if (choice == 2) {
        end = false;
      }
    } else {
      std::cout << "\n # Nie ma takiej ksiazki, czy na pewno chcesz usuwac? # \n1. tak \n2.nie \n" << std::endl;
      choice = int_input("liczbe", 1, 2);
      if (choice == 2) {
        end = false;
      }
    }
  }
}

void edit_option () {
  bool end = true;
  int choice = -1;
  std::string title_or_id = "";
  std::cout << "# Edytowanie ksiazek #" << std::endl;
  while (end) {
    print_all();
    title_or_id = string_input("id albo tytul");
    if (find_in_list(title_or_id)) {
      edit_book_switch();
      std::cout << "Czy chcesz edytowac dalej? \n1. tak \n2.nie" << std::endl;
      choice = int_input("liczbe", 1, 2);
      if (choice == 2) {
        end = false;
      }
    } else {
      std::cout << "\n # Nie ma takiej ksiazki, czy na pewno chcesz edytowac? # \n1. tak \n2.nie \n" << std::endl;
      choice = int_input("liczbe", 1, 2);
      if (choice == 2) {
        end = false;
      }
    }
  }
}