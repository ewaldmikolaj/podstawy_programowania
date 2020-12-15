#include <stdio.h>
#include <stdlib.h>

typedef struct element_list
{
    int klucz;
    struct element_list *next;
} element_list;

element_list* head = NULL;
void dodawanie_pocz(int liczba);
void dodwanie_kon(int liczba);
void wyswietl(element_list* head);
void usun_pocz();


int main () {
    dodawanie_pocz(5);
    dodawanie_pocz(10);
    dodawanie_pocz(15);
    printf("head:  %d \n", head->next->next->klucz);
    wyswietl(head);
    usun_pocz();
    wyswietl(head);
    return 0;
}

void dodawanie_pocz(int liczba) {
    element_list *element = (element_list*)malloc(sizeof(element_list));
    element -> klucz = liczba;
    element -> next = head;
    head = element;
}

void dodwanie_kon(int liczba) {
    if (head == NULL) {
        element_list* element = (element_list*)malloc(sizeof(element_list));
        element -> klucz = liczba;
        element -> next = NULL;
        head = element;
    } else {
        
    }
}

void wyswietl(element_list* head) {
    element_list *element = head;
    while (element != NULL) {
        printf("%d ", element -> klucz);
        element = element -> next;
    }
}

void usun_pocz() {
    element_list *element = head;
    if (element != NULL) {
        head = element -> next;
        free(element);
    }
}