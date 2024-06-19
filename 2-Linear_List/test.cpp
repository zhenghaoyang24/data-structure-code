#include <stdio.h>
#include <malloc.h>

typedef int ElemType;

// 定义一个单链表节点类型；
typedef struct LNode
{
	ElemType data;			// 节点数据元素
	struct LNode *next; 	// 指针域
} LNode, *LinkList;

bool ListInit(LinkList &L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false;
        /* code */
    }
    L->next = NULL;
    return true;
}

// 头插法
LinkList List_InsertHead(LinkList &L)
{
    ElemType e;
    LNode *s;
	L = (LNode*)malloc(sizeof(LNode)); // 初始化单链表
	L->next = NULL;						 // 使单链表尾部始终为NULL;(消除脏数据);

    printf("输入元素:");
    while (scanf("%d", &e) != EOF)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data=e;
        s->next=L->next;
        L->next=s;
        /* code */
        printf("输入元素：");
    }
    return L;
}

int main()
{
    LinkList L;
    List_InsertHead(L);

    return 0;
}
