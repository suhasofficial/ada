
#include <stdio.h>
void warshall(int a[100][100], int n)
{
    int i, j, k;
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i != k && j != k)
                {
                    a[i][j] = a[i][j] || a[i][k] && a[k][j];
                }
            }
        }
    }
}
void main()
{
    int n, a[100][100], i, j;

    printf("enter number of vertices\n");
    scanf("%d", &n);

    printf("enter adjacency  matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    warshall(a, n);
    printf("transitive closure\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}
