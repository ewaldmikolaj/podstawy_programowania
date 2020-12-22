#include <stdio.h>
#include <stdlib.h>

typedef struct element_list
{
    int klucz;
    struct element_list *next;
} element_list;

element_list* head = NULL;
void dodawanie_pocz(int liczba);
void dodawanie_kon(int liczba);
void wyswietl(element_list* head);
void usun_pocz();
void usun_koniec();
void usun_index(int index);


int main () {
    dodawanie_pocz(5);
    dodawanie_kon(10);
    dodawanie_pocz(15);
    usun_index(1);
    wyswietl(head);
    return 0;
}

void dodawanie_pocz(int liczba) {
    element_list *element = (element_list*)malloc(sizeof(element_list));
    element -> klucz = liczba;
    element -> next = head;
    head = element;
}

void dodawanie_kon(int liczba) {
    if (head == NULL) {
        element_list* element = (element_list*)malloc(sizeof(element_list));
        element -> klucz = liczba;
        element -> next = NULL;
        head = element;
    } else {
        element_list* curr = head;

        while (curr->next != NULL) {
            curr = curr->next;
        }

        curr->next = (element_list*)malloc(sizeof(element_list));
        curr->next->klucz = liczba;
        curr->next->next = NULL;
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

void usun_koniec() {
    if (head->next == NULL) {
        head = NULL;
    } else {
        element_list *curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }
        free(curr->next);
        curr->next = NULL;
    }
}

void usun_index(int index) {
    if (index == 0) {
        usun_pocz();
    } else {
        element_list *curr = head;
        element_list *tmp;
        int i = 0;
        while(curr->next != NULL && i < index - 1) {
            curr = curr->next;
            i++;
        }
        tmp = curr->next;
        curr->next = tmp->next;
        free(tmp);
    }
}