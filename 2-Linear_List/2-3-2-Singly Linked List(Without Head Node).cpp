// 不带头结点的单链表

#include<stdio.h>
#include <string.h>
#include <malloc.h>

//定义一个单链表节点类型
typedef struct LNode {
	int data;	//节点数据元素
	struct LNode* next;			//指针指向下一个节点
}LNode, * LinkList;


//1-初始化一个单链表（不带头结点）
bool InitList(LinkList& L) {
	L = NULL;
	return true;
}

//按位序插入（不带头结点）
bool ListInsert(LinkList &L, int i, int e) {
	if (i<0){
		printf("插入位置不合法。");
		return false;
	}
	if (i==1){	//插入位置为1时，单独处理
		LNode *s = (LNode *)malloc(sizeof(LNode));
		s->next=L;
		s->data = e;
		L = s;	//头指针指向新节点(重新设置链表的第一个位置)
		return true;
	}
	LNode *p;	//利用指针p指向某个节点
	int j = 1;
	p = L;	//指针指向第一个位置
	while (p!=NULL&&j<i-1){		//让p指向插入位置的前一个结点
		p=p->next;
		j++;
	}
	if (p==NULL){
		printf("插入位置不合法，插入错误。");
		return false;
	}
	LNode *s = (LNode *)malloc(sizeof(LNode));	//添加新节点s
	s->data = e;	//将新节点加入链表
	s->next = p->next;
	p->next = s;
	return true;

}

//单链表显示
void ListShow(LinkList &L) {
	LNode* p;	//定义一个指针p
	p = L;  
	for (int i = 1; p!=NULL; i++){
		printf("LNode[%d]=%d\n", i, p->data);
		p = p->next;
	}
}


void ListLength(LinkList &L){
	int n=0;
	LNode *p;
	p=L;
	while(p!=NULL){
		p=p->next;
		n++;
	}
	printf("链表长度=%d\n",n);
}


int main() {

	LinkList L;
	InitList(L);
	ListInsert(L,1,1);
	ListInsert(L,2,2);
	ListInsert(L,3,3);
	ListLength(L);
	ListShow(L);



}