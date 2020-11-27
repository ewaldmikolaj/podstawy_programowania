#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long fibonacci(long long n);
long long fibonacci2(long long n);

unsigned long long potega(int p, int n);
unsigned long long potega2(int p, int n);

unsigned long long silnia(int n);
unsigned long long silnia2(int n);

int nwd(int a, int b);
int nwd2(int a, int b);

int nww(int a, int b);
int nww2(int a, int b);

int main()
{
    clock_t start, koniec;

    printf("fibonacci: \n");

    long long n;
    scanf("%lld", &n);
    start = clock();
    printf("wynik: %lld \n", fibonacci(n));
    koniec = clock();
    printf("rekurencja fibonacci w czasie: %f \n", (double)(koniec - start));
    start = clock();
    printf("wynik: %lld \n", fibonacci2(n));
    koniec = clock();
    printf("iteracja fibonacci w czasie: %f \n", (double)(koniec - start));

    printf("potega: \n");

    int p, w;
    scanf("%d %d", &p, &w);
    start = clock();
    printf("wynik: %llu \n", potega(p, w));
    koniec = clock();
    printf("rekurencja potega w czasie: %f \n", (double)(koniec - start));
    start = clock();
    printf("wynik: %llu \n", potega2(p, w));
    koniec = clock();
    printf("iteracja potega w czasie: %f \n", (double)(koniec - start));

    printf("silnia: \n");

    int m;
    scanf("%d", &m);
    start = clock();
    printf("wynik: %llu \n", silnia(m));
    koniec = clock();
    printf("rekurencja silnia w czasie: %f \n", (double)(koniec - start));
    start = clock();
    printf("wynik: %llu \n", silnia2(m));
    koniec = clock();
    printf("iteracja silnia w czasie: %f \n", (double)(koniec - start));

    /*int a, b;
    scanf("%d %d", &a, &b);
    printf("wynik: %d \n", nwd(a, b));
    printf("wynik: %d \n", nwd2(a, b));*/

    /*int a, b;
    scanf("%d %d", &a, &b);
    printf("wynik: %d \n", nww(a, b));
    printf("wynik: %d \n", nww2(a, b));*/


}

long long fibonacci(long long n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n > 1) {
        return fibonacci(n - 2) + fibonacci(n - 1);
    }
    return -1;
}

long long fibonacci2(long long n) {
    long long f[1000];
    f[0] = 0;
    f[1] = 1;
    long long ciag = 0;
    if (n == 0)
        return f[0];
    if (n == 1)
        return f[1];
    for (int i = 2; i <= n; i++) {
        f[i] =  f[i - 1] + f[i - 2];
        ciag = f[i];
    }
    return ciag;
}

unsigned long long potega(int p, int n) {
    if (n == 0)
        return 1;
    if (n == 1)
        return p;
    return p * potega(p, n - 1);
}

unsigned long long potega2(int p, int n) {
    unsigned long long wynik = 1;
    if (n == 0)
        return wynik;
    for (int i = 1; i <= n; i++)
        wynik *= p;
    return wynik;
}

unsigned long long silnia(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * silnia(n - 1);
}

unsigned long long silnia2(int n) {
    unsigned long long tab[1000];
    tab[0] = 0;
    tab[1] = 1;
    unsigned long long wynik;
    if (n == 0)
        return tab[0];
    if (n == 1)
        return tab[1];
    for (int i = 2; i <= n; i++) {
        tab[i] = i * tab[i - 1];
        wynik = tab[i];
    }
    return wynik;
}

int nwd(int a, int b) {
    if (a != b) {
        if (a > b)
            return nwd(a - b, b);
        if (b > a)
            return nwd(a, b - a);
    }
    return a;
}

int nwd2(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int nww(int a, int b) {
    int wynik = a * b / nwd(a, b);
    return wynik;
}

int nww2(int a, int b) {
    int wynik = a * b / nwd2(a, b);
    return wynik;
}

