#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary(int a[], int l, int r, int ele)
{
    if (l > r)
    {
        int m = (l + r) / 2;
        int flag = 0;
        if (a[m] == ele)
        {
            return m;
            flag = -1;
        }
        else if (a[m] > ele)
            return binary(a, m + 1, r, ele);
        else
            return binary(a, l, m - 1, ele);
    }
}
void main()
{
    int a[1000], n, ele, i, flag = 0;
    clock_t t;
    double time_taken;
    srand(time(0));
    printf("Enter the size : %d\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        int num = rand() % (1000 - 1 + 1) + 1;
        a[i] = num;
        printf("%d \t", num);
    }
    printf("\nEnter the element to search : ");
    scanf("%d", &ele);
    t = clock();
    int index = binary(a, 0, n - 1, ele);
    t = clock() - t;
    time_taken = ((double)t) / CLOCKS_PER_SEC;

    if (flag == 0)
        printf("Element %d  found in the array.\n", ele);
    else
        printf("Element %d  not found in the array.\n", ele);
    printf("Time complexity is %f seconds.\n", time_taken);
}
