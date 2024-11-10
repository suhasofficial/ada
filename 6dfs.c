#include <stdio.h>
void dfs(int adj[][100], int i, int n)
{
    int j, s[100], top = -1, k, flag = 0, visited[100];   
    for (k = 0; k < n; k++)
    {
        visited[k] = 0;
    }
 
    s[++top] = i;
    visited[i] = 1;
    printf("dfs visited: %d\n", i);
    while (top != -1)
    {
        i = s[top]; 
        flag = 0;

     
        for (j = 0; j < n; j++)
        {
            if (adj[i][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;                
                s[++top] = j;                   
                printf("dfs visited: %d\n", j); 
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            top--;
        }
    }
}

int main()
{
    int adj[100][100], n, i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");

    // Input adjacency matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
 
    printf("\nDFS Traversal:\n");
    dfs(adj, 0, n); 
    return 0;
}
