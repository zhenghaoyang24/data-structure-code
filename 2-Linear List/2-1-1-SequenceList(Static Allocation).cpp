#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 1.˳顺序表的实现（静态分配）
#define MaxSize 100 // 最大长度
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length; // 顺序表长度
} SqList;

// 初始化静态表
void InitList(SqList &L)
{
	// for (int i = 0; i < MaxSize; i++) {
	//	L.data[i] = 0;
	// }
	L.length = 0;
}

// 插入元素
bool LinstInsert(SqList &L, int i, int e)
{
	if (i < 1 || i > L.length + 1)
	{
		printf("插入位置不合法。\n");
		return false;
	}
	if (L.length > MaxSize)
	{
		printf("线性表已满。");
		return false;
	}
	for (int j = L.length; j >= i; j--)
	{ // 元素后移
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e; // 插入元素
	L.length++;
	return true;
}

// 删除指定元素
bool ListDelete(SqList &L, int i, int &e)
{
	if (i < 1 || i > L.length)
	{
		printf("位置不合法。\n");
		return false;
	}
	e = L.data[i - 1]; // 删除的元素
	for (int j = i; j < L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

// 获取指定元素
int GetElem(SqList L, int i)
{
	return L.data[i - 1];
}

// 按值查找
int LocateElem(SqList L, int e)
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
		{
			return i + 1; // �ҵ��󷵻�λ��
		}
	}
	return 0;
}

// 打印数据
void PrintList(SqList &L)
{
	for (int i = 0; i < L.length; i++)
	{
		printf("data[%d]=%d\n", i, L.data[i]);
	}
}

// 销毁线性表
void DestotyList(SqList &L)
{
	L.length = 0;
}

// 判断空
bool ListEmpty(SqList L)
{
	return L.length == 0;
}

// 将最小元素用最后一个元素代替，带回最小元素
bool deleteMin(SqList &L, int &e)
{
	int m = 0;
	if (L.data == 0)
		return false;
	e = L.data[0];
	for (int i = 1; i < L.length; i++)
		if (L.data[i] < e)
		{
			e = L.data[i];
			m = i;
		}

	L.data[m] = L.data[L.length - 1];
	L.length--;
	return true;
}

// 逆置顺序表
bool reverse(SqList &L)
{
	if (ListEmpty(L))
		return false; // 表空返回false
	int i = 0, tmp;

	while (i < L.length / 2)
	{
		tmp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = tmp;
		i++;
	}
	return true;
}

// 时间复杂度为O(n),空间复杂度为O(1)，删除表中为x的元素，快慢指针
void deleteByX(SqList &L, int x)
{
	int k = 0, i; // 需要删的个数
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)//把不符合要求的范围放在判断里面
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}
void CreateList(SqList &L)
{
	int e, i = 0;
	printf("输入第1个数据：");
	while (scanf("%d", &e) != EOF)
	{
		L.data[i] = e;
		i++;
		L.length++;
		printf("输入第%d个数据：", i);
	}
}

// 1.传统方法：删除有序表中值在min带max之间的元素
bool deleteMinToMax(SqList &L,int min ,int max){
	if (min>max)
		return false;
	if (L.length==0)
		return false;
	int k =0,i;
	for (i = 0; L.data[i]<max;i++ )  
	{
		if (L.data[i]>min)
		{
			k++;  //记录被删个数
		}
	}
	for (int j = i; j < L.length; j++)
	{
		L.data[j-k]=L.data[j];   //删除符合条件的元素
	}
	L.length=L.length-k;
	return true;

}

// 1.双指针方法：删除有序表中值在min带max之间的元素
void deleteMinToMax2(SqList &L, int min,int max)
{
	int k = 0, i; // 需要删的个数
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i]<min||L.data[i]>max)	//把不符合要求的范围放在判断里面
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}

// 删除有序表中的重复元素
void deleteSame(SqList &L)
{
	int k , i; // 需要删的个数
	for (k = 0,i=1; i < L.length-1; i++)
	{
		if (L.data[k]!=L.data[i])	//把不符合要求的范围放在判断里面
		{
			k++;
			L.data[k] = L.data[i];
			
		}
	}
	L.length = k+1;
}


int main()
{
	int a = 1;
	SqList L;
	InitList(L);
	CreateList(L);
	PrintList(L);
	printf("\n");

	// LinstInsert(L, 6, 10);

	int e = -1;

	// if (ListDelete(L, 5, e))
	// {
	// 	printf("删除的元素为%d\n", e);
	// }
	// PrintList(L);
	// printf("%d\n", GetElem(L, 2));
	// printf("%d\n", LocateElem(L, 2));

	// 删除最小元素
	//  deleteMin(L,e);
	//  printf("e=%d",e);

	// 逆置
	// reverse(L);

	// 时间复杂度为O(n),空间复杂度为O(1)，删除表中为x的元素，快慢指针
	// deleteByX(L, 5);

	// 删除有序表中值在min带max之间的元素
	// deleteMinToMax(L,2,6);
	// deleteMinToMax2(L,2,6);

	// 删除有序表相同元素
	deleteSame(L);
	
	PrintList(L);

	return 0;
}
