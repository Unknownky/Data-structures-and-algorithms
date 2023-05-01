#define _CRT_SECURE_NO_WARNINGS 1

//ջ��ʵ��
//1.ջ��˳��洢�ṹ*************************
#include <stdio.h>
#include <time.h>
#define MAXSIZE 20
//����˳��ջ�Ľṹ��
typedef struct 
{
	int data[MAXSIZE];
	int top;//����ջ��ָ��
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
	if (S->top == -1)//ջ��
		return 0;
	*e = S->data[S->top];
	S->top--;
	return 1;
}


int main() {
	SqStack L;
	int num;
	int e;
	L.top = -1;//ʹ�����ж���Ŀ�ջʱtop=-1
	srand(time(0));
	for (int count = 0; count < 10; count++)
	{
		num = rand()%20+1;
		push(&L, num);//��ջ
	}
	printf("%d\n", num);
	pop(&L, &e);//��ջ,e�õ�ɾ����Ԫ��
	printf("%d\n", e);
	return 0;
}

