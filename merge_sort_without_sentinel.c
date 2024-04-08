#include <stdio.h>
#include <stdlib.h>
void merge(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + 1 + j];
    }

    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k++] = L[i++];
        }
        else
        {
            A[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        A[k++] = L[i++];
    }
    while (j < n2)
    {
        A[k++] = R[j++];
    }

    free(L);
    free(R);
}