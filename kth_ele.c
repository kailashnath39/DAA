// Online C compiler to run C program online
#include <stdio.h>

int partision(int a[],int l,int h)
{
    int pivot = a[l],i = l-1,j = h+1,temp;
    do
    {
        do
        {
            i++;
        }while(a[i] <= pivot && i<=j);
        do
        {
            j--;
        }while(a[j] > pivot);
        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        
    }while(i < j);
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return(j);
}

int quickSearch(int a[],int l,int h,int k)
{
    while(l <= h)
    {
        int j = partision(a,l,h);
        // like binary search
        if(k == j)
        {
            return(a[k]);
        }
        else if(k < j)
            h = j-1;
        else 
            l = j+1;
    }
    return -1;
}

int main()
{
    system("cls");
    int n,k;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter which smallest element you want : ");
    scanf("%d",&k);
    printf("the %dth smallest element is %d\n",k,quickSearch(a,0,n-1,k-1));
    return 0;
}