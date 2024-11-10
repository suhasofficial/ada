
#include <stdio.h>
void floyd(int w[100][100], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i != k && j != k && i != j)
                {
                    if (w[i][j] > w[i][k] + w[k][j])
                        w[i][j] = w[i][k] + w[k][j];
                }
            }
        }
    }
}
void main()
{
    int n, w[100][100], i, j;
    printf("enter number of vertices\n");
    scanf("%d", &n);
    printf("enter weighted matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }
    floyd(w, n);
    printf("distance matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", w[i][j]);
        }
        printf("\n");
    }
}
