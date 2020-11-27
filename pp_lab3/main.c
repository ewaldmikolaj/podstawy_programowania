#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

float funkcja(float fahr);
void dzielniki(int n);
float FtoC(float n);
float FtoK(float n);
float CtoF(float n);
float CtoK(float n);
float KtoC(float n);
float KtoF(float n);
bool sprawdz(float temp, char stopnie);

int main()
{
    //zadanie 3
    /*int n;
    do {
        printf("podaj liczbe: ");
        scanf("%d", &n);
    } while (n <= 0);
    dzielniki(n);*/

    //zadanie 5
    long operation;
    //char *pom, string[100];
    float temp;

    while(true) {
        printf(" 1.Przelicz F na C \n 2.Przelicz F na K \n 3.Przelicz C na F \n 4.Przelicz C na K \n 5.Przelicz K na C \n 6.Przelicz K na F \n 7.Zakoncz dzialanie \n co chcesz zrobic: ");
        scanf("%d", &operation);
        //¿eby zabezpieczy program przed wprowadzaniem string albo entera alb znaków zamiast scanf u¿ywam fgets i wyciagam z niego liczbe za pomoca strtol.
        //ale zostawilem to zakomentowane, poniewaz nie jestem az tak doscwiadczony w C, zeby sam wpasc na takie rozwiazanie
        //wpadlem na nie po przegladaniu stackoverflow, a wlasciwie to troche przerobilem rozwiazanie innej osoby
        //dlatego zostawiam je zakomentowane
        //poniewa¿ tego programu nie mielismy jeszcze zabezpieczac wiec zostawiam z scanfem

        /*while (fgets(string, sizeof(string), stdin)) {
            operation = strtol(string, &pom, 10);
            if (pom == string || *pom != '\n')
            {
                printf("Wbisz liczbe od 1 do 7: ");
            }
            else
                break;
        }*/

        switch(operation)
        {
            case 1:
                printf("podaj temperature w F:");
                scanf("%f", &temp);
                if (sprawdz(temp, 'F'))
                    printf("poczatkowa: %0.2fF przeliczona: %0.2fC \n \n", temp, FtoC(temp));
                else
                    printf("Nie ma takiej temperatury \n \n");
                break;
            case 2:
                printf("podaj temperature w F:");
                scanf("%f", &temp);
                if (sprawdz(temp, 'F'))
                    printf("poczatkowa: %0.2fF przeliczona: %0.2fK \n \n", temp, FtoK(temp));
                else
                    printf("Nie ma takiej temperatury \n \n");
                break;
            case 3:
                printf("podaj temperature w C:");
                scanf("%f", &temp);
                if (sprawdz(temp, 'C'))
                    printf("poczatkowa: %0.2fC przeliczona: %0.2fF \n \n", temp, CtoF(temp));
                else
                    printf("Nie ma takiej temperatury \n \n");
                break;
            case 4:
                printf("podaj temperature w C:");
                scanf("%f", &temp);
                if (sprawdz(temp, 'C'))
                    printf("poczatkowa: %0.2fC przeliczona: %0.2fK \n \n", temp, CtoK(temp));
                else
                    printf("Nie ma takiej temperatury \n \n");
                break;
            case 5:
                printf("podaj temperature w K:");
                scanf("%f", &temp);
                if (sprawdz(temp, 'K'))
                    printf("poczatkowa: %0.2fK przeliczona: %0.2fC \n \n", temp, KtoC(temp));
                else
                    printf("Nie ma takiej temperatury \n \n");
                break;
            case 6:
                printf("podaj temperature w K:");
                scanf("%f", &temp);
                if (sprawdz(temp, 'K'))
                    printf("poczatkowa: %0.2fK przeliczona: %0.2fF \n \n", temp, KtoF(temp));
                else
                    printf("Nie ma takiej temperatury \n \n");
                break;
            case 7:
                exit(0);
            default:
                printf("Nie ma takiego numeru \n \n");
        }
    }
    return 0;
}

//zadanie 3
void dzielniki(int n)
{
    int i;
    for (i = 1; i < n/2; i++) {
        if (n % i == 0)
            printf("%d \t", i);
            printf("%d \t", -i);
    }
    printf("%d \t", n);
    printf("%d", -n);
}

//zadanie 5
float FtoC(float n)
{
    return (n - 32.0) * 5.0/9.0;
}

float FtoK(float n)
{
    return (n + 459.67) * 5.0/9.0;
}

float CtoF(float n)
{
    return n * 9.0/5.0 + 32.0;
}

float CtoK(float n)
{
    return n + 273.15;
}

float KtoC(float n)
{
    return n - 273.15;
}

float KtoF(float n)
{
    return n * 9.0/5.0 - 459.67;
}

bool sprawdz(float temp, char stopnie)
{
    switch(stopnie)
    {
        case 'K':
            if (temp < 0)
                return false;
            else
                return true;
        case 'C':
            if (temp < -273.15)
                return false;
            else
                return true;
        case 'F':
            if (temp < -469.67)
                return false;
            else
                return true;
        default:
            return false;
    }
    return true;
}

