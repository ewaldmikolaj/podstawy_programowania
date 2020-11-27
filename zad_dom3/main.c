#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

float FtoC(float n);
float FtoK(float n);
float CtoF(float n);
float CtoK(float n);
float KtoC(float n);
float KtoF(float n);
int checkInput(int a, int b);
bool sprawdz(float temp, char stopnie);
float input(char z);
void save(float input, float output, char in, char out, int index, bool increase);
void history();
void showRow();
void del();
bool checkModify(char c, char blocked, int index);
float modifyValues(char a, char b, float n);
void modify();
void modifyDumb();
char randomChar();
void randomArray();
void randomArrayDumb();

float valUser[20];
float valProg[20];
char sysUser[20];
char sysProg[20];
int currIndex = 0;

int main()
{
    int operation;
    float temp, result;
    srand(time(NULL));

    while (true)
    {
        printf(" 1.Przelicz F na C \n 2.Przelicz F na K \n 3.Przelicz C na F \n 4.Przelicz C na K \n 5.Przelicz K na C \n 6.Przelicz K na F \n 7.Pokaz historie \n 8.Pokaz zakres w historii \n 9.Usun wiersz z historii \n 10.Modyfikowanie wartosci \n 11.Modyfikowanie nieinteligentne \n 12.Losowanie inteligentne \n 13.Losowanie nieinteligentne  \n 14.Zakoncz dzialanie \n Co chcesz zrobic: \n");
        operation = checkInput(1, 14);

        switch(operation)
        {
            case 1:
                temp = input('F');
                result = FtoC(temp);
                printf("%0.2fF na C to %0.2f \n \n", temp, result);
                save(temp, result, 'F', 'C', currIndex, true);
                break;
            case 2:
                temp = input('F');
                result = FtoK(temp);
                printf("%0.2fF na K to %0.2f \n \n", temp, result);
                save(temp, result, 'F', 'K', currIndex, true);
                break;
            case 3:
                temp = input('C');
                result = CtoF(temp);
                printf("%0.2fC na F to %0.2f \n \n", temp, result);
                save(temp, result, 'C', 'F', currIndex, true);
                break;
            case 4:
                temp = input('C');
                result = CtoK(temp);
                printf("%0.2fC na K to %0.2f \n \n", temp, result);
                save(temp, result, 'C', 'K', currIndex, true);
                break;
            case 5:
                temp = input('K');
                result = KtoC(temp);
                printf("%0.2fK na C to %0.2f \n \n", temp, result);
                save(temp, result, 'K', 'C', currIndex, true);
                break;
            case 6:
                temp = input('K');
                result = KtoF(temp);
                printf("%0.2fK na F to %0.2f \n \n", temp, result);
                save(temp, result, 'K', 'F', currIndex, true);
                break;
            case 7:
                history();
                break;
            case 8:
                showRow();
                break;
            case 9:
                del();
                break;
            case 10:
                modify();
                break;
            case 11:
                modifyDumb();
                break;
            case 12:
                randomArray();
                break;
            case 13:
                randomArrayDumb();
                break;
            case 14:
                exit(0);
            default:
                printf("Nie ma takiej opcji, wybierz co innego! \n");
                break;
        }
    }
    return 0;
}

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

int checkInput(int a, int b)
{
    int n;
    char *pom, string[100];
    do {
        printf("Wybierz (od %d do %d): ", a, b);
        while (fgets(string, sizeof(string), stdin)) {
            n = strtol(string, &pom, 10);
            if (pom == string || *pom != '\n')
            {
                printf("Wybierz (od %d do %d): ", a, b);
            }
            else
                break;
        }
    } while((n < a) || (n > b));

    return n;
}

bool sprawdz(float temp, char stopnie)
{
    if (((temp < 0) && (stopnie == 'K')) || ((temp < -273.15) && (stopnie == 'C')) || ((temp < -469.67) && (stopnie == 'F')))
        return true;
    return false;
}

float input(char z)
{
    float a;
    printf("podaj temperature w %c: ", z);
    scanf("%f", &a);
    while (sprawdz(a, z))
    {
        printf("Podales zla temperature. Sprobuje jeszcze raz: ");
        scanf("%f", &a);
    }
    return a;
}

void save(float input, float output, char in, char out, int index, bool increase)
{
    if (index < 20)
    {
        valUser[index] = input;
        valProg[index] = output;
        sysUser[index] = in;
        sysProg[index] = out;
        if (increase){
            currIndex++;
        }
    } else
    {
        printf("Twoja historia jest pelna. Przeliczenie nie zostanie zapisane. \n");
    }
}

void history()
{
    if (currIndex == 0)
    {
        printf(" brak historii \n \n");
    } else
    {
        printf("\n");
        for (int i = 0; i < currIndex; i++)
        {
            printf("#%2.0d %0.2f%c  -->  %0.2f%c \n", i + 1, valUser[i], sysUser[i], valProg[i], sysProg[i]);
        }
        printf("\n");
    }
}

void del()
{
    if (currIndex == 0)
    {
        printf("Nie mozesz niczeog usunac, bo nie ma zadnej historii \n");
    } else
    {
        bool flaga = true;
        while (flaga)
        {
            int index;
            printf("podaj index do usuniecia od 1 do %d: \n", currIndex);
            index = checkInput(1, currIndex);
            index = index - 1;
            valUser[index] = 0;
            valProg[index] = 0;
            sysUser[index] = 0;
            sysProg[index] = 0;
            for (int i = index; i < currIndex - 1; i++)
            {
                valUser[i] = valUser[i + 1];
                valProg[i] = valProg[i + 1];
                sysUser[i] = sysProg[i + 1];
                sysProg[i] = sysProg[i + 1];
            }
            currIndex--;
            printf("\nUsuwanie zakonczone \n");
            history();

            if (currIndex != 0)
            {
                int goNext;
                printf("chcesz dalej usuwac: \n 1. tak \n 2. nie \n");
                goNext = checkInput(1, 2);
                if (goNext == 2)
                {
                    flaga = false;
                }
            } else
            {
                flaga = false;
            }
        }
    }
}

bool checkModify(char c, char blocked, int index)
{
    if (c == blocked)
    {
        return true;
    } else if ((c == 'K') || (c == 'F') || (c =='C'))
    {
        return false;
    } else
    {
        return true;
    }

}

float modifyValues(char a, char b, float n)
{
    if (a == 'F' && b == 'C') {
        return FtoC(n);
    }
    if (a == 'F' && b == 'K') {
        return FtoK(n);
    }
    if (a == 'C' && b == 'F') {
        return CtoF(n);
    }
    if (a == 'C' && b == 'K') {
        return CtoK(n);
    }
    if (a == 'K' && b == 'C') {
        return KtoC(n);
    }
    if (a == 'K' && b == 'F') {
        return KtoF(n);
    }
    return 0;
}

void modify()
{
    printf("\n");
    if (currIndex == 0)
    {
        printf("pusta historia \n");
    } else
    {
        history();
        int index;
        printf("podaj ktory indeks chcesz modyfikowac od 1  do %d: ", currIndex);
        index = checkInput(1, currIndex);
        index -= 1;

        printf("Wybrales: #%2.0d %0.2f%c  -->  %0.2f%c \n", index + 1, valUser[index], sysUser[index], valProg[index], sysProg[index]);

        int value;
        printf("\n 1. Wartosci podana przez uzytkownika \n 2. Wartosci obliczone przez program \n Co chcesz zmodyfikowac: ");
        value = checkInput(1, 2);

        float replValue, result;
        char replC;

        switch(value)
        {
            case 1:
                printf("Na co chcesz zmienic wartosc %0.2f%c: \n", valUser[index], sysUser[index]);

                do {
                    printf("na jaki znak chcesz zmienic %c (oprocz %c): ", sysUser[index], sysProg[index]);
                    scanf(" %c", &replC);
                }while(checkModify(replC, sysProg[index], index));

                replValue = input(replC);
                result = modifyValues(replC, sysProg[index], replValue);
                save(replValue, result, replC, sysProg[index], index, false);
                printf("Modyfikacja zakonczona pomyslnie \n \n");
                break;
            case 2:
                printf("Na co chcesz zmienic wartosc %0.2f%c: ", valProg[index], sysProg[index]);

                do{
                    printf("na jaki znak chcesz zmienic %c (oprocz %c): ", sysProg[index], sysUser[index]);
                    scanf(" %c", &replC);
                }while(checkModify(replC, sysUser[index], index));

                replValue = input(replC);
                result = modifyValues(replC, sysUser[index], replValue);
                save(result, replValue, sysUser[index], replC, index, false);
                printf("Modyfikacja zakonczona pomyslnie \n \n");
                break;
            default:
                printf("Nie ma czegos takiego \n \n");
                break;
        }
    }
}

void modifyDumb()
{
    printf("\n");
    if(currIndex == 0)
    {
        printf("pusta historia \n \n");
    } else
    {
        history();
        int index;
        printf("podaj ktory indeks chcesz modyfikowac od 1  do %d: ", currIndex);
        index = checkInput(1, currIndex);
        index -= 1;

        printf("Wybrales: #%2.0d %0.2f%c  -->  %0.2f%c \n", index + 1, valUser[index], sysUser[index], valProg[index], sysProg[index]);

        int value;

        float replaceValue;
        char replaceSystem;
        bool flaga = true;

        while (flaga)
        {
            printf("\n 1. Wartosci podana przez uzytkownika \n 2. Znak uzytkownika \n 3. Wartosci obliczone przez program \n 4. Znak programu \n 5. Zakoncz modyfikacje \n Co chcesz zmodyfikowac: ");
            value = checkInput(1, 5);
            switch(value)
            {
                case 1:
                    printf("podaj temperature w %c: ", sysUser[index]);
                    replaceValue = input(sysUser[index]);
                    valUser[index] = replaceValue;
                    printf("Modyfikacja zakonczona pomyslnie \n \n");
                    break;
                case 2:
                    printf("podaj znak (K, F, C): ");
                    do{
                        printf("podaj znak (K, F, C): ");
                        scanf(" %c", &replaceSystem);
                    }while(checkModify(replaceSystem, '0', index));
                    sysUser[index] = replaceSystem;
                    printf("Modyfikacja zakonczona pomyslnie \n \n");
                    break;
                case 3:
                    printf("podaj temperature w %c: ", sysProg[index]);
                    replaceValue = input(sysProg[index]);
                    valUser[index] = replaceValue;
                    printf("Modyfikacja zakonczona pomyslnie \n \n");
                    break;
                case 4:
                    printf("podaj znak (K, F, C): ");
                    do{
                        printf("podaj znak (K, F, C): ");
                        scanf(" %c", &replaceSystem);
                    }while(checkModify(replaceSystem, '0', index));
                    sysProg[index] = replaceSystem;
                    printf("Modyfikacja zakonczona pomyslnie \n \n");
                    break;
                case 5:
                    flaga = false;
                    printf("\n");
                    break;
                default:
                    printf("Nie ma czegos takiego");
                    break;
            }
        }

    }
}

char randomChar()
{
    int random = rand() % 3;
    if (random == 0)
        return 'K';
    if (random == 1)
        return 'F';
    if (random == 2)
        return 'C';
    return '1';
}

void randomArrayDumb()
{
    float randomUser, randomProgram;
    char randomUserChar, randomProgramChar;
    for(int i = 0; i < 20; i++)
    {
        randomUserChar = randomChar();
        do{
            randomProgramChar = randomChar();
        }while(randomUserChar == randomProgramChar);
        do{
            randomUser = -500.00 + (float) rand() / RAND_MAX*(500.00 - (-500.00));
        }while(sprawdz(randomUser, randomUserChar));
        do{
            randomProgram = -500.00 + (float) rand() / RAND_MAX*(500.00 - (-500.00));
        }while(sprawdz(randomProgram, randomProgramChar));

        valUser[i] = randomUser;
        valProg[i] = randomProgram;
        sysUser[i] = randomUserChar;
        sysProg[i] = randomProgramChar;

    }
    printf("\n Wypelnianie historii losowymi wartosciami!!! \n (obliczenia moga sie nie zgadzac) \n \n");
    currIndex = 20;
}

void randomArray()
{
    float randomUser, result;
    char randomUserChar, randomProgramChar;
    for(int i = 0; i < 20; i++)
    {
        randomUserChar = randomChar();
        do{
            randomProgramChar = randomChar();
        }while(randomUserChar == randomProgramChar);
        do{
            randomUser = -500.00 + (float) rand() / RAND_MAX*(500.00 - (-500.00));
        }while(sprawdz(randomUser, randomUserChar));
        result = modifyValues(randomUserChar, randomProgramChar, randomUser);

        valUser[i] = randomUser;
        valProg[i] = result;
        sysUser[i] = randomUserChar;
        sysProg[i] = randomProgramChar;
    }
    printf("\n Wypelnianie historii losowymi wartosciami!!! \n (obliczenia sie zgadzaja) \n \n");
    currIndex = 20;
}

void showRow()
{
    if (currIndex == 0)
    {
        printf("\n brak historii \n \n");
    } else
    {
        printf("Od ktorego do ktorego wiersza chcesz wyswietlic (mozesz od 1 do %d): \n", currIndex);
        int rowF, rowL;
        printf("od: ");
        scanf("%d", &rowF);
        printf("do: ");
        scanf("%d", &rowL);
        while((rowF < 0) || (rowL < 0) || (rowF > rowL) || (rowF > currIndex) || (rowL > currIndex))
        {
            if(rowF < 0)
                printf("pierwsza wartosc nie moze byc mniejsza od zera \n");
            if(rowL < 0)
                printf("druga wartosc nie moze byc mniejsza od zera \n");
            if(rowF > rowL)
                printf("pierwsza wartosc nie moze byc wieksza od drugiej \n");
            if(rowF > currIndex)
                printf("piewsza wartosc nie moze byc wieksza niz zakres \n");
            if(rowL > currIndex)
                printf("druga wartosc nie moze byc wieksza niz zakres \n");
            printf("podaj jeszzcze raz (mozesz od 1 do %d): \n", currIndex);
            printf("od: ");
            scanf("%d", &rowF);
            printf("do: ");
            scanf("%d", &rowL);
        }

        for (int i = rowF - 1; i < rowL; i++)
        {
            printf("#%2.0d %0.2f%c  -->  %0.2f%c \n", i + 1, valUser[i], sysUser[i], valProg[i], sysProg[i]);
        }
        printf("\n");
    }
}


