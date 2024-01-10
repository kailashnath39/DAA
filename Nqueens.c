// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int n,count = 0;
int *x;

int Place(int k, int i)
{
    for(int j=0;j<k;j++)
    {
        if(x[j] == i || abs(k-j) == abs(i-x[j]))
            return 0;
    }
    return 1;
}

void Nqueens(int k)
{
    for(int i=0;i<n;i++)
    {
        if(Place(k,i))
        {
            x[k] = i;
            if(k == n-1)
            {
                count++;
                for(int j=0;j<n;j++)
                    printf("%d  ",x[j]+1);
                printf("\n");
            }
            else
                Nqueens(k+1);
        }
    }
}

int main()
{
    printf("Enter the number of queens : ");
    scanf("%d",&n);
    x = (int *)malloc(n*sizeof(int));
    printf("The solution sets(non attacking positions of Queens) are : \n");
    for(int i=1;i<=n;i++)
        printf("q%d ",i);
    printf("\n");
    Nqueens(0);
    printf("The no. of solution sets are : %d\n",count);
}