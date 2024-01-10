#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int minCoins(int coins[],int m,int reAmt,int noOfCoins[])
{
    if(reAmt == 0)
        return 0;
    else if(noOfCoins[reAmt] != -1)
        return noOfCoins[reAmt];
    else
    {
        int res = INT_MAX;
        for(int i=0;i<m;i++)
        {
            if(coins[i] <= reAmt)
            {
                int sub_res = minCoins(coins,m,reAmt-coins[i],noOfCoins);
                if(sub_res != INT_MAX && sub_res+1 <= res)
                    res = sub_res + 1;
            }
        }
        noOfCoins[reAmt] = res;
        return res;
    }
}

int main()
{
  int m;
  printf("Enter the no. of kinds of coins:");
  scanf("%d",&m);
  int coins[m];
  printf("\nEnter the values of coins (in non-increasing  order):");
  for(int i=0;i<m;i++){
    scanf("%d",&coins[i]);
  }
  
    //int m = sizeof(coins) / sizeof(coins[0]);
    int V;
    printf("\nEnter the Amount:");
    scanf("%d",&V);
    int noOfCoins[V+1];
    for(int i=1;i<=V;i++)
        noOfCoins[i] = -1;
    int res = minCoins(coins,m,V,noOfCoins);
    if (res == INT_MAX)
        res = -1;
    
    printf("Minimum coins required is %d", res);
    return 0;
}
