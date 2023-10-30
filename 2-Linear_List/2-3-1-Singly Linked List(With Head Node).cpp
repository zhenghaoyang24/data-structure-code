// 带头结点的单链表

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef int ElemType;

// 定义一个单链表节点类型
typedef struct LNode
{
	ElemType data;			// 节点数据元素
	struct LNode *next; 	// 指针域
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
	L->next = NULL; // 头结点指针为空
	return true;
}

// 按值查找，找到数据域==e的节点
LNode* LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

// 在指定节点前插入一个新节点
// 由于单链表只能找到后继节点，因此可以利用交换元素的方法实现。( 时间复杂度为O(1) )
bool InsertPriorNode(LNode *p, int e)
{
	if (p == NULL)
	{
		printf("目标节点为空，插入失败。");
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		printf("内存分配失败。");
		return false;
	}
	// 将新节点插入到p后，再交换p与s的数据元素
	s->next = p->next;
	s->data = p->data;
	p->next = s;
	p->data = e;
	return true;
}

// 在指定节点后插入一个新节点
bool InsertNextNode(LNode *p, int e)
{
	if (p == NULL)
	{
		printf("目标节点为空，插入失败。");
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		printf("内存分配失败。");
		return false;
	}
	s->data = e; // 连接新节点
	s->next = p->next;
	p->next = s;
	return true;
}

// 按位查找，返回第i个节点
LNode *GetElem(LinkList L, int i)
{
	if (i < 0)
	{
		printf("查找位置不合法。");
		return NULL;
	}
	LNode *p;
	p = L;
	int j = 0;
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

// 按位序插入（带头结点）
bool ListInsert(LinkList L, int i, int e)
{
	if (i < 1)
	{
		printf("插入位置不合法。\n"); // 插入位置至少为1
		return false;
	}
	// LNode *p;  // 定义一个指针p
	// int j = 0; // 指针指向第几个节点（头结点为0个节点）
	// p = L;	   // 指针指定链表第一个节点（指向头结点）

	// while (p != NULL && j < i - 1)
	// { // 插入位置为i,则指针p最终应该指向i-1个节点
	// 	p = p->next;
	// 	j++;
	// }
	// 以上代码替换为GetElem()
	LNode *p = GetElem(L, i - 1);

	// if (p == NULL) {
	// 	printf("插入位置不合法。\n");
	// 	return false;
	// }
	// LNode *s = (LNode *)malloc(sizeof(LNode));	//申请一个新节点
	// s->data = e;			//将新节点插入到p之后
	// s->next = p->next;
	// p->next = s;
	// return true;
	// 以上代码可直接换为InsertNextNode()方法。
	return InsertNextNode(p, e);
}

// 链表长度
void ListLength(LinkList &L)
{
	int n = 0;
	LNode *p;
	p = L->next;
	while (p != NULL)
	{
		p = p->next;
		n++;
	}
	printf("链表长度=%d\n", n);
}

// 单链表显示
void ListShow(LinkList &L)
{
	LNode *p; // 定义一个指针p
	p = L;
	p = p->next;
	for (int i = 1; p != NULL; i++)
	{
		printf("LNode[%d]=%d\n", i, p->data);
		p = p->next;
	}
}

// 删除指定位置的节点
bool ListDelete(LinkList &L, int i, int &e)
{
	if (i < 1)
	{
		return false;
	}
	LNode *p;
	int j = 0;
	p = L;
	while (p != NULL && j < i - 1)
	{
		p = p->next;
		j++;
	}
	if (p == NULL || p->next == NULL)
	{
		return false;
	}
	LNode *q = p->next; // 令q指向被删除节点
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

// 建立单链表（尾插法）
LinkList List_TailInster(LinkList &L)
{
	int x;								 // 输入的数据
	L = (LinkList)malloc(sizeof(LNode)); // 建立头结点，初始化空表
	L->next = NULL;
	LNode *s, *r = L;		// 指针s为新节点，r指向尾节点
	printf("输入节点的数据：");
	// scanf("%d", &x);
	while (scanf("%d", &x) != EOF)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s; // 使指针永远指向表尾
		printf("输入节点的数据："); 
		// scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// 建立单链表（头插法）  单链表的逆序则可以先正序找出数据元素，再利用头插法插入到新的链表
LinkList List_HeadInsert(LinkList &L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); // 初始化单链表
	L->next = NULL;						 // 使单链表尾部始终为NULL;(消除脏数据);
	printf("输入节点的数据：");
	while (scanf("%d", &x) != EOF)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		printf("输入节点的数据：");
	}
	return L;
}

int main()
{
	LinkList L;
	InitList(L);
	List_HeadInsert(L);
	ListLength(L);
	ListShow(L);

	printf("sizeof(int):%d\n",sizeof(LNode));
	printf("sizeof(int*):%d",sizeof(LNode*));

	return 0;
}
