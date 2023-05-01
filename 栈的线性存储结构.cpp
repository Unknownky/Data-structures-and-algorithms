#define _CRT_SECURE_NO_WARNINGS 1

//栈的实现
//1.栈的顺序存储结构*************************
#include <stdio.h>
#include <time.h>
#define MAXSIZE 20
//定义顺序栈的结构体
typedef struct 
{
	int data[MAXSIZE];
	int top;//用于栈顶指针
}SqStack;

int push(SqStack* S, int num) {
	if (S->top == MAXSIZE - 1)
		return 0;
	S->top++;
	S->data[S->top] = num;
	return 1;
}

int pop(SqStack* S, int* e)
{
	if (S->top == -1)//栈空
		return 0;
	*e = S->data[S->top];
	S->top--;
	return 1;
}


int main() {
	SqStack L;
	int num;
	int e;
	L.top = -1;//使用书中定义的空栈时top=-1
	srand(time(0));
	for (int count = 0; count < 10; count++)
	{
		num = rand()%20+1;
		push(&L, num);//入栈
	}
	printf("%d\n", num);
	pop(&L, &e);//出栈,e得到删除的元素
	printf("%d\n", e);
	return 0;
}

