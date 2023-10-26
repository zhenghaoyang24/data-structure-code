#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// 打印数组
void show_array(int arr[], int n)
{
    printf("排序后为：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertSort(int arr[], int len)
{
    int temp,i,j;
    for( i = 1; i < len; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }

    }
}


// 1-2希尔排序
void shellSort(int arr[], int len)
{
    int gap, i, j, temp;
    for (gap = len / 2; gap >= 1; gap = gap / 2)
    {
        for (i = gap; i < len; i++)
        {
            if (arr[i] < arr[i - gap])
            {
                temp = arr[i];
                for (j = i - gap; j >= 0 && arr[j] > temp; j = j - gap)
                {
                    arr[j + gap] = arr[j];
                }
                arr[j + gap] = temp;
            }
        }
    }
}

// 2-2.快速排序
// 划分数据为两个部分
int Partition(int arr[], int low, int high) // high=len-1
{
    int pivot = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= pivot)
            high--;
        arr[low] = arr[high];
        while (low < high && arr[low] <= pivot)
            low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot; // 结束后，基准元素则固定了
    return low;
}
// 快速排序(递归)
void quick_sort_recursive(int arr[], int low, int high) // high=len-1
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);
        printf("第一趟完:\n");
        show_array(arr,8);
        printf("\n");
        quick_sort_recursive(arr, low, pivot - 1);
        quick_sort_recursive(arr, pivot + 1, high);
    }
}




int main()
{

    int arr[10] = {32,5,2,28,16,12,72,60};
    printf("\n");

    // 排序
    // insertSort(arr, 10);
    // shellSort(arr,8);
    quick_sort_recursive(arr,0,7);

    show_array(arr, 8);

    return 0;
}
