#include<stdio.h>
#include<stdlib.h>
void merge(int *A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    // 分配动态内存
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 将数据复制到左右子数组中
    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[q + 1 + j];
    }

    // 不再使用哨兵，而是在循环中检查索引
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k++] = L[i++];
        } else {
            A[k++] = R[j++];
        }
    }

    // 处理剩余的元素
    while (i < n1) {
        A[k++] = L[i++];
    }
    while (j < n2) {
        A[k++] = R[j++];
    }

    // 释放动态分配的内存
    free(L);
    free(R);
}