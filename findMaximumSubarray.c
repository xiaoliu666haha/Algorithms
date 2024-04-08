#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct
{
    int max_left;
    int max_right;
    int sum;
} result;

result findMaxCrossingSubarray(int *A, int low, int mid, int high)
{
    int left_sum = -100000;
    int sum = 0;
    int max_left;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    int right_sum = -100000;
    sum = 0;
    int max_right;
    for (int j = mid + 1; j <= high; j++)
    {
        sum = sum + A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    result res;
    res.max_left = max_left;
    res.max_right = max_right;
    res.sum = left_sum + right_sum;
    return res;
}
result findMaximumSubarray(int *A, int low, int high)
{
    result res;
    if (high == low)
    {
        res.max_left = low;
        res.max_right = high;
        res.sum = A[low];
        return res;
    }
    else
    {
        int mid = floor((low + high) / 2);
        res = findMaximumSubarray(A, low, mid);
        int left_low = res.max_left;
        int left_high = res.max_right;
        int left_sum = res.sum;
        res = findMaximumSubarray(A, mid + 1, high);
        int right_low = res.max_left;
        int right_high = res.max_right;
        int right_sum = res.sum;
        res = findMaxCrossingSubarray(A, low, mid, high);
        int cross_low = res.max_left;
        int cross_high = res.max_right;
        int cross_sum = res.sum;
        if (left_sum >= right_sum && left_sum >= cross_sum)
        {
            result answer;
            answer.max_left = left_low;
            answer.max_right = left_high;
            answer.sum = left_sum;
            return answer;
        }
        else if (right_sum >= left_sum && right_sum >= cross_sum)
        {
            result answer;
            answer.max_left = right_low;
            answer.max_right = right_high;
            answer.sum = right_sum;
            return answer;
        }
        else
        {
            result answer;
            answer.max_left = cross_low;
            answer.max_right = cross_high;
            answer.sum = cross_sum;
            return answer;
        }
    }
}
int main()
{
    printf("Please input the length of the array:\n");
    int len;
    scanf("%d", &len);
    int *A = malloc(len * sizeof(int));
    printf("Please input the array:\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &A[i]);
    }
    result res;
    res = findMaximumSubarray(A, 0, len - 1);
    printf("low :%d\n", res.max_left);
    printf("high:%d\n", res.max_right);
    printf("maxSum:%d\n", res.sum);
    return 0;
}