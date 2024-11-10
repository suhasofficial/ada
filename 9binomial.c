#include<stdio.h>

int min(int i , int k){
    if(i < k)
        return i;
    else
        return k;
}

int bcdynamic(int n , int k )
{
    int c[n + 1][k + 1];
    int i, j;
    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= min(i,k); j++)
        {
            if (j == 0 || j == i)
            {
                c[i][j] = 1;

            }
            else{
                c[i][j] = c[i-1][j-1]+ c[i-1][j];
            }
        }
    }
    return c[n-1][k-1]+c[n-1][k];
}

int main(){
    int n, k;
    printf("Enter the value of n ");
    scanf("%d",&n);
    printf("Enter the value of k ");
    scanf("%d", &k);
    int bc = bcdynamic(n, k);
    printf("binomial coefficent is : %d\n",bc);
    return 0;
}
