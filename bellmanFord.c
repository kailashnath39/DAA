#include <stdio.h>
#include <stdlib.h>
#define INF 999

// int checkIncomingEdge(int **cost,int u,int n)
// {
//     for(int i=0;i<n;i++)
//         if(cost[i][u] != 0 && cost[i][u] < INF)
//             return 1;
//     return 0;
// }

void shortestPath(int v,int **cost,int *dist,int n)
{
    /**
     * This function finds the shortest distance From source to the other vertices
     * Every iteration we will consider or increase the number of edges between the 
     * two vertices or we will see the incoming edges and see if there is 
     * anywhere to reduce the cost in this way. At every iteration, 
     * we will update the previously selected vertices which overcomes 
     * the drawback of dijkstras algorithm.
     * 
     * 
     * There is no need of checking of incoming edge, because 
     * the inner loop itself chekcs the incoming edge
    */
    int i,k,w,u;
    for(i=0;i<n;i++)
        dist[i] = cost[v][i];
    for(k=2;k<n;k++)
        for(u=0;u<n;u++)
            if(u!=v)
            {
                for(i=0;i<n;i++)
                {
                    if(cost[i][u] != 0 && cost[i][u] < INF)
                    {
                        if(dist[u] > dist[i] + cost[i][u])
                            dist[u] = dist[i] + cost[i][u];
                    }
                }
            }
}

int main()
{
    int v,n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **cost = (int **)malloc(n * sizeof(int *));
    printf("Enter the costs : \n");
    for (int i = 0; i < n; ++i) 
    {
        cost[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%d",&cost[i][j]);
    }
    printf("Enter the source vertex : ");
    scanf("%d",&v);
    v--;
    int *dist = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        dist[i] = cost[v][i];
    shortestPath(v,cost,dist,n);
    printf("the distance among source to every other vertex are : \n");
    for(int i=0;i<n;i++)
    {
        if(i == v){continue;}
        printf("%d - %d --> %d\n",v+1,i+1,dist[i]);
    }
    free(cost);
    free(dist);
    return 0;
}


// 0 6 5 5 999 999 999 
// 999 0 999 999 -1 999 999
// 999 -2 0 999 1 999 999
// 999 999 -2 0 999 -1 999
// 999 999 999 999 0 999 3
// 999 999 999 999 999 0 3
// 999 999 999 999 999 999 0

// 0 2 4 999 999 999 
// 999 0 -3 1 5 999
// 999 999 0 -4 -2 999
// 999 999 999 0 999 8
// 999 999 999 4 0 6
// 999 999 999 999 999 0