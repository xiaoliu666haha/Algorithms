#include <stdio.h>
#include <stdlib.h>

typedef struct subarray
{
    int low;
    int high;
    int sum;
} Subarray;
Subarray linerFindMaximumSubarray(int *A, int low, int high)
{
    Subarray s = {-1, -1, INT_MIN};
    int sum = 0;
    int slow = -1;
    for (int i = 0; i <= high; i++)
    {
        if (sum > 0)
        {
            sum += A[i];
        }
        else
        {
            sum = A[i];
            slow = i;
        }
        if (sum > s.sum)
        {
            s.sum = sum;
            s.low = slow;
            s.high = i;
        }
    }
    return s;
}
int main()
{
    printf("input the length of the array:");
    int len = 0;
    scanf("%d", &len);
    int *A = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &A[i]);
    }
    Subarray s = linerFindMaximumSubarray(A, 0, len - 1);
    printf("low: %d,high: %d,sum: %d", s.low, s.high, s.sum);
    return 0;
}