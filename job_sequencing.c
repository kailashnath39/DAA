#include <stdio.h>
void readArray(int arr[],int n)
{
    printf("Enter the elements : ");
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
void printArray(int arr[],int n)
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int arr[],int i,int j)
{
        int minIndex = arr[i];
        arr[i] = arr[j];
        arr[j] = minIndex;
}
void Sort(int a[],int p[],int n)
{
    int minIndex;
    for(int i=1;i<n;i++)
    {
        minIndex = i;
        for(int j=i;j<=n;j++)
        {
            if(a[j] > a[minIndex])
            {
                minIndex = j;
            }
        }
        swap(a,i,minIndex);
        swap(p,i,minIndex);
    }
}
int maxProfit(int p[],int d[],int n)
{
    Sort(p,d,n);
    int j[n+1],k=1,r;
    j[0] = 0;
    j[1] = 1;
    for(int i=2;i<=n;i++)
    {
        r = k;
        while(d[i]<d[j[r]] && d[j[r]]!=r) 
        // ensures correct sequence and no scheduling of jobs
        // and finding the crt position
            r = r-1;
        if(d[i] >= d[j[r]] && d[i]>r) 
        // ensures that putting one satisfies the dependencies
        // validating the place 
        {
            for(int q=k;q>=r+1;q--)
                j[q+1] = j[q];
            k+=1;
            j[r+1] = i;
        }
    }
    int totProfit=0;
    for(int i=1;i<=k;i++)
    {
        totProfit+=p[j[i]];
    }
    return totProfit;
}

int main()
{
    int p[] = {0,3,5,20,18,1,6,30},d[] = {0,1,3,4,3,2,1,2};
    // int p[] = {0,100,19,38,27,52},d[] = {0,2,1,2,1,3};
    int n = 7;
    int profit = maxProfit(p,d,n);
    printf("maximum profit : %d\n",profit);
    return 0;
}