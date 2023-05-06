#define _CRT_SECURE_NO_WARNINGS 1

//2.两个具有相同数据类型的栈共享空间
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 20
//定义共享空间的栈结构
typedef struct {
	int data[MAXSIZE];
	int top1;//Stack1 point
	int top2;//Stack2 point
}SqDoubleStack;


int push(SqDoubleStack* S, int num, int Stacknumber)
{
	if (S->top1 + 1 == S->top2)//栈满
		return 0;
	if (Stacknumber == 1)
		S->data[++S->top1] = num;
	else if (Stacknumber == 2)
		S->data[--S->top2] = num;
	return 1;
}

int pop(SqDoubleStack* S, int* e, int Stacknumber)
{
	if (Stacknumber == 1)
	{
		if (S->top1 == -1)//栈空
			return 0;
		*e = S->data[S->top1--];
	}
	else if (Stacknumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return 0;
		*e = S->data[S->top2++];
	}
	return 1;
}


int main() {
	SqDoubleStack S;
	int num;
	int e1;
	int e2;
	S.top1 = -1;
	S.top2 = MAXSIZE;
	srand(time(0));
	printf("匿名结构体的字节数:%zd", sizeof(SqDoubleStack));
	printf("依次放入栈中的数据 ");
	for (int count = 0; count < 10; count++)
	{
		num = rand() % 20 + 1;
		push(&S, num, 1);
		push(&S, num, 2);
		printf("%.2d ", num);
	}
	printf("\n");
	for (int count = 0; count < MAXSIZE / 2; count++)
	{
		pop(&S, &e2, 1);
		pop(&S, &e1, 2);
		printf("栈1  %.2d  栈2  %.2d\n", e1, e2);
	}
	return 0;
}