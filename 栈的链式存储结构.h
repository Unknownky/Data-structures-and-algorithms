#pragma once
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


int push(LinkStack* S, int num);
int pop(LinkStack* S, int* e);
int Is_Empety(const LinkStack* const S);
