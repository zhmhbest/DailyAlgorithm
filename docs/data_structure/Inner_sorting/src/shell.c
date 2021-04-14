#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

void shellSortGroupTest(int arr[], int len)
{
    // 将每组分为2,4,8...个
    for (int step = len / 2; step > 0; step /= 2)
    {
        printf("step=%d\n", step);
        for (int i = step; i < len; i++)
        {
            int j = i,
                k = j - step;
            printf("group=(%d", arr[j]);
            while (k >= 0)
            {
                j = k;
                k = j - step;
                printf(", %d", arr[j]);
            }
            printf(")\n");
        }
    }
}

/**
 * 希尔排序
 */
void shellSort(int arr[], int len)
{
    for (int step = len / 2; step > 0; step /= 2)
    {
        for (int i = step; i < len; i++)
        {
            int j = i,
                k = j - step,
                dump = arr[j];
            // 插入排序
            while (k >= 0 && arr[k] > dump)
            {
                arr[j] = arr[k];
                j = k;
                k = j - step;
            }
            arr[j] = dump;
        }
    }
}

int main()
{
    int arr[] = {2, 5, 1, 8, 23, 546, 76, 34, 82, 3, 6, 4};
    const int len = 12;
    printArray(arr, len);
    shellSortGroupTest(arr, len);
    shellSort(arr, len);
    printArray(arr, len);
    return 0;
}
