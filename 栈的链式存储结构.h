#pragma once
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


int push(LinkStack* S, int num);
int pop(LinkStack* S, int* e);
int Is_Empety(const LinkStack* const S);
