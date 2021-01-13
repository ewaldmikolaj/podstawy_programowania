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

#include "function.h"


int main() {
  std::string input;
  std::unordered_map<std::string, int> main_switch_case;
  std::cout << "# Witamy w programie bibliotecznym #" << std::endl;
  while (true) {
    //dodac menu zalezne od tego co mamy
    if (head == NULL) {
      main_switch_case = main_switch_case_small;
      std::cout << "Co chcesz zrobic?\n1. Dodaj nowa ksiazke\n2. Wczytaj ksiazki\nX. Wyjdz" << std::endl;
    } else {
      main_switch_case = main_switch_case_big;
      std::cout << "Co chcesz zrobic?\n1. Dodaj nowa ksiazke\n2. Usun ksiazke\n3. Edytuj dane ksiazki\n4. Zmien status ksiazki\n5. Wyszukaj ksiazke\n6. Wypisz wszystkie ksiazki\n7. Wypisz ksiazki alfabetycznie\n8. Wypisz ksiazki wypozyczone\nX. Wyjdz " << std::endl;
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
      
    case 6:
      print_all();
      break;

    case 7:
      print_alphabetically();
      break;

    case 8:
      break;
    
    case 9:
      read_from_file();
      break;
    
    case 10:
      save_to_file();
      break;

    case 11:
      std::cout << "Wylaczanie programu..." << std::endl;
      save_to_file();
      std::exit(0);
      break;

    case 0:
      std::cout << "Wprowadz poprawna wartosc" << std::endl;
      break;
    }
  }
  return 0;
}