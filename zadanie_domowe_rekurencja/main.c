#include <stdio.h>
#include <stdlib.h>

int sumaI(int n) {
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n = n / 10;
    }
    return suma;
}

int sumaR(int n) {
    if (n == 0)
        return 0;
    return n % 10 + sumaR(n / 10);
}

int sumaParzystychI(int n) {
    int suma = 0;
    while (n > 0) {
        if ((n % 10) % 2 == 0)
            suma += n % 10;
        n = n / 10;
    }
    return suma;
}

int sumaParzystychR(int n) {
    if (n == 0)
        return 0;
    return ((n % 10) % 2) == 0 ? n % 10 + sumaParzystychR(n / 10) : sumaParzystychR(n / 10);
}

void odwrotnieR(char tab[], int size) {
    if (size < 0)
        return;
    printf(" %c", tab[size]);
    odwrotnieR(tab, size - 1);
}

void sortowanie(int tab[], int lewy, int prawy, int srodek) {

}

int szukanie(int tab[], int tabSize, int x) {
    if (tabSize < 0)
        return 0;
    if (tab[tabSize] == x)
        return 1;
    return szukanie(tab, tabSize - 1, x);
}



int main()
{
    //Zad 1. Napisz program obliczania sumy cyfr dziesi�tnych dla zadanej z klawiatury liczby n (iteracyjnie, rekurencyjnie).
    printf("suma: %d \n", sumaI(555));
    printf("suma: %d \n", sumaR(555));

    //Zad 2. Napisz program obliczania sumy cyfr dziesi�tnych, ale tylko parzystych dla zadanej z klawiatury liczby n (iteracyjnie, rekurencyjnie).
    printf("suma parzystych: %d \n", sumaParzystychI(22));
    printf("suma parzystych: %d \n", sumaParzystychR(555));

    //Zad 3. Napisz funkcj�, kt�ra wypisze w odwrotnej kolejno�ci znaki wczytane z klawiatury. Przyk�adowo,
    //gdy zadany ci�g to: [1, 2, 3, a, c, b] program powinien wypisa�: [b, c, a, 3, 2, 1].
    char tab[] = {'a', 'b', 'c', '1', '2', '3'};
    int tabLenght = sizeof(tab) / sizeof(*tab) + 1;
    printf("odwrotnie:");
    odwrotnieR(tab, tabLenght);
    printf("\n");

    //Zad 4. Napisz program w kt�rym zadeklarujesz tablic� o d�ugo�ci n, wype�nij j� warto�ciami losowymi
    //i zaimplementuj rekurencyjny algorytm sortowania metod� podzia�u na dwie cz�ci.


    //Zad 5. Napisz program w kt�rym zadeklarujesz tablic� o d�ugo�ci n, a nast�pnie sprawdz czy w tablicy wyst�puje liczba x, podana jako parametr do funkcji.
    int tab2[] = {1, 6, 7, 234, 631, 37, 832, 16, 15};
    int tabLenght2 = sizeof(tab2) / sizeof(int);
    printf("czy jest w tablicy: %d", szukanie(tab2, tabLenght2, 6786));


    return 0;
}
