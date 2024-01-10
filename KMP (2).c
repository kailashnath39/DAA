#include<stdio.h>
#include<stdlib.h>

int *computeLPS(char *p,int m)
{
    int *LPS = (int *)malloc(sizeof(int)*(m));
    int k = 0;
    LPS[1] = 0;
    for(int q=2;q<m;q++)
    {
        while(k>0 && p[k+1] != p[q])
            k = LPS[k];
        if(p[k+1] == p[q])
            k++;
        LPS[q] = k;
    }
    return LPS;
}

void kmpMatcher(char *t,char *p,int n,int m)
{
    /**
     * the main core part of this algorithm is when mismatch occurs,
     * we will place the pattern in the position in which no. of comparisions
     * it won't make redundant comparisions.
     * One point is that this algorithm and there is another algorithm
     * which is similar to this one it uses T[LPS[j-1]] - index starts from 0
     * this algorithm uses T[LPS[q]+1] - index starts from 1.
    */
    int q = 0; // iterator for pattren
    int *LPS = computeLPS(p,m);
    for(int i=1;i<n;i++)
    {
        while(q>0 && p[q+1] != t[i])
            q = LPS[q];
        if(p[q+1] == t[i])
            q++;
        if(q == m-1)
        {
            printf("Pattren occurs with shift : %d\n",i-m+1);
            q = LPS[q];
        }
    }
}

int main() {
    int n, m;
    printf("Enter the length of the Text: ");
    scanf("%d", &n);
    char *t = (char *)malloc(sizeof(char)*(n+1));
    printf("Enter the Text: ");
    scanf("%s", t+1);
    printf("Enter the length of the Pattern: ");
    scanf("%d", &m);
    char *p = (char *)malloc(sizeof(char)*(m+1));
    printf("Enter the Pattern: ");
    scanf("%s", p+1);
//   char t[] = "0ABABDABACDABABCABAB";
//   char p[] = "0ABAB";
   kmpMatcher(t,p,n+1,m+1);
    return 0;
}