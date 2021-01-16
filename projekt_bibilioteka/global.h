#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unordered_map>
#include <utility>

list_of_books* head = NULL;
list_of_books* tail = NULL;
list_of_books* modified = NULL;
std::string last_id = "0"; 

static const std::unordered_map<std::string, int> main_switch_case_small {
  {"1", 1},
  {"2", 9},
  {"X", 11}
};

static const std::unordered_map<std::string, int> main_switch_case_big {
  {"1", 1},
  {"2", 2},
  {"3", 3},
  {"4", 4},
  {"5", 5},
  {"6", 6},
  {"7", 7},
  {"8", 8},
  {"9", 9},
  {"10", 10},
  {"X", 11}
};

const std::pair <std::string, std::string> book_holder[] {
  {"id", ""},
  {"tytul", ""},
  {"imie autora", ""},
  {"nazwisko autora", ""},
  {"kategoria", ""},
  {"status", "0"},
  {"dzien", "0"},
  {"miesiac", "0"},
  {"rok", "0"},
  {"imie czytelnika", ""},
  {"nazwisko czytelnika", ""},
  {"inne", ""}
};