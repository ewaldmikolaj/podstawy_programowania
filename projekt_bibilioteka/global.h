#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>

list_of_books* head = NULL;

static const std::unordered_map<std::string, int> main_switch_case {
  {"1", 1},
  {"2", 2},
  {"3", 3},
  {"4", 4},
  {"5", 5},
  {"6", 6},
  {"7", 7},
  {"X", 8}
};

static const std::map<std::string, std::string> map_of_book {
  {"id", ""},
  {"tytul", ""},
  {"imie autora", ""},
  {"nazwisko autora", ""},
  {"kategoria", ""},
  {"dzien", ""},
  {"miesiac", ""},
  {"rok", ""},
  {"imie czytelnika", ""},
  {"nazwisko czytelnika", ""},
  {"inne", ""}
};