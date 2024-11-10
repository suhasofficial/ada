#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int t = 0, lower = 10, upper = 100;
    long int f;
    srand(time(0));
    int a[100], i, j, size, small, temp;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Array elements are:\n");
    // Generate random elements and print them
    for (i = 0; i < size; i++)
    {
        a[i] = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", a[i]);
    }

    // Selection Sort Algorithm
    for (i = 0; i < size - 1; i++)
    {
        small = i;
        for (j = i + 1; j < size; j++)
        {        // Ensure we don't go out of bounds
            t++; // Count the number of comparisons
            if (a[j] < a[small])
            {
                small = j;
            }
        }

        // Swap the smallest element found with the element at position i
        if (small != i)
        {
            temp = a[i];
            a[i] = a[small];
            a[small] = temp;
        }
    }

    // Print the sorted array
    printf("\nSorted array: \n");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nTime complexity (number of comparisons): %d\n", t);

    return 0;
}
