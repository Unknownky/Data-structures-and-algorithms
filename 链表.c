#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20//存储空间初始分配量

typedef int Status;//Status是函数类型，其值是函数结果状态代码，如OK等，属于自定义的类型,用于表示状态
typedef int ElemType;//typedef 用于个性化定义，与int不冲突



typedef struct//定义一个结构体里面放入了一个线性表和相关的信息(感觉可以提高可读性)
{
	ElemType data[MAXSIZE];//真正的数组存储数据元素
	int length;			//线性表当前长度；通过结构体存储需要使用的线性表的相关信息(我觉得应该是数据结构的严谨特点)
}SqList;






//顺序存储结构获得元素的操作
Status GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}


//实现在(第i个)某个位置插入元素的操作,并返回该值
Status ListInsert(SqList* L, int i, ElemType e)//传入指针才能进行修改
{//首先判错
	if (L->length == MAXSIZE)//线性表已满
	{
		return ERROR;
	}
	if (i<1 || i>L->length+1)//当要插入的位置比第一个位置还小，比最后一个位置后一个位置还大时(即非队列插入)
	{
		return ERROR;
	}
	//先移动元素,从后面开始遍历,不会丢失数据
	for (int k = L->length; k >= i; k--)//插入最后的位置同样适用
	{
		L->data[k] = L->data[k - 1];//若i = 3   3 <- 2  length <- length-1  能够完成第i个及以后数据的后移
	}
	L->data[i - 1] = e;//插入数据
	L->length++;//长度更新
	return OK;
}


////
////实现删除操作
//Status ListDelete(SqList* L, int i, ElemType* e)//传入
//{
//
//
//
//
//}

int main() //尝试一下
{
	int ret = 0;
	int a = 0;
	SqList L = { {1,2,3,4,5}, 5 };//初始化
	ret = ListInsert(&L, 3, 8);
	printf("%d\n", ret);
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	GetElem(L, 3, &a);
	printf("\n%d\n", a);
	return 0;
}