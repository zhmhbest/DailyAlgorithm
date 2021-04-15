#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

void quickSwapPartitionRecursive(int arr[], const int boundL, const int boundR)
{
    if (boundL >= boundR)
        return;

    int partition = arr[boundR];
    int i = boundL;
    int j = boundR - 1;

    while (i < j)
    {
        // 期望左侧数据小于partition
        while (arr[i] < partition && i < j)
            i++;
        // 期望右侧数据大于partition
        while (arr[j] >= partition && i < j)
            j--;

        // 不满足期望的地方交换两侧数据
        swapValue(arr, i, j);
    }

    // 定位切割数
    if (arr[i] >= arr[boundR])
        swapValue(arr, i, boundR);
    else
        i++;

    if (i)
        quickSwapPartitionRecursive(arr, boundL, i - 1);
    quickSwapPartitionRecursive(arr, i + 1, boundR);
}

/**
 * 快速排序
 */
void quickSwapSortByRecursive(int arr[], int len)
{
    quickSwapPartitionRecursive(arr, 0, len - 1);
}

int main()
{
    // int arr[] = {2, 4, 5, 1, 8};
    int arr[] = {8, 5, 4, 2, 1};
    const int len = 5;
    printArray(arr, len);
    quickSwapSortByRecursive(arr, len);
    printArray(arr, len);
    return 0;
}
