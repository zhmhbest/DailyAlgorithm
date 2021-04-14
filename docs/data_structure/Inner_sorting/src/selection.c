#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

/**
 * 简单选择排序
 */
void selectSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = minKey(arr, len, i);
        if (i != j)
            swapValue(arr, i, j);
    }
}

int main()
{
    int arr[] = {2, 4, 5, 1, 8};
    const int len = 5;
    printArray(arr, len);
    selectSort(arr, len);
    printArray(arr, len);
    return 0;
}
