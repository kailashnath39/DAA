#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
}

int min(int a,int b)
{
    return a<b?a:b;
}

int minCoinChange(int amt,int *dnom,int n)
{
    int *arr = (int *)malloc(sizeof(int)*(amt+1));
    int *selectionCoin = (int *)malloc(sizeof(int)*(amt+1));
    memset(arr,-1,sizeof(int)*(amt+1));
    arr[0] = 0;
    int resAmt;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<(amt+1);j++)
        {
            if(dnom[i] <= j)
            {
                if(arr[j] == -1)
                {
                    if(arr[j-dnom[i]] != -1)
                    {
                        arr[j] = 1 + arr[j-dnom[i]];
                        selectionCoin[j] = i;}
                }
                else
                {
                    if(arr[j-dnom[i]] != -1)
                        {arr[j] = min(arr[j],1 + arr[j-dnom[i]]);
                        selectionCoin[j] = i;}
                }
            }
        }
        // printArray(arr,amt+1);
    }
    int temp = amt;
    while(temp>0)
    {
        printf("%d\n",dnom[selectionCoin[temp]]);
        temp -= dnom[selectionCoin[temp]];
    }
    return arr[amt];
}


int main()
{
    int dnom[4] = {4,10,25},amt = 41;
    printf("minimum no. of coins : %d\n",minCoinChange(amt,dnom,3));
    
    return 0;
}