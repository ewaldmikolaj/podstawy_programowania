#include <stdio.h>
#include <stdlib.h>

typedef struct dane_osobowe {
    char imie[15];
    char nazwisko[20];
    char plec;
} dane_osobowe;

typedef struct baza_danych {
    dane_osobowe osoba[5];
} baza_danych;


int main()
{	
    baza_danych baza;
    int flag;
    int ile = 0;
    for (int i = 0; i < 5; i++) {
        printf("czy chcesz dalej podawac? \n 1. tak 2. nie \n");
        scanf("%d", &flag);
        if (flag == 2) {
            break;
        }
        ile++;
        scanf("%s", &baza.osoba[i].imie);
        scanf("%s", &baza.osoba[i].nazwisko);
        scanf(" %c", &baza.osoba[i].plec);
    }

    for (int i = 0; i < ile; i++) {
        printf("osoba %d: ", i + 1);
        printf("%s \n", baza.osoba[i].imie);
        printf("%s \n", baza.osoba[i].nazwisko);
        printf("%c \n", baza.osoba[i].plec);
    }
    return 0;
}