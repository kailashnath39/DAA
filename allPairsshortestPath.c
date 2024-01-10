#include <stdio.h>
#include <stdlib.h>
#define INF 999

int min(int a,int b){return a<b?a:b;}

void allPairsShortestPath(int **cost,int **A,int n)
{
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            A[i][j] = cost[i][j];
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
}

int main()
{
    int i,j,n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **cost = (int **)malloc(n * sizeof(int *));
    int **A = (int **)malloc(n * sizeof(int *));
    printf("Enter the weights : \n");
    for (i = 0; i < n; ++i) 
    {
        cost[i] = (int *)malloc(n * sizeof(int));
        A[i] = (int *)malloc(n * sizeof(int));
        for (j = 0; j < n; ++j)
            scanf("%d",&cost[i][j]);
    }
    allPairsShortestPath(cost,A,n);
    printf("the shortest path from any node to any other node is : \n  ");
    for(i=0;i<n;i++)
        printf("%d ",i+1);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",i+1);
        for(j=0;j<n;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }
}


// 0 4 11 
// 6 0 2
// 3 999 0

// 0 3 8 999 -4 
// 999 0 999 1 7
// 999 4 0 999 999
// 2 999 -5 0 999
// 999 999 999 6 0

