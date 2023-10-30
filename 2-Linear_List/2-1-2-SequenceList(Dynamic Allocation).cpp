//2.顺序表的实现-动态分配

#include<stdio.h>
#include <malloc.h>

#define InitSize 10	//默认最大长度
typedef struct {
	int *data;	//指示动态分配的指针
	int MaxSize;	//表的最大容量
	int length;		//当前长度
}SeqList;

void InitList(SeqList &L) {
	//用malloc申请一片连续的存储空间
	L.data = (int *)malloc(InitSize * sizeof(int));	//data指向分配空间的首地址
	L.length = 0;	//顺序表的当前长度
	L.MaxSize = InitSize;	//顺序表的最大容量
}

//增加动态数组的最大容量
void IncreaseSize(SeqList& L, int len) {
	int *p = L.data;
	L.data = (int*)malloc(( L.MaxSize +len)*sizeof(int));	//开辟一片新的存储空间
	for (int i = 0; i < L.length; i++) {
		L.data[i] = p[i];	//将p中以前的数据复制到新的地址中   ==>时间开销大<==
	}
	L.MaxSize = L.MaxSize + len;	//改变顺序表的最大容量
	free(p);	//释放以前的存储空间
}



int main() {
	SeqList L;
	InitList(L);
	printf("当前最大容量为：%d\n", L.MaxSize);
	IncreaseSize(L, 5);
	printf("当前最大容量为：%d", L.MaxSize);


	return 0;

}