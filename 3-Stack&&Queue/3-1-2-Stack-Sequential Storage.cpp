// 栈的顺序存储结构

#include <malloc.h>
#include <stdio.h>

// 共享栈(两个指针分别在栈空间顶与栈空间底，实则为两个栈公用一个栈空间，提高空间利用率)
// #define MaxSize 10
// typedef struct
// {
//     int data[MaxSize];
//     int top0; // 0号栈顶指针
//     int top1; // 0号栈顶指针
// } ShStack;
 
// 顺序栈的定义
#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int top;    // 栈顶指针
} SqStack;

// 初始化栈
void InitStack(SqStack &S)
{
    S.top = -1; // 也可将top初始化为0，代表top指向的为第几个栈元素；（进栈出栈操作也有一点变化）
}

// 判断是否为空栈
bool StackEmpty(SqStack S)
{
    if (S.top == -1)
        return true; // 栈为空
    else
        return false; // 栈非空
}

// 元素进栈
bool Push(SqStack &S, int elem)
{
    if (S.top == MaxSize - 1)
    {
        printf("栈已满，无法入栈。\n");
        return false;
        /* code */
    }
    S.data[++S.top] = elem;
    return true;
}

// 出栈
bool Pop(SqStack &S, int &x)
{
    if (S.top == -1)
    {
        printf("栈为空，不能出栈操作。\n");
        return false;
    }
    // x= S.data[S.top];
    // S.top--;
    x = S.data[S.top--];
    return true;
}

void ShowStack(SqStack S)
{
    if (S.top == -1)
    {
        printf("栈为空。\n");
        /* code" */
    }
    else
    {
        int i = S.top;
        int j = S.top;
        int x = i - j; // 当前输出的下标
        while (x < i + 1)
        {
            printf("stack.data[%d]=%d\n", x, S.data[x]);
            j--;
            x = i - j;
            /* code */
        }
    }
}

// 获取栈顶元素
int GetTop(SqStack S)
{
    if (S.top == -1)
    {
        printf("栈为空。\n");
        /* code" */
        return NULL;
    }
    else
    {
        return S.data[S.top];
    }
}

int main()
{
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    Push(S, 4);
    ShowStack(S);
    printf("%d", GetTop(S));

    return 0;
}
