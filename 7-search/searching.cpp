#include <stdio.h>
#define MaxSize 100

typedef int ElementType;
typedef struct
{
    ElementType data[MaxSize];
    int lengh;
} SqList;

void initList(SqList &L)
{
    L.lengh = 0;
}

int searchSql(SqList L, int key)
{
    int i;
    for (i = 0; i < L.lengh && L.data[i] != key; ++i);
    return i == L.lengh ? -1 : i;
}

int searchSql2(SqList L, int key)
{
    L.data[0] = key;
    int i;
    for (i = L.lengh - 1; L.data[i] != key; --i);
    return i;
}
void inputElem(SqList &L)
{
    int key;
    int i = 0;
    printf("输入元素：");
    while (scanf("%d", &key) != EOF)
    {
        L.data[i++] = key;
        L.lengh++;
        printf("输入元素：");
    }
}

void showSql(SqList L)
{
    for (int i = 0; i < L.lengh; i++)
    {
        printf("L.data[%d]=%d ", i, L.data[i]);
    }
}

int main()
{
    SqList L;
    initList(L);
    inputElem(L);
    showSql(L);
    printf("查找结果：%d",searchSql(L,6));


    return 0;
}
