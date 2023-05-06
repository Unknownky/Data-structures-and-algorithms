#define _CRT_SECURE_NO_WARNINGS 1

//栈的链式存储结构,使用头插法,通常对于
#include <stdio.h>
#include <stdlib.h>



typedef struct Stack//栈节点
{
	int data;
	struct Stack* next;
}StackNode, * LinkStackptr;


typedef struct
{//top栈顶节点随着进栈和出栈操作会变化（这点不同于链表),为了实时修改栈顶节点定义一个结构体。
	LinkStackptr top;
	int count;
}LinkStack;//栈节点数


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
	if (S->top == NULL)//空栈
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


