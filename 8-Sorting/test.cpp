#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main()
{

    int arr[10] = {2, 6, 9, 1, 0, 8, 3, 5, 4, 7};
    printf("\n");

    // 排序
    insertSort(arr, 10);

    show_array(arr, 10);

    return 0;
}
