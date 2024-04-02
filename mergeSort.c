#include<stdio.h>
#include<math.h>
void merge(int *,int ,int, int);
void mergeSort(int * A,int p,int r)
{
    if(p<r)
    {
        int q = floor((p+r)/2);
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}
int main()
{
    int A[] = {2,1,6,4,5,9,7,8};
    mergeSort(A,0,7);
    for(int i = 0;i<8;i++)
    {
        printf("%d ",A[i]);
    }
    return 0;
}