#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct ratioProfitWeight
{
    float pwr;
    float p;
    float w;
} item;
item *rpw;
float bagWt;


void sort()
{
    /**
     * sorting based on profit/weight ratio reason is given in 
     * below function's documentation.
    */
    int i,j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (rpw[j].pwr < rpw[j + 1].pwr)
            {
                item temp = rpw[j];
                rpw[j] = rpw[j + 1];
                rpw[j + 1] = temp;
            }
}

// int compareItems(const void *a, const void *b) {
//     // return ((const item *)a)->pwr > ((const item *)b)->pwr ? 1 : (((const item *)a)->pwr < ((const item *)b)->pwr ? -1 : 0);
//     return -((const item *)a)->pwr + ((const item *)b)->pwr;
// }


float fracKnapSack()
{
    /**
     * this function's approach is profits and weights
     * are arranged in non-increasing order of profit/weight(p/w) ratio
     * beacause (p/w) ratio gives profit per each unit of item in the items(optimal
     * solution(maximization of total profit) for the problem).
     * For each item it takes <= given weight for that item.  
    */
    sort();
    // qsort(rpw,n,sizeof(item),compareItems);
    int i;
    float *x = (float *)calloc(n,sizeof(float));
    for(i=0;i<n;i++)
    {
        if(rpw[i].w > bagWt)
            break;
        x[i] = 1;
        bagWt = bagWt-rpw[i].w;
    }
    if(i<n)
        x[i] = bagWt/rpw[i].w;
    float maxP = 0.0;
    for(i=0;i<n;i++)
    {
        maxP += rpw[i].p * x[i];
    }
    free(x);
    return maxP;
}


int main()
{
    int i,j;
    printf("Enter the size : ");
    scanf("%d",&n);
    rpw = (item *)malloc(n * sizeof(item));
    printf("Enter the profits and weights : \n");
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&rpw[i].p,&rpw[i].w);
        rpw[i].pwr = rpw[i].p/rpw[i].w;
    }
    printf("Enter the bag weight : ");
    scanf("%f",&bagWt);
    printf("max profit : %f\n",fracKnapSack());
    free(rpw);
}

