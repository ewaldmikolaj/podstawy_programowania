#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unordered_map>
#include <utility>

#include "struct.h"
#include "global.h"

void push(Book data);
void del_book(int index);
void print_all();

void print_book(Book data);
void save_to_file();
void read_from_file();

std::string string_input();
bool find_in_list(std::string value);

void add_option();
void add_book();

#include "function.h"


int main() {
  read_from_file();
  std::string input = string_input("wartosc");
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
  
  case 0:
    std::cout << "zakres" << std::endl;
    break;
  }
  save_to_file();
  return 0;
}