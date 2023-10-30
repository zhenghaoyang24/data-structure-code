// 双链表链式存储
#include <stdio.h>
#include <malloc.h>


typedef struct
{
    int value;
} ElemType;

// 定义二叉树   若需要寻找父节点，可以添加*parent指针
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 创建头节点
void CreatRootNode(BiTNode *&T, int i)
{
    ElemType e;
    e.value = i;
    T = (BiTree)malloc(sizeof(BiTNode));
    T->data = e;
    T->lchild = NULL;
    T->rchild = NULL;
}

// 插入节点
bool AddTNode(BiTNode *T, int i, char position, BiTNode *&add)
{
    ElemType e;
    e.value = i;
    if (T->lchild != NULL && T->rchild != NULL)
    {
        printf("此节点已经有左右孩子。\n");
        return false;
    }
    else
    {
        if ((position == 'l' && T->lchild != NULL) || (position == 'r' && T->rchild != NULL))
        {
            printf("相应位置已有孩子。\n");
            return false;
        }
        else
        {
            BiTNode *s;
            s = (BiTree)malloc(sizeof(BiTNode));
            s->data = e;
            s->lchild = NULL;
            s->rchild = NULL;
            if (position == 'l')
            {
                T->lchild = s;
            }
            if (position == 'r')
            {
                T->rchild = s;
            }
            add = s;
            return true;
        }
    }
}

void visit(BiTNode *node)
{
    printf("%d", node->data.value);
}

// 先序遍历
void PreOrder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        /* code */
    }
}

// 中序遍历
void InOrder(BiTree T)
{
    if (T != NULL)
    {
        PreOrder(T->lchild);
        visit(T);
        PreOrder(T->rchild);
    }
}

// 后序遍历
void PostOrder(BiTree T)
{
    if (T != NULL)
    {
        PreOrder(T->lchild);
        PreOrder(T->rchild);
        visit(T);
    }
}



// 树的深度
int treeDeep(BiTree T)
{
    if (T == NULL)
    {
        return 0;
    }
    else
    {
        int l = treeDeep(T->lchild);
        int r = treeDeep(T->rchild);
        return l > r ? l + 1 : r + 1;
    }
}

int main()
{
    BiTree T;
    CreatRootNode(T, 1);
    BiTNode *node21, *node22, *node31, *node32, *node33, *node41;
    AddTNode(T, 2, 'l', node21);
    AddTNode(T, 3, 'r', node22);

    AddTNode(node21, 4, 'l', node31);
    AddTNode(node21, 5, 'r', node32);

    AddTNode(node22, 6, 'l', node32);

    AddTNode(node31, 7, 'r', node41);

    printf("树的深度：%d\n", treeDeep(T));

    printf("\n先序:");
    PreOrder(T);
    printf("\n中序:");
    InOrder(T);
    printf("\n后序:");
    PostOrder(T);
}
