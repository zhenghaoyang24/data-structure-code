// 循环单链表

#include <stdio.h>
#include <malloc.h>

// 定义一个单链表节点类型
typedef struct LNode
{
    int data;           // 节点数据元素
    struct LNode *next; // 指针指向下一个节点
} LNode, *LinkList;

// 2-初始化一个单链表（带头结点，一般用带头结点）
bool InitList(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    // L = (LNode*)malloc(sizeof(LinkList));	//分配一个头结点
    if (L == NULL)
    {
        printf("初始化失败。");
        return false; // 内存不足，分配失败，又可能发生
    }
    L->next = L; // 头结点指针为空
    return true;
}

LinkList CreateList(LinkList &L)
{
    LNode *p = L;
    LNode *s;
    int e;
    printf("输入int型数据：");
    while (scanf("%d", &e) != EOF)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
        p = s;
        printf("输入int型数据：");
    }

    return L;
}

// 展示所有数据
void ShowList(LinkList L)
{
    LNode *p;
    p = L;
    int i = 1;
    while (p->next != L)
    {
        p = p->next;
        printf("data[%d]=%d\n", i, p->data);
        i++;
    }
}

// 长度
int LengthList(LinkList L)
{
    LNode *p;
    p = L;
    int i = 0;
    while (p->next != L)
    {
        i++;
        p = p->next;
        /* code */
    }
    return i;
}

// 删除i后的一个节点
bool DeleteLNode(LinkList &L, int i, int &e)
{
    LNode *p = L;
    LNode *q;
    int j = 0;
    int length = LengthList(L);
    if (i < 1 || i > length)
    {
        printf("位置不合法。\n");
        return false;
    }
    while (L->next != L && j < i - 1)
    {
        j++;
        p = p->next;
    }
    q = p->next;
    e = q->data;
    p->next = p->next->next;
    free(q);
    return true;
}

// 根据位置插入数据
bool InsertLNode(LinkList &L, int i, int e)
{
    LNode *p = L, *s;
    int length = LengthList(L);
    if (i < 1 || i > length)
    {
        printf("插入位置不合法。\n");
        return false;
    }
    int j = 0;
    while (p->next != L && j < i - 1)
    {
        p = p->next;
        j++;
    }
    s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int main()
{
    LinkList L;
    InitList(L);
    CreateList(L);
    printf("长度：%d\n", LengthList(L));
    int e = -1;
    DeleteLNode(L, 4, e);
    printf("被删除元素为:%d\n", e);
    printf("长度：%d\n", LengthList(L));
    ShowList(L);
    InsertLNode(L, 3, 33);
    printf("长度：%d\n", LengthList(L));
    ShowList(L);
    return 0;
}