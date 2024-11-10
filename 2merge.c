#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
void mergesort(int[], int, int);
void merge(int[], int, int, int);

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}
void merge(int a[], int l, int m, int r)
{
    int fp = l, sp = m + 1, k = l, b[100000], j;
    while (fp <= m && sp <= r)
    {
        if (a[fp] <= a[sp])
        {
            b[k] = a[fp];
            fp++;
            k++;
        }
        else
        {
            b[k] = a[sp];
            sp++;
            k++;
        }
    }
    if (sp > r)
    {
        for (j = fp; j <= m; j++)
        {
            b[k] = a[j];
            k++;
        }
    }
    for (j = l; j <= r; j++)
    {
        a[j] = b[j];
    }
}

void main()
{
    int a[100000], n, i, l, r;
    clock_t start, end, time1;
    double ctu;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        a[i] = (rand() % (1000 - 10 + 1)) + 10;
        printf("%d ", a[i]);
    }
    r = n - 1;
    start = clock();
    mergesort(a, l, r);
    end = clock();
    ctu = (double)(end - start) / CLOCKS_PER_SEC;
    for (i = 0; i < n; i++)
    {
        // printf("sorted array %d ", a[i]);
    }
    printf("\nTime taken for Merge Sort: %f seconds\n", ctu);
}
