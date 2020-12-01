#include <stdio.h>
#include <stdlib.h>

void swapp(int *a, int *b);
float averege(int tab[], int size);

const int size = 3;
int main()
{
    /*######################################################*/
    //zad 2.1 & zad 2.2
    //int tab[3] = {20, 40, 60};
    //int *ptr[size];
    //int *ptr = &tab[0];

    /*for (int i = 0; i < size; i++)
        ptr[i] = &tab[i];*/

    /*for (int i = 0; i < size; i++) {
        printf("%d, ", *ptr);
        ptr++;
    }*/

    //zad 2.3
    /*int a = 2;
    int b = 4;
    swapp(&a, &b);
    printf("%d, %d", a, b);*/

    /*######################################################*/

    //zad 4.1
    /*int a;
    scanf("%d", &a);
    int *wsk = &a;
    printf("%d", *wsk);*/

    //zad 4.2
    /*int jakas_tablica[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  //deklaracja tablicy
	int *wsk;	          // deklaracja wskaŸnika typu int
	wsk = jakas_tablica;     // wsk wskazuje 1-szy element
	wsk = &jakas_tablica[0]; // to jest dok³adnie to samo
	                         // co instrukcja wczeœniej
	wsk++; 	   // ok, teraz wskazujemy na 2-gi element tablicy
	(*wsk)++; // a teraz ten 2-gi element zwiêkszamy o 1
	wsk--;
	for (int i = 1; i <= 10; i++) {
        printf("%d, ", *wsk);
        wsk++;
        if (i == 7) {
            *wsk = 77;
        }
    }
	printf("\n%d", jakas_tablica[7]);*/

	//zad 4.3
	/*int tab[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int *ptr = &tab[9];
	for (int i = 1; i <= 10; i++) {
        printf("%p: %d \n", ptr, *ptr);
        ptr--;
	}*/

	//zad 4.4
	/*int tab[3] = {20, 40, 60};
    int *ptr = &tab[0];
	while (ptr <= &tab[size - 1]) {
        printf("%p: %d \n", ptr, *ptr);
        ptr++;
	}*/

	//zad 4.5
    /*int tab[5] = {5, 3, 2, 1, 6};
    float avg = averege(tab, 5);
    printf("%f", avg);*/

	//tablica znaków
	char slowo[] = {'j', 'a', 'k', 'd', 'z', 'i', 'a', 'l', 'a'};
	char slowo2[] = "jakdziala";
	printf("%s \n", slowo);
	printf("%s \n", slowo2);

	for (int i = 0; i < 9; i++)
        printf("%c", slowo[i]);

	return 0;
}

void swapp(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

float averege(int tab[], int size) {
    double avg = 0;
    for(int i = 0; i < size; i++)
        avg += tab[i];
    avg = avg / (double)size;
    return avg;
}
