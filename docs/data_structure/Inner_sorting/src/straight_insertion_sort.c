#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "array.inl"

/**
 * 直接插入排序
 */
void straightInsertSort(int arr[], int len)
{
    // 从第二位开始最后一位
    for (int i = 1; i < len; i++)
    {
        // “当前元素”左侧数据[0,i)已经有序

        // 1.“当前元素”不需要移动
        int j = i - 1;
        if (arr[i] >= arr[j])
            continue;

        // 2.将“当前元素”插入到左侧数据，使之依然有序
        int x = arr[i];
        for (; j >= 0 && x < arr[j]; j--)
            arr[j + 1] = arr[j]; // 当前记录j后移
        arr[j + 1] = x;

        // // 打印每次插入后结果
        // printf("batch%d = ", i);
        // printArray(arr, len);
    }
}

int main()
{
    int arr[] = {8, 5, 9, 4, 2, 1};
    const int len = 6;
    printArray(arr, len);
    straightInsertSort(arr, len);
    printArray(arr, len);
    return 0;
}
