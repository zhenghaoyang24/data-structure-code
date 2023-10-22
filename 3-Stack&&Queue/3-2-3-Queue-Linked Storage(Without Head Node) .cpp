// 队列 链式存储结构 （不带头结点）
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
    // 初始时，都为NULL
    Q.front = NULL;
    Q.rear = NULL;
}

// 判断队列是否为空
bool EmptyQueue(LinkQueue Q)
{
    if (Q.front == NULL) // 也可以利用rear==NULL判断
        return true;     // 为空
    else
        return false; // 不为空
}

// 入队
void EnQueue(LinkQueue &Q, int x)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (Q.front == NULL) // 若不带头结点队列为空，需要对插入的第一个元素单独处理
    {
        Q.front = s; // 更改对头、队尾指针。指向第一个节点
        Q.rear = s;
    }
    else
    {
        Q.rear->next = s; // 连接新节点
        Q.rear = s;
    }
}

// 出队
bool DeQueue(LinkQueue &Q, int &x)
{
    if (Q.front == NULL)
    {
        printf("队列为空，出队失败。\n");
        return false;
    }
    LinkNode *p = Q.front;
    x = p->data;
    Q.front = p->next; // 头结点为p的下一个节点
    if (Q.rear == p)
    {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}

// 打印所有元素数据
void ShowQueue(LinkQueue Q)
{
    LinkNode *p = Q.front;
    if (p != NULL)
    {
        int i = 0;
        do
        {
            printf("data[%d]=%d\n", i, p->data);
            i++;
            p = p->next;
        } while (p != NULL);
        /* code */
    }
    else
    {
        printf("队列为空。\n");
    }
}

int main()
{
    int x = -1;
    LinkQueue Q;
    InitQueue(Q);
    // EnQueue(Q, 0);
    // EnQueue(Q, 1);
    // EnQueue(Q, 2);
    EnQueue(Q, 3);
    ShowQueue(Q);
    DeQueue(Q, x);

    ShowQueue(Q);
    if (EmptyQueue(Q))
    {
        printf("空\n");
        /* code */
    }
    else
    {
        printf("非空\n");
    }

    printf("%p\n", Q.front);
    printf("%p\n", Q.rear);

    return 0;
}
