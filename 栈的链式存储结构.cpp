#define _CRT_SECURE_NO_WARNINGS 1

//ջ����ʽ�洢�ṹ,ʹ��ͷ�巨,ͨ������
#include <stdio.h>
#include <stdlib.h>



typedef struct Stack//ջ�ڵ�
{
	int data;
	struct Stack* next;
}StackNode, * LinkStackptr;


typedef struct
{//topջ���ڵ����Ž�ջ�ͳ�ջ������仯����㲻ͬ������),Ϊ��ʵʱ�޸�ջ���ڵ㶨��һ���ṹ�塣
	LinkStackptr top;
	int count;
}LinkStack;//ջ�ڵ���


int push(LinkStack* S, int num)
{
	LinkStackptr p = (LinkStackptr)malloc(sizeof(StackNode));
	p->data = num;
	p->next = S->top;
	S->top = p;
	S->count++;
	return 0;
}

int pop(LinkStack* S, int* e)
{
	LinkStackptr p;
	if (S->top == NULL)//��ջ
		return 0;
	*e = S->top->data;
	p = S->top;
	S->top = S->top->next;
	S->count--;
	free(p);
	return 1;
}

int Is_Empety(const LinkStack* const S) {
	if (S->top == NULL)
		return 1;
	else return 0;
}
int main() {
	LinkStack L;
	int e;
	int num = 10;
	L.top = (LinkStackptr)malloc(sizeof(StackNode));
	L.top->next = NULL;
	L.count = 0;
	push(&L, num);
	pop(&L, &e);
	printf("%d\n", e);
	return 0;
}


