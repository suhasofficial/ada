#include <stdio.h>
void bfs(int adj[][100], int i, int n)
{
    int q[100], f = -1, r = -1, visited[100], j, k;
    for (k = 1; k <= n; k++)
    {
        visited[k] = 0;
    }
    visited[i] = 1;
    printf("BFS visited: %d\n", i);
    while (1)
    {
        for (j = 1; j <= n; j++)
        {
            if (adj[i][j] == 0)
            {
                if (visited[j] == 0)
                {
                    visited[j] = 1;
                    q[++r] = j;
                    if (f == -1)
                        f = f + 1;
                    printf("BFS visited: %d\n", j);
                }
            }
        }
        if (f == -1 || f > r)
            break;
        else
            i = q[++f];
    }
}

void main()
{
    int adj[100][100], n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nBFS Traversal:\n");
    bfs(adj, i, n);
}
