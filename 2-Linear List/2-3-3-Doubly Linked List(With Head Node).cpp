// 双链表（带头结点）
#include <malloc.h>
#include <stdio.h>

// 定义双链表
typedef struct DNode
{
    int data;
    DNode *prior, *next;
} DNode, *DLinkList;

// 初始化链表
bool InitDLinkList(DLinkList &L)
{
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
    {
        return false;
    }
    L->prior = NULL;
    L->next = NULL;
    return true;
}

// 在p节点后插入s节点（后插）
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p == NULL || s == NULL)
    {
        return false;
    }
    s->next = p->next;
    if (p->next!= NULL) // 判断p是不是最后一个节点
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

// 删除节点p后的一个节点
bool DeleteNextDNode(DNode *p)
{
    if (p == NULL)
    {
        return false; // p为空
        /* code */
    }
    DNode *q = p->next;     //删除q后的一个结点（q）
    if (q == NULL)
        return false; // p已经是最后一个节点
    if (q->next != NULL) // 如果q不是最后一个结点
        q->next->prior = p;
    p->next = q->next;
    free(q);
    return true;
}

//释放链表所有节点
void DestroyList(DLinkList &L){
    while (L->next!=NULL)
    {
        DeleteNextDNode(L);
        /* code */
    }
    free(L);    //释放头结点
    L=NULL;
}

//打印链表
void ShowDLinkList(DLinkList L){
    
    while (L->next!=NULL)
    {
        /* code */
    }
    
}
