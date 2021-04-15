#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

void quickSwapPartitionRecursive(int arr[], const int boundL, const int boundR)
{
    if (boundL >= boundR)
        return;

    // 每轮确定一个中间数arr[p]的位置
    int p = boundR;
    int i = boundL;
    int j = boundR - 1;

    // printf("bound=%d,%d,p=%d\n", boundL, boundR, p);

    for (;;)
    {
        // 期望左侧数据小于arr[p]
        while (arr[i] < arr[p] && i < j)
            i++;

        // 期望右侧数据大于arr[p]
        while (arr[j] >= arr[p] && i < j)
            j--;

        // 此时i == j即为arr[p]的位置
        if (i == j)
            break;

        // 不满足期望的地方交换两侧数据
        // printf("swap1 %d,%d\n", i, j);
        swapValue(arr, i, j);
    }

    // 定位切割数
    if (arr[i] >= arr[p])
    {
        // printf("swap2 %d,%d\n", i, p);
        swapValue(arr, i, p);
    }
    else
    {
        i++;
    }
    // printArray(arr, 6);

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
    int arr[] = {5, 8, 4, 2, 9, 7};
    const int len = 6;
    printArray(arr, len);
    quickSwapSortByRecursive(arr, len);
    printArray(arr, len);
    return 0;
}
