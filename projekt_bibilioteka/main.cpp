#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>

#include "struct.h"
#include "global.h"
#include "function.h"


int main() {
  read_from_file();
  std::string input = string_input("wartosc");
  switch (main_switch_case.count(input) ? main_switch_case.at(input) : 0)
  {
  case 1:
    add_book();
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