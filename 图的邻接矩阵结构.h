#pragma once
#define MaxLen 15 //����BFS�Ķ��е���󳤶�
#define Maxint 32767  //��ʾ����ֵ��������;Ϊ��ֵʱ��Ϊ������
#define MVnum 100     //��󶥵��������������
typedef char VerTexType;  //�趥�����������Ϊ�ַ���
typedef int ArcType;  //����ߵ�Ȩֵ����Ϊ����
typedef bool Status;   //���巵������


//����ͼ�ṹ��
typedef struct AMGraph {
	VerTexType vexs[MVnum]; //���嶥���
	ArcType arcs[MVnum][MVnum]; //�����ڽӾ���
	int vexnum, arcnum;
	int visited[MVnum];//������ʶ��������
}AMGraph;//Adjacency Matrix Graph

Status CreateUDN(AMGraph& G);