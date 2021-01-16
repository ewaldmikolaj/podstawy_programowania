#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unordered_map>

#include "struct.h"
#include "global.h"

void push(Book data); 
void del_book(); 
void print_all(); 
void clean_list();

void print_book(Book data);
void print_used_books();
void save_to_file();
void read_from_file();

std::string string_input();
int int_input (std::string what, int from, int to);
bool find_in_list(std::string value);
void edit_book_switch();
void modify_book_status();

void add_option();
void add_book();
void edit_option();
void del_option();
void change_status();
void print_alphabetically();
void print_rented();
void print_selected();

#include "function.h"

//dodac ogon

int main() {
  std::string input;
  std::unordered_map<std::string, int> main_switch_case;
  std::cout << "# Witamy w programie bibliotecznym #" << std::endl;
  while (true) {
    if (head == NULL) {
      main_switch_case = main_switch_case_small;
      std::cout << "Co chcesz zrobic?\n1. Dodaj nowa ksiazke\n2. Wczytaj ksiazki\nX. Wyjdz" << std::endl;
    } else {
      main_switch_case = main_switch_case_big;
      std::cout << "Co chcesz zrobic?\n1. Dodaj nowa ksiazke\n2. Usun ksiazke\n3. Edytuj dane ksiazki\n4. Zmien status ksiazki\n5. Wyszukaj ksiazke\n6. Wypisz wszystkie ksiazki\n7. Wypisz ksiazki alfabetycznie\n8. Wypisz ksiazki wypozyczone\n9. Wczytaj z pliku\n10. Zapisz do pliku\nX. Wyjdz " << std::endl;
    }
    input = string_input("wartosc");
    switch (main_switch_case.count(input) ? main_switch_case.at(input) : 0)
    {
    case 1:
      add_option();
      break;
    
    case 2:
      del_option();
      break;
    
    case 3:
      edit_option();
      break;

    case 4:
      change_status();
      break;

    case 5:
      print_selected();
      break;
      
    case 6:
      print_all();
      break;

    case 7:
      print_alphabetically();
      break;

    case 8:
      print_rented();
      break;
    
    case 9:
      std::cout << "Wczytanie danych z pliku..." << std::endl;
      read_from_file();
      break;
    
    case 10:
      std::cout << "Zapisywanie danych do pliku..." << std::endl;
      save_to_file();
      break;

    case 11:
      std::cout << "Wylaczanie programu..." << std::endl;
      clean_list();
      std::exit(0);
      break;

    case 0:
      std::cout << "Wprowadz poprawna wartosc" << std::endl;
      break;
    }
  }
  return 0;
}