#include<stdio.h>
#define inf 999
int n;

int findMin(int near[],int cost[][n+1])
{
    int j=1,i=1;
    while(near[i++] == 0);
    j = i-1;
    for(i=j;i<=n;i++)
    {
        if(near[i] != 0 &&
        cost[i][near[i]] < cost[j][near[j]])
        {
            j = i;
        }
    }
    return(j);
}

int main()
{
    printf("enter the no. of vertices : ");
    scanf("%d",&n);
    int cost[n+1][n+1],t[n][2];
    int near[n+1],mincost = inf,i,j,k,l;
    printf("enter the costs:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&cost[i][j]);
    for(i=0;i<=n;i++)
        cost[i][0] = cost[0][i] = 0;
    

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(cost[i][j] != 0 && cost[i][j] < mincost)
            {
                mincost = cost[i][j];
                k = i;l = j;
            }
        }
    for(i=1;i<=n;i++)
    {
        if(cost[i][k] < cost[i][l])
            near[i] = k;
        else
            near[i] = l;
    }
    near[k] = near[l] = 0;
    t[0][0] = k;t[0][1] = l;
    for(i=2;i<n;i++)
    {
        int j = findMin(near,cost);
        t[i-1][0] = j;t[i-1][1] = near[j];
        mincost += cost[j][near[j]];
        near[j] =0;
        for(int k=1;k<=n;k++)
        {
            if(near[k]!=0 && cost[k][j] < cost[k][near[k]])
            {
                near[k] = j;
            }
        }
    }
    printf("min cost : %d \n",mincost);
    printf("the spanning tree is :\n");
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }
}





// 0 28 999 999 999 10 999
// 28 0 16 999 999 999 16
// 999 16 0 12 999 999 999
// 999 999 12 0 22 999 18
// 999 999 999 22 0 25 24
// 10 999 999 999 25 0 999
// 999 14 999 18 24 999 0

// 0 5 999 4 999 999 999 999 
// 5 0 999 999 1 999 999 999 
// 999 999 0 1 3 1 999 999 
// 4 999 1 0 999 999 999 2
// 999 1 3 999 0 999 6 999 
// 999 999 1 999 999  0 4 10
// 999 999 999 999 6 4 0 2
// 999 999 999 2 999 10 2 0

