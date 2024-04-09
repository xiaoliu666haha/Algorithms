#include <stdio.h>
#include <stdlib.h>

int **squareMatrixMultiply(int **A, int **B, int nrow)
{
    int **C = (int **)malloc(nrow * sizeof(int *));

    for (int i = 0; i < nrow; i++)
    {
        C[i] = (int *)malloc(nrow * sizeof(int));
    }
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < nrow; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < nrow; k++)
            {
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int main()
{
    int nrow = 5;

    int **A = (int **)malloc(nrow * sizeof(int *));
    for (int i = 0; i < nrow; i++)
    {
        A[i] = (int *)malloc(nrow * sizeof(int));
    }

    int **B = (int **)malloc(nrow * sizeof(int *));
    for (int i = 0; i < nrow; i++)
    {
        B[i] = (int *)malloc(nrow * sizeof(int));
    }

    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < nrow; j++)
        {
            int val = 1;
            A[i][j] = val;
            B[i][j] = val;
        }
    }

    int **C = squareMatrixMultiply((int **)A, (int **)B, nrow);
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < nrow; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < nrow; i++)
    {
        free(C[i]);
    }
    free(C);

    return 0;
}
