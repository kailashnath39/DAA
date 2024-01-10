// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
int partision(int a[],int l,int h)
{
    int pivot = a[l],i = l-1,j = h+1,temp;
    printf("%d\n",pivot);
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

void quickSort(int a[],int l,int h)
{
    if(l < h)
    {
        int j = partision(a,l,h);
        quickSort(a,l,j-1);
        quickSort(a,j+1,h);
    }
}

int main()
{
    system("cls");
    int a[] = {10,6,7,5,8,9,4,3,2,1},n = 9;
    quickSort(a,0,9);
    for(int i=0;i<=9;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}