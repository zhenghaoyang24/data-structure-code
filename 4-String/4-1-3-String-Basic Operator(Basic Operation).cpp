// 串的基本操作

#include <stdio.h>

#define MAXLEN 10

// 为保证位置与下标统一 ，ch[0]为废弃位置
typedef struct
{
    char ch[MAXLEN];
    int length;
} SString;

// 赋值
void StrAssign(SString &S, char chars[], int length)
{
    for (int i = 0; i < length; i++)
    {
        S.ch[i + 1] = chars[i];
    }
    S.length = length;
}

void ShowStr(SString S)
{
    for (int i = 1; i <= S.length; i++)
    {
        printf("%c", S.ch[i]);
    }
    printf("\n");
}

// 求子串  sub:返回的子串   S：主串 pos:开始位置    len:子串长度
bool SubString(SString &sub, SString S, int pos, int len)
{
    if (pos + len - 1 > S.length) // 子串结束位置不能超过主串的长度
    {
        printf("位置不合法。\n");
        return false;
    }
    for (int i = pos; i < pos + len; i++)
    {
        sub.ch[i - pos + 1] = S.ch[i];
    }
    sub.length = len; // 把长度给子串
    return true;
}

// 比较两个字符串的大小   S>T:返回值>0，S=T:返回值=0，S<T:返回值<0
int StrCompare(SString S, SString T)
{
    for (int i = 1; i <= S.length && i <= T.length; i++)
    {
        if (S.ch[i] != T.ch[i])
        {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

// 子串出现位置
int Index(SString S, SString T)
{
    int i = 1, S_length = S.length, T_length = T.length;
    SString sub;
    while (i <= S_length - T_length + 1)
    {
        SubString(sub, S, i, T_length); // 取出相应位置的子串
        if (StrCompare(sub, T) != 0)    // 判断子串与T是否相等
            i++;
        else
            return i;
    }
    return -1;
}

// 简单的模式匹配
int Index_1(SString S, SString T)
{
    int i = 1, j = 1;
    int S_length = S.length, T_length = T.length;
    while (i <= S_length && j <= T_length)
    {
        if (S.ch[i] == T.ch[j]) // 匹配成功
        {
            i++;
            j++;
        }
        else // 匹配失败
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T_length) // 返回子串位置
        return i - T_length;
    else
        return 0;
}

int main()
{
    SString S1;
    SString S2;
    SString S3;
    char chars1[5] = {'a', 'b', 'c', 'd', 'e'};
    char chars2[5] = {'b', 'c', 'd'};
    StrAssign(S1, chars1, 5);
    StrAssign(S2, chars2, 3);
    // ShowStr(S1);
    SubString(S3, S1, 2, 3);
    ShowStr(S3);
    printf("%d\n", StrCompare(S1, S2));
    printf("%d\n", StrCompare(S2, S3));
    printf("子串出现位置为%d\n", Index(S1, S2));

    return 0;
}
