#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

/**
 * 直接插入排序
 */
void insertSort(int arr[], int len)
{
    // 从第二位开始最后一位
    for (int i = 1; i < len; i++)
    {
        // “当前元素”左侧数据已经有序

        // 1.“当前元素”不需要移动
        int j = i - 1;
        if (arr[i] >= arr[j])
            continue;

        // 2.将“当前元素”插入到左侧数据，使之依然有序
        int x = arr[i];
        for (; j >= 0 && x < arr[j]; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = x;
    }
}

int main()
{
    int arr[] = {2, 4, 5, 1, 8};
    const int len = 5;
    printArray(arr, len);
    insertSort(arr, len);
    printArray(arr, len);
    return 0;
}
