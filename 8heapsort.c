#include <stdio.h>
#include <stdlib.h>

#include <time.h>

void heapify(int a[], int n, int i);
void buildheap(int a[], int n);
void heapsort(int a[], int n);

int main()
{
    int n;
    clock_t start, end, time1;
    double ctu;
    printf("Enter the size: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % (100 - 10 + 1)) + 10;
        printf("%d ", a[i]);
    }
    start = clock();
    heapsort(a, n);
    end = clock();
    time1 = end - start;
    ctu = (double)time1 / CLOCKS_PER_SEC;
    printf("\nSorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nTime taken: %F \n", ctu);
}

void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] < a[largest])
    {
        largest = left;
    }
    if (right < n && a[right] < a[largest])
        largest = right;
    if (largest != i)
    {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        heapify(a, n, largest);
    }
}

void buildheap(int a[], int n)
{
    for (int i = n / 2; i >= 0; i++)
        heapify(a, n, i);
}
void heapsort(int a[], int n)
{
    buildheap(a, n);
    for (int i = n - 1; i > 0; i--)
    {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, i, 0);
    }
}
