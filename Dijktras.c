#include<stdio.h>
#include<stdlib.h>
#define INF 999

int minVertex(int *dist, int *s,int n)
{
    int temp = INF,u;
    for(int i=0;i<n;i++)
    {
        if(s[i] == 0 && dist[i] <= temp)
        {
            temp = dist[i];
            u = i;
        }
    }
    return u;
}

void shortestPath(int v,int **cost,int *dist,int n)
{
    /**
     * This function finds the shortest path from source vertex to the all vertices.
     * At every time we only select the vertex only once but not many times 
     * Because if many times allowed, 
     * then selection of minimum vertex will put the loop in an infinite loop.
     * That's where we go for Beellman Ford. And this is the drawback of this algorithm.
    */
    int i,w,u;
    int *s = (int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        s[i] = 0;
        dist[i] = cost[v][i];
    }
    s[v] = 1;
    for(i=2;i<n;i++)
    {
        u = minVertex(dist,s,n);
        s[u] = 1;
        for(w = 0;w < n;w++)
        {
            if(s[w] == 0 && dist[w] > dist[u] + cost[u][w])
            {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
    free(s);
}

int main()
{
    int v,n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **cost = (int **)malloc(sizeof(int *)*n);
    printf("Enter the costs : \n");
    for (int i = 0; i < n; ++i) {
        cost[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; ++j)
            scanf("%d",&cost[i][j]);
    }
    printf("Enter the source vertex : ");
    scanf("%d",&v);
    v--;
    int *dist = (int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        dist[i] = cost[v][i];
    }
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

// 0 1 2 999 999 999 3 
// 999 0 999 4 999 999 999
// 999 999 0 999 3 1 999
// 999 999 999 0 999 1 999
// 999 999 999 999 0 2 999
// 999 999 999 999 999 0 999
// 999 999 999 999 999 8 0

// 0 999 999 999 999 999 999 999 
// 3 0 999 999 999 999 999 999
// 10 8 0 999 999 999 999 999
// 999 999 12 0 999 999 999 999
// 999 999 999 15 0 2 999 999
// 999 999 999 10 999 0 9 14
// 999 999 999 999 999 999 0 10
// 17 999 999 999 999 999 999 0