#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

/**
 * 冒泡排序
 */
void bubbleSort(int arr[], int len)
{
    // [ →i→ ]
    for (int i = 0; i < len; i++)
    {
        // (i ←j← ]
        for (int j = len - 1; j > i; j--)
        {
            if (arr[j - 1] > arr[j])
            {
                swapValue(arr, j - 1, j);
            }
        }
    }
}

int main()
{
    // int arr[] = {2, 4, 5, 1, 8};
    int arr[] = {8, 5, 4, 2, 1};
    const int len = 5;
    printArray(arr, len);
    bubbleSort(arr, len);
    printArray(arr, len);
    return 0;
}
