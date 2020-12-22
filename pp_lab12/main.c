#include <stdio.h>
#include <stdlib.h>

typedef struct element_list {
  int klucz;
  struct element_list *next;
  struct element_list *prev;
} element_list;

element_list* head = NULL;
element_list* prev = NULL;

int main() {
  
  return 0;
}