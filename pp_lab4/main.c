#include <stdio.h>
#include <stdlib.h>

void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    if (n == 0)
    {
        printf("0");
    }
    if (n == 1)
    {
        printf("1");
    }
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            b += a;
            a = b - a;
            printf("%d    ", b);
        }
    }
}

void srednia(int tab[], int n)
{
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%d \t", tab[i]);
        suma += tab[i];
    }
    printf("\nsrednia %d", suma / n);
}


int main()
{
    //zad 3.1
    /*int tab[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &tab[i]);
    }

    for (int i = 9; i >= 0; i--)
    {
        printf("%d \t", tab[i]);
    }*/

    //zad 3.2
    /*int n;
    scanf("%d", &n);
    fibonacci(n);
    printf("\n");*/

    //zad 3.3
    int n;
    scanf("%d", &n);
    srand(time(NULL));
    int tab[n];
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 10;
    }
    srednia(tab, n);

   return 0;
}
