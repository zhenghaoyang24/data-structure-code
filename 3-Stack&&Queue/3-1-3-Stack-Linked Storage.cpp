// 栈的链式存储-不带头结点（实则为规定只能头部增删的单链表）
#include <malloc.h>
#include <stdio.h>

typedef struct LinkNode
{
    int data;
    struct LinkNode *next;
    /* data */
} *LiStack, LinkNode;

bool InitStack(LiStack &S)
{
    S = NULL;
    return true;
}

// 进栈
bool Push(LiStack &S, int elem)
{
    LinkNode *s;
    s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = elem;
    s->next = S;
    S = s;
    return true;
}

// 出栈
bool Pop(LiStack &S)
{

    LinkNode *p, *q;
    q = S; // q指向栈顶元素
    if (q == NULL)
    {
        printf("栈为空，无需出栈。\n");
        return false;
        /* code */
    }

    p = S->next; // p指向q的后一个元素
    S = p;
    free(q); // 销毁栈顶
    return true;
}

// 栈长度
int LengthStack(LiStack S)
{
    LinkNode *p = S;
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

// 所有栈元素，从栈顶开始
void ShowStack(LiStack S)
{
    LinkNode *p;
    p = S;
    for (int i = LengthStack(S) - 1; p != NULL; i--)
    {
        printf("stack.data[%d]=%d\n", i, p->data);
        p = p->next;
        /* code */
    }
}

// 获取栈顶元素
int GetElem(LiStack S)
{
    if (S == NULL)
    {
        printf("栈为空，栈顶获取失败。\n");
        return NULL;
        /* code */
    }
    else
    {
        return S->data;
    }
}

int main()
{
    LiStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    Push(S, 5);
    printf("栈长度为：%d\n", LengthStack(S));
    ShowStack(S);

    Pop(S);
    printf("栈长度为：%d\n", LengthStack(S));
    ShowStack(S);

    Pop(S);
    printf("栈长度为：%d\n", LengthStack(S));
    ShowStack(S);
    printf("栈顶元素为：%d\n", GetElem(S));

    return 0;
}
