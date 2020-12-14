#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

double avg(double *arr, int n);
void maxV(double *arr, int n, double *max);

int main()
{
    int n, k;
    double sum = 0;
    int sumOfK = 0;
    double max = -1000;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        sumOfK += k;
        double* ptr1 = (double*)malloc(k * sizeof(double));
        for (int j = 0; j < k; j++) {
            scanf("%lf", ptr1 + j);
            sum += *(ptr1 + j);
        }
        maxV(ptr1, k, &max);
        printf("srednia zbioru %d: %0.2lf\n", i + 1, avg(ptr1, k));
        free(ptr1);
    }

    printf("srednia ze wszystkich: %0.2lf\n", sum / sumOfK);
    printf("najwiekszy element: %lf", max);


    return 0;
}

double avg(double *arr, int n) {
    double sum = 0;
    for(int i = 0; i < n; i++) 
        sum += *(arr + i);
    return sum / n;
}

void maxV(double *arr, int n, double *max) {
    for (int i = 0; i < n; i++) {
        if (*(arr + i) > *max)
            *max = *(arr + i);
    }
}