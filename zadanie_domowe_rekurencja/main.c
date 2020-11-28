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
    //Zad 1. Napisz program obliczania sumy cyfr dziesiêtnych dla zadanej z klawiatury liczby n (iteracyjnie, rekurencyjnie).
    printf("suma: %d \n", sumaI(555));
    printf("suma: %d \n", sumaR(555));

    //Zad 2. Napisz program obliczania sumy cyfr dziesiêtnych, ale tylko parzystych dla zadanej z klawiatury liczby n (iteracyjnie, rekurencyjnie).
    printf("suma parzystych: %d \n", sumaParzystychI(22));
    printf("suma parzystych: %d \n", sumaParzystychR(555));

    //Zad 3. Napisz funkcjê, która wypisze w odwrotnej kolejnoœci znaki wczytane z klawiatury. Przyk³adowo,
    //gdy zadany ci¹g to: [1, 2, 3, a, c, b] program powinien wypisaæ: [b, c, a, 3, 2, 1].
    char tab[] = {'a', 'b', 'c', '1', '2', '3'};
    int tabLenght = sizeof(tab) / sizeof(*tab) + 1;
    printf("odwrotnie:");
    odwrotnieR(tab, tabLenght);
    printf("\n");

    //Zad 4. Napisz program w którym zadeklarujesz tablicê o d³ugoœci n, wype³nij j¹ wartoœciami losowymi
    //i zaimplementuj rekurencyjny algorytm sortowania metod¹ podzia³u na dwie czêœci.


    //Zad 5. Napisz program w którym zadeklarujesz tablicê o d³ugoœci n, a nastêpnie sprawdz czy w tablicy wystêpuje liczba x, podana jako parametr do funkcji.
    int tab2[] = {1, 6, 7, 234, 631, 37, 832, 16, 15};
    int tabLenght2 = sizeof(tab2) / sizeof(int);
    printf("czy jest w tablicy: %d", szukanie(tab2, tabLenght2, 6786));


    return 0;
}
