// 栈在括号匹配中的应用
#include <stdio.h>
#include <malloc.h>

#define MaxSize 10

typedef struct
{
    char data[MaxSize];
    int top;
} SqStack;

// 初始化
void InitStack(SqStack &S)
{
    S.top = -1;
}

// 判断空
bool Empty(SqStack S)
{
    if (S.top == -1)
        return true;
    else
        return false;
}

// 进栈
bool Push(SqStack &S, char s)
{
    if (S.top == MaxSize - 1)
    {
        printf("栈已满。\n");
        return false;
    }
    S.data[++S.top] = s;
    return true;
}

bool Pop(SqStack &S, char &s)
{
    if (Empty(S))
    {
        printf("栈为空。\n");
        return false;
    }
    s = S.data[S.top--];
    return true;
}

bool bracketCheck(char s[], int length)
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < length; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            Push(S, s[i]);
            /* code */
        }
        else
        {
            if (Empty(S))
            {
                printf("%c匹配失败。\n", s[i]);
                return false;
                /* code */
            }
            else
            {
                char topElem;
                Pop(S, topElem);
                if (s[i] == ')' && topElem != '(')
                {
                    printf("%c匹配失败。\n", s[i]);
                    return false;
                }
                if (s[i] == '}' && topElem != '{')
                {
                    printf("%c匹配失败。\n", s[i]);
                    return false;
                }
                if (s[i] == ']' && topElem != '[')
                {
                    printf("%c匹配失败。\n", s[i]);
                    return false;
                }
            }
        }

        /* code */
    }
    return Empty(S);
}

void scanfChar(char str[], int length)
{
    int i = 0;
    printf("输入括号：");
    while (scanf("%s", &str[i]) != EOF)
    {
        i++;
        printf("输入括号：");
    }
    length = i;
}

void show(char s[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("data[%d]=%c\n", i, s[i]);
    }
}

int main()
{

    int length = 6;
    char s[length];
    scanfChar(&s[0], length);
    printf("%d", length);
    show(s, length);
    if (bracketCheck(s, length))
        printf("匹配成功。\n");
    else
        printf("匹配失败。\n");

    return 0;
}
