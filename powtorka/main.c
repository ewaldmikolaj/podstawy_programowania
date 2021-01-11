#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int liczba;
  struct lista *next;
  struct lista *prev;
} lista;

struct lista* head = NULL;
struct lista* tail = NULL;

void push (int dane) {
  if (head == NULL) {
    lista* elem = (lista*)malloc(sizeof(lista));
    elem -> liczba = dane;
    elem -> next = NULL;
    elem -> prev = NULL;
    head = elem;
  } else {
    lista* elem = head;
    lista* tmp = (lista*)malloc(sizeof(lista));
    while (elem->next != NULL) {
      elem = elem->next;
    }

    tmp -> liczba = dane;
    tmp -> next = NULL;
    tmp -> prev = elem;
    elem -> next = tmp;
    tail = tmp;
  }
}

void unshift (int dane) {
  if (head == NULL) {
    lista* elem = (lista*)malloc(sizeof(lista));
    elem -> next = NULL;
    elem -> prev = NULL;
    elem -> liczba = dane;
    head = elem;
  } else {
    lista* elem = (lista*)malloc(sizeof(lista));
    elem -> next = head;
    elem -> prev = NULL;
    elem -> liczba = dane;
    head -> prev = elem;
    head = elem;
  }
}

void print () {
  lista* elem = head;
  while (elem != NULL) {
    printf("%d\n", elem->liczba);
    elem = elem->next;
  }
}

void remove_index (int index) {
  if (index == 0) {
    lista* elem = head;
    head = elem -> next;
    free(elem);
  } else {
    lista* elem = head;
    lista* tmp = (lista*)malloc(sizeof(lista));
    int i = 0;
    while (elem -> next != NULL && i < index - 1) {
      elem = elem -> next;
      i++;
    }
    tmp = elem -> next;
    elem -> next = tmp -> next;
    if (tmp -> next != NULL) {
      tmp -> next -> prev = elem;
    }
    free(tmp);
  }
}

int main () {
  push(10);
  push(20);
  push(30);
  unshift(100);
  unshift(200);
  remove_index(4);
  print();
  return 0;
}