#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 交换元素
void swap(int *x, int *y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

// 1.插入排序
// 1-1.直接插入排序
void InsertSort(int arr[], int len)
{
    int i, j, temp;
    for (i = 1; i < len; i++)
    {
        if (arr[i] < arr[i - 1]) // 后一个比前一个小
        {
            temp = arr[i];
            for (j = i - 1; j >= 0 && arr[j] > temp; j--) // 将大于temp的元素往后移
            {
                arr[j + 1] = arr[j];
            }
            arr[j + 1] = temp;
        }
    }
}

// 2.交换排序
// 2-1.冒泡排序
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 2-2.快速排序
// 划分数据为两个部分
int Partition(int arr[], int low, int high)   //high=len-1
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
    arr[low] = pivot;
    return low;
}
// 快速排序(递归)
void quick_sort_recursive(int arr[], int low, int high)   //high=len-1
{
    if (low < high)
    {
        int pivot = Partition(arr, low, high);
        quick_sort_recursive(arr, low, pivot - 1);
        quick_sort_recursive(arr, pivot + 1, high);
    }
}

// 3.选择排序
// 3-1.简单选择排序
void selectSort(int arr[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {

            if (arr[j] < arr[min])
                min = j;
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
// 3-2.堆排序
// 调整大根堆(对非叶结点)
void HeadAdjust(int arr[], int start, int end)
{
    int dad = start;
    int son = dad * 2 + 1; // son为dad的左孩子
    while (son <= end)
    {
        if (son + 1 <= end && arr[son + 1] > arr[son]) // 右孩子存在且右孩子大于左孩子
        {
            son++;
        }
        if (arr[dad] > arr[son]) // 若父结点本就最大直接跳出循环
        {
            return;
        }
        else
        { // 否则交换父节点与最大孩子的位置
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
// 堆排序
void HeapSort(int arr[], int len)
{
    int i;
    // 对非叶结点进行堆处理
    for (i = len / 2 - 1; i >= 0; i--)
    {
        HeadAdjust(arr, i, len - 1); // 对非叶结点进行堆处理
    }
    for (i = len - 1; i > 0; i--) // 对所有元素进行排序
    {
        swap(&arr[0], &arr[i]);
        HeadAdjust(arr, 0, i - 1); // 因为此时arr[i]元素已经最大，无需参加堆处理
    }
}

// 4.归并排序
int *B = (int *)malloc(30 * sizeof(int));  //记得free
// 分隔序列
void Merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    for (k = low; k <= high; k++)
    {
        B[k] = arr[k];   //现将待排序序列复制给B
    }
    for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++)
    {
        if (B[i] <= B[j])   //比较两部分大小（<=为了保证稳定性）
            arr[k] = B[i++];   //将小的复制给arr
        else
            arr[k] = B[j++];
    }
    while (i <= mid)    //将剩余的元素直接复制给arr
        arr[k++] = B[i++];
    while (j <= high)
        arr[k++] = B[j++];
}
// 排序
void MergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);     //当只有一个元素时，low==mid，不能在分
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);   //merge最短会接受两个元素
    }
}

// 创建随机数组
void creat_random_array(int arr[], int n)
{

    int i;

    // 使用当前时间作为随机数种子，避免每次生成的随机数序列相同
    srand((unsigned)time(NULL));

    for (i = 0; i < 30; i++)
    {
        arr[i] = rand() % 30 + 1; // 生成1-30之间的随机整数
    }
    printf("随机生成的数组为：");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("\n");
}

// 打印数组
void show_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// 复制数组
void copyArray(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

int main()
{

    int arr[10]; // 数组长度为10，可以根据需要修改
    creat_random_array(arr, 10);
    int len = (int)sizeof(arr)/sizeof(*arr);

    // 直接插入排序
    int arr1[len];
    copyArray(arr, arr1, len);
    InsertSort(arr1, len);
    show_array(arr1, len);
    printf("(直接插入排序)\n");

    // 冒泡排序
    int arr2[30];
    copyArray(arr, arr2, len);
    bubble_sort(arr2, len);
    show_array(arr2, len);
    printf("(冒泡排序)\n");
    // 快速排序

    int arr3[30];
    copyArray(arr, arr3, len);
    quick_sort_recursive(arr3, 0, len-1);
    show_array(arr3, len);
    printf("(快速排序)\n");

    // 简单选择排序
    int arr4[30];
    copyArray(arr, arr4, len);
    selectSort(arr4, len);
    show_array(arr4, len);
    printf("(简单选择排序)\n");

    // 堆排序
    int arr5[30];
    copyArray(arr, arr5, len);
    HeapSort(arr5, len);
    show_array(arr5, len);
    printf("(堆排序后)\n");

    // 归并排序
    int arr6[30];
    copyArray(arr, arr6, len);
    MergeSort(arr6, 0, len-1);
    show_array(arr6, len);
    printf("(归并排序)");
}
