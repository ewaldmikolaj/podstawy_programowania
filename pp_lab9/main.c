#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int sum(int* arr1, int* arr2, int n);
int multi(int* arr1, int* arr2, int n);

int main()
{
    int n;
    scanf("%d", &n);
    int* ptr1 = (int*)malloc(n * sizeof(int));
    int* ptr2 = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        printf("tablica pierwsza: ");
        scanf("%d", ptr1 + i);
        printf("tablica druga: ");
        scanf("%d", ptr2 + i);
    }

    sum(ptr1, ptr2, n);
    multi(ptr1, ptr2, n);

    free(ptr1);
    free(ptr2);
    return 0;
}

int sum(int* arr1, int* arr2, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum = *(arr1 + i) + *(arr2 + i);
        printf("suma elementu %d: %d\n", i + 1, sum);
    } 
}

int multi(int* arr1, int* arr2, int n) {
    int multiplication = 1;
    for (int i = 0; i < n; i++) {
        multiplication = *(arr1 + i) * *(arr2 + i);
        printf("iloczyn elementu %d: %d\n", i + 1, multiplication);
    } 
}