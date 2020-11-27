#include <stdio.h>
#include <stdlib.h>

int main()
{
    ///zadanie 5.1
    /*printf("M         M    EEEEEEEEEEE\n");
    printf("MM       MM    E\n");
    printf("M M     M M    E\n");
    printf("M  M   M  M    E\n");
    printf("M   M M   M    EEEEEEEEEE\n");
    printf("M    M    M    E\n");
    printf("M         M    E\n");
    printf("M         M    E\n");
    printf("M         M    EEEEEEEEEE\n");*/

    ///zadanie 5.5
    /*int f, c;
    printf("podaj temperature w F: ");
    scanf("%d", &f);

    c = 5 * (f - 32) / 9;
    printf("20 stopni Fahrenheita to %d stopni Celsjusza", c);
    return 0;*/

    ///zadanie 7
    /*float fahr, celsius; //zmienne typu float
    int start, limit, krok; //zmienne typu int

    start = 0; //przypisz 0 do start
    limit = 200; //przypisz 200 do limit
    krok = 20; //przypisz 20 do krok

    fahr = start; //przypisz wartosc start do zmiennej fahr, czyli fahr = 0
    for (fahr = 0.0; fahr <= limit; fahr += krok ) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f \t %6.1f \n", fahr, celsius);
    }*/

    ///zadanie 9.1
    /*float numbers[10];
    int i;
    for (i = 0; i < 10; i++) {
        printf("podaj liczbe numer %d :", i + 1);
        scanf("%f", &numbers[i]);
    }
    for (i = 0; i < 10; i++) {
        if (numbers[i] > 0)
            printf("%0.2f \t", numbers[i]);
    }*/

    ///zadanie 9.3
    /*int number, i;
    printf("podaj liczbe, ktora ma podzielic liczby: ");
    scanf("%d", &number);
    printf("liczb podzielne przez %d \n", number);
    for (i = 1; i < 8; i++) {
        printf("%d \t", i * number);
    }*/

    ///zadanie 9.6
    /*int n, m, i, number;
    printf("ile liczb chcesz wylosowac: ");
    scanf("%d", &n);
    printf("podaj liczbe do ktorej chcesz losowac: ");
    scanf("%d", &m);
    srand(time(NULL));

    printf("wylosowane liczby: ");
    for (i = 0; i < n; i++) {
        number = rand() % m;
        printf("%d \t", number);
    }*/

}





