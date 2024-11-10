#include <stdio.h>
#include <stdlib.h>
void main()
{
    int e, i, a[10000], n, lower = 10, upper = 100, j, t;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++)
    {
        a[i] = (rand() % (upper - lower + 1)) + lower;
        printf("%d ", a[i]);
    }
    for(i = 1; i < n; i++)
    {
        e = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > e)
        {
            t = t + 1;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = e;
    }
    printf("\nSorted array :\n" );
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    
    }
    printf("time complexity is %d\n", t);

}

