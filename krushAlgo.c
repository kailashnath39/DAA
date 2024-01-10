#include <stdio.h>
#include <stdlib.h>

#define INF 999
int n = 0;

int find(int parent[], int i) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}

void Union(int parent[], int x, int y) {
    parent[y] = x;
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int cost[n][n];
    int parent[n];

    int mincost = 0;

    printf("Enter the costs:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", & cost[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", cost[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int min = INF,v1,v2;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(find(parent,j) != find(parent,k) && cost[j][k] != 0 && min > cost[j][k])
                {
                    min = cost[j][k];
                    v1 = j;v2 = k;
                }
            }
        }
        printf("%d %d\n",v1,v2);
        int x = find(parent, v1);
        int y = find(parent, v2);

        if (x != y) {
            mincost += cost[v1][v2];
            Union(parent, x, y);
        }
    }

    printf("Minimal Cost: %d\n", mincost);
    return 0;
}


// 0 5 999 4 999 999 999 999 
// 5 0 999 999 1 999 999 999
// 999 999 0 1 3 1 999 999
// 4 999 1 0 999 999 999 2
// 999 1 3 999 0 999 6 999
// 999 999 1 999 999 0 4 10
// 999 999 999 999 6 4 0 2 
// 999 999 999 2 999 10 2 0