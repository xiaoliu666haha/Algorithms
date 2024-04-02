#include<stdio.h>
void merge(int * A,int p,int q,int r)
{
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1+1];
    int R[n2+1];
    for(int i = 0;i<n1;i++){
        L[i] = A[p+i];
    }
    for (int i = 0;i<n2;i++){
        R[i] = A[q+1+i];
    }
    L[n1] = 10000;
    R[n2] = 10000;
    int i = 1;
    int j = 1;
    for(int k = p;k<=r;k++)
    {
        if (L[i]<=R[j])
        {
            A[k]=L[i];
            i++;
        }
        else 
        {
            A[k] = R[j];
            j++;
        }
    }
}