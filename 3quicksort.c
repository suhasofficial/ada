#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void quicksort(int[], int, int);
int part(int[], int, int);

void main()
{
    int a[1000], n, i, l, r;
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
    quicksort(a, l, r);
    end = clock();
    ctu = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted array: ");
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);

    }
    printf("\nTime taken for Quick Sort: %f seconds\n", ctu);
}


void quicksort(int a[], int l, int r)
{
    if (l<r)
    {
        int s= part(a,l,r);
        quicksort(a, l, s-1);
        quicksort(a, s+1, r);
    }
}

int part(int a[], int l, int r){
  
    int i = (l - 1);
    int j = r+1;
    int pivot = a[r];
    int t;

    for (int j = l; j <= r - 1; j++)
    {
        t++;
        if (a[j] <= pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;

    return (i + 1);
}
