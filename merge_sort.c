

#include <stdio.h>

void merge(int a[],int l,int m,int h)
{
    /**
     * merging into one single new array by traversing two arrays(a[l:m] and a[m+1:h]) or lists at a time.
     * based on that resultant array doing updations in original array i.e., in a(a[l:h]). 
    */
    int i = l,j = m+1,k = 0;
    int b[h-l];
    while(i <= m && j<=h)
    {
        if(a[i] >= a[j])
        {
            b[k] = a[j];
            j++;
        }
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }
    while(i<=m)
    {
        b[k] = a[i];
        k++;i++;
    }
    while(j<=h)
    {
        b[k] = a[j];
        k++;j++;
    }
    for(int x = 0;x<k;x++)
    {
        a[x+l] = b[x];
    }
}

void mergeSort(int a[],int l,int h)
{
    /**
     * this function sorts the array by divide and conquer strategy.
     * starting with division of the array into two parts and those into two parts.....
     * division stops when lower and higher index are equal i.e., single element.
     * and that element is aldredy sorted and another reason is thta we can not divide any furthor
     * (every time average(l,h) value is same) -> which leads to infinite loop.
    */
    if(l < h)
    {
        int mid = (l+h)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,h);
        merge(a,l,mid,h);
    }
}

int main()
{
    int n,k;
    printf("Enter the size of array : ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the array elements : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,n-1);
    printf("sorted elements are : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}