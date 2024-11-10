#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    // Use a fixed-size array or dynamic memory allocation
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                K[i][j] = max(val[i - 1] + K[i - 1][j - wt[i - 1]], K[i - 1][j]);
            }
            else
            {
                K[i][j] = K[i - 1][j];
            }
        }
    }

    // Optional: Print the dynamic programming table
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= W; j++)
        {
            printf("%d ", K[i][j]);
        }
        printf("\n");
    }

    return K[n][W];
}

int main()
{
    int val[] = {12,10,20,15};
    int wt[] = {2,1,3,2};
    int W = 5;
    int n = 4;
    printf("Maximum value in Knapsack = %d\n", knapSack(W, wt, val, n));
    return 0;
}
