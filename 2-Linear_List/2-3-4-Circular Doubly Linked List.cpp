// 循环双链表

#include <stdio.h>
#include <malloc.h>

// 定义双链表
typedef struct DNode
{
    int data;
    DNode *prior, *next;
} DNode, *DLinkList;

// 初始循环化链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = L;
    L->next = L;
    return true;
}

// 创建链表数据
DLinkList CreateList(DLinkList &L)
{
    DNode *s, *p;
    p = L;
    int value;
    printf("输入int型整数：");
    while (scanf("%d", &value) != EOF)
    {
        s = (DNode *)malloc(sizeof(DNode));
        s->data = value;
        s->prior = p;
        p->next = s;
        s->next = L;    //表头表尾连接
        L->prior = s;
        p = s;
        printf("输入int型整数：");
    }
    return L;
}

// 打印循环双链表数据
void ShowDList(DLinkList L)
{
    DNode *p = L->next;
    int i = 1;
    while (p != L)
    {
        printf("data[%d]=%d\n", i, p->data);
        p = p->next;
        i++;
        /* code */
    }
}

// 循环双链表长度
int LengthDLinkList(DLinkList L)
{
    DNode *p = L->next;
    int x = 0;
    while (p != L)
    {
        x++;
        p = p->next;
        /* code */
    }
    return x;
}

// 按位删除节点
bool DeleteDNode(DLinkList &L, int i, int &e)
{
    int length = LengthDLinkList(L);
    DNode *p = L, *q;
    int j = 0;
    if (i < 0 || i > length)
    {
        printf("删除节点位置不合法。\n");
        return false;
    }
    while (p->next != L && j < i - 1)
    {
        p = p->next;
        j++;
        /* code */
    }
    q = p->next; // 取出被删除节点的元素数据
    e = q->data;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}



int main()
{
    DLinkList L;
    InitDLinkList(L);
    CreateList(L);
    printf("双链表长度：%d\n", LengthDLinkList(L));
    ShowDList(L);

    int e = -1;
    DeleteDNode(L, 1, e);
    printf("被删除元素为：%d\n", e);

    printf("双链表长度：%d\n", LengthDLinkList(L));
    ShowDList(L);

    return 0;
}
