// ��ͷ���ĵ�����

#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef int ElemType;

// ����һ��������ڵ�����
typedef struct LNode
{
	ElemType data;			// �ڵ�����Ԫ��
	struct LNode *next; 	// ָ����
} LNode, *LinkList;

// 2-��ʼ��һ����������ͷ��㣬һ���ô�ͷ��㣩
bool InitList(LinkList &L)
{
	L = (LNode *)malloc(sizeof(LNode));
	// L = (LNode*)malloc(sizeof(LinkList));	//����һ��ͷ���
	if (L == NULL)
	{
		printf("��ʼ��ʧ�ܡ�");
		return false; // �ڴ治�㣬����ʧ�ܣ��ֿ��ܷ���
	}
	L->next = NULL; // ͷ���ָ��Ϊ��
	return true;
}

// ��ֵ���ң��ҵ�������==e�Ľڵ�
LNode* LocateElem(LinkList L, int e)
{
	LNode *p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
	}
	return p;
}

// ��ָ���ڵ�ǰ����һ���½ڵ�
// ���ڵ�����ֻ���ҵ���̽ڵ㣬��˿������ý���Ԫ�صķ���ʵ�֡�( ʱ�临�Ӷ�ΪO(1) )
bool InsertPriorNode(LNode *p, int e)
{
	if (p == NULL)
	{
		printf("Ŀ��ڵ�Ϊ�գ�����ʧ�ܡ�");
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		printf("�ڴ����ʧ�ܡ�");
		return false;
	}
	// ���½ڵ���뵽p���ٽ���p��s������Ԫ��
	s->next = p->next;
	s->data = p->data;
	p->next = s;
	p->data = e;
	return true;
}

// ��ָ���ڵ�����һ���½ڵ�
bool InsertNextNode(LNode *p, int e)
{
	if (p == NULL)
	{
		printf("Ŀ��ڵ�Ϊ�գ�����ʧ�ܡ�");
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));
	if (s == NULL)
	{
		printf("�ڴ����ʧ�ܡ�");
		return false;
	}
	s->data = e; // �����½ڵ�
	s->next = p->next;
	p->next = s;
	return true;
}

// ��λ���ң����ص�i���ڵ�
LNode *GetElem(LinkList L, int i)
{
	if (i < 0)
	{
		printf("����λ�ò��Ϸ���");
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

// ��λ����루��ͷ��㣩
bool ListInsert(LinkList L, int i, int e)
{
	if (i < 1)
	{
		printf("����λ�ò��Ϸ���\n"); // ����λ������Ϊ1
		return false;
	}
	// LNode *p;  // ����һ��ָ��p
	// int j = 0; // ָ��ָ��ڼ����ڵ㣨ͷ���Ϊ0���ڵ㣩
	// p = L;	   // ָ��ָ�������һ���ڵ㣨ָ��ͷ��㣩

	// while (p != NULL && j < i - 1)
	// { // ����λ��Ϊi,��ָ��p����Ӧ��ָ��i-1���ڵ�
	// 	p = p->next;
	// 	j++;
	// }
	// ���ϴ����滻ΪGetElem()
	LNode *p = GetElem(L, i - 1);

	// if (p == NULL) {
	// 	printf("����λ�ò��Ϸ���\n");
	// 	return false;
	// }
	// LNode *s = (LNode *)malloc(sizeof(LNode));	//����һ���½ڵ�
	// s->data = e;			//���½ڵ���뵽p֮��
	// s->next = p->next;
	// p->next = s;
	// return true;
	// ���ϴ����ֱ�ӻ�ΪInsertNextNode()������
	return InsertNextNode(p, e);
}

// ������
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
	printf("������=%d\n", n);
}

// ��������ʾ
void ListShow(LinkList &L)
{
	LNode *p; // ����һ��ָ��p
	p = L;
	p = p->next;
	for (int i = 1; p != NULL; i++)
	{
		printf("LNode[%d]=%d\n", i, p->data);
		p = p->next;
	}
}

// ɾ��ָ��λ�õĽڵ�
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
	LNode *q = p->next; // ��qָ��ɾ���ڵ�
	e = q->data;
	p->next = q->next;
	free(q);
	return true;
}

// ����������β�巨��
LinkList List_TailInster(LinkList &L)
{
	int x;								 // ���������
	L = (LinkList)malloc(sizeof(LNode)); // ����ͷ��㣬��ʼ���ձ�
	L->next = NULL;
	LNode *s, *r = L;		// ָ��sΪ�½ڵ㣬rָ��β�ڵ�
	printf("����ڵ�����ݣ�");
	// scanf("%d", &x);
	while (scanf("%d", &x) != EOF)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		r->next = s;
		r = s; // ʹָ����Զָ���β
		printf("����ڵ�����ݣ�"); 
		// scanf("%d", &x);
	}
	r->next = NULL;
	return L;
}

// ����������ͷ�巨��  �����������������������ҳ�����Ԫ�أ�������ͷ�巨���뵽�µ�����
LinkList List_HeadInsert(LinkList &L)
{
	LNode *s;
	int x;
	L = (LinkList)malloc(sizeof(LNode)); // ��ʼ��������
	L->next = NULL;						 // ʹ������β��ʼ��ΪNULL;(����������);
	printf("����ڵ�����ݣ�");
	while (scanf("%d", &x) != EOF)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = x;
		s->next = L->next;
		L->next = s;
		printf("����ڵ�����ݣ�");
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
