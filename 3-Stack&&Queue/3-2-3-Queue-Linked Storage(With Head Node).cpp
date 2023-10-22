// 队列 链式存储结构 （带头结点）
#include <stdio.h>
#include <malloc.h>

// 定义队列节点
typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
} LinkNode;

// 定义链式队列
typedef struct
{
    LinkNode *front, *rear; // 队列的头指针与尾指针
    /* data */
} LinkQueue;

// 初始化队列
void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode)); // 建立头结点
    Q.front->next = NULL;                                    // 初始为空
}

// 判断队列是否为空
bool EmptyQueue(LinkQueue Q)
{
    if (Q.rear == Q.front)
        return true; // 为空
    else
        return false; // 不为空
}

// 入队
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    Q.rear->next = s; // 插入rear之后
    Q.rear = s;       // 尾指针指向s
}

// 出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (EmptyQueue(Q))
    {
        printf("队列为空，出队失败。\n");
        return false;
    }
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) // 判断被删除的节点是否为最后一个节点，如果是则要更改队尾指针
    {
        Q.rear = Q.front;
    }
    free(p);
    return true;
}

// 所有元素
void ShowQueue(LinkQueue Q)
{
    LinkNode *p = Q.front->next;
    if (EmptyQueue(Q))
    {
        printf("队列为空。\n");
    }
    else
    {
        int i = 0;
        do
        {
            printf("data[%d]=%d\n", i, p->data);
            i++;
            p = p->next;
        } while (p != NULL);
    }
}

int main()
{
    LinkQueue Q;
    InitQueue(Q);
    printf("%p\n", Q.front->next);
    printf("%p\n", Q.rear->next);

    EnQueue(Q, 1);
    printf("%p\n", Q.front->next);
    printf("%p\n", Q.rear->next);
    EnQueue(Q, 2);
    printf("%p\n", Q.front->next);
    printf("%p\n", Q.rear->next);
    ShowQueue(Q);
    int x = -1;
    printf("出队元素为：%d\n", DeQueue(Q, x));
    ShowQueue(Q);
    return 0;
}
