#define _CRT_SECURE_NO_WARNINGS 1

//�ô���������ʮ������ʵ��ͼ�ṹ,�÷�������ͳ������ͼ�Ķȣ�ͬʱ��������ͼ�Ĵ洢�ռ�

//ʮ����������ע���㣬�����ҵ�����ͼ�еĻ�ͷ�ͻ�β������ͳ������ͼ�Ķ�
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef bool Status;

typedef struct ArcNode {
	ArcType tailvex,headvex; //tailvex��β���㣬headvex��ͷ����
	struct ArcNode* tlink,* hlink;//tlinkͬһ��β����һ��������hlinkͬһ��ͷ����һ���뻡
}ArcNode;



typedef struct VNode {
	VerTexType value;
	ArcNode* firstin;//��һ���뻡
	ArcNode* firstout;//��һ������
}VNode;


typedef struct OrthoList {
	VNode* vertexlist;//�����
	int vexnum;//������
	int arcnum;//����
}OrthoList;

int LocateVex(OrthoList* u, VerTexType c) {
	for (int i = 0; i < u->vexnum; i++)
		if (u->vertexlist[i].value == c) return i;
	return -1;
}




Status CreateOrthoList(OrthoList* G) {
	int i, j;
	cout << "��ֱ����붥�����ͱ���:";
	cin >> G->vexnum >> G->arcnum;//���붥�����ͱ���
	G->vertexlist = (VNode*)malloc(sizeof(VNode*) * G->vexnum);//��̬����ռ�
	cout << "Please give the total data of the vex:";
	for (int k = 0; k < G->vexnum; k++) {//��ʼ�������
		cin >> G->vertexlist[k].value;
		G->vertexlist[k].firstin = NULL;
		G->vertexlist[k].firstout = NULL;
	}
	for (int k = 0; k < G->vexnum; k++) {
		VerTexType V1, V2;
		printf("�������%d�����������յ㣨�ÿո��������\n", k + 1) ;
		cin >> V1 >> V2;
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);
		if (i == -1 || j == -1) return false;
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode*));
		p->tailvex = i;
		p->headvex = j;
		p->tlink = G->vertexlist[i].firstout;
		G->vertexlist[i].firstout = p;
		p->hlink = G->vertexlist[j].firstin;
		G->vertexlist[j].firstin = p;
	}
	return true;
}

void DestoryOrthoList(const OrthoList* const u) {//����ʮ������
	for (int i = 0; i < u->vexnum; i++)//����ÿ���������ٳ���
	{
		ArcNode* p = u->vertexlist[i].firstout;
		while (p) {
			ArcNode* q = p->tlink;
			free(q);
			p = q;
		}
	}
}

void PrintOrthoList(const OrthoList* const u) {
	cout << "ʮ���������Ϣ����:";
	for (int i = 0; i < u->vexnum; i++) {
		cout << "��ǰ����Ϊ" << u->vertexlist[i].value<<endl;
		ArcNode* p = u->vertexlist[i].firstout;//���ʳ���
		while (p) {
			cout << u->vertexlist[p->tailvex].value<<"-->"<<u->vertexlist[p->headvex].value<<endl;
			p = p->tlink;
		}
	}
}

int main() {
	OrthoList* G = new OrthoList;
	CreateOrthoList(G);//����ʮ������
	PrintOrthoList(G);//��ӡ��ǰʮ������
	DestoryOrthoList(G);//���ٵ�ǰʮ������
	cout << "��ǰʮ������������";
	return 0;
}
