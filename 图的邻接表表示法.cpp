#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

typedef char VerTexType; //���嶥�����������
typedef int ArcType;
typedef bool Status;

#define MVNum 100

typedef struct VNode{
	VerTexType value;  //������Ϣ
	ArcNode* firstarc; //ָ���һ���߽���ָ��
}VNode;//���嶥��ṹ��,����ṹ������

typedef struct ArcNode{ //�߽��
	int adjvex; //�ñ���ָ����λ�ã���ͷ��ָ��ĵ�
	struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
	int info; //�ͱ��йص���Ϣ
}ArcNode;

typedef struct AMGraph {
	VNode* vertices; //�����˶���ṹ�������;����ֱ�Ӵ�ṹ��ָ������̬�滮ʵ����Ҫ�Ŀռ�
	int vexnum, arcnum; //���嶥�����ͱ���
};

//��λ������Ϣ��Ӧ�Ķ���
int LocateVex(AMGraph &G, VerTexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vertices[i].value == u) return i;
	return -1;
}

//�����ڽӱ��ʾͼ���ݽṹ�ĺ���
//�㷨˼�룺
//1.���붥�����ͱ���
//2.���������
//3.��ʼ�������ٱ�����
//4.�����ڽӱ�
Status CreateAMGraph(AMGraph &G) {//���ﹹ������������,����ͼ������ͼ/���ʵ��䶯����
	VerTexType V1, V2;
	int w, i, j;
	cin >> G.arcnum >> G.vexnum;//����ͼ�ı����Ͷ�����
	G.vertices = (VNode*)malloc(sizeof(VNode*) * G.vexnum);
	for (int k = 0; k < G.vexnum; k++) {
		cin >> G.vertices[k].value;//�������������Ҫ�Ķ��������Ķ��㸳ֵ,ͬʱ��ʼ����ֵ�˵��ٱ߱�
		G.vertices[k].firstarc = NULL;
	}//������ʹ��ͷ�巨����ͼ
	for (int k = 0; k < G.arcnum; k++) {
		cin >> V1 >> V2 >> w;//������Ҫ�����Ķ��㣬����������ߵ�Ȩֵ
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);//��λ��Ϣ��Ӧ�����λ��
		if (i == -1 || j == -1) return false;
		ArcNode* p = new ArcNode;//����һ���µı߽������ͷ��
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		G.vertices[i].firstarc = p;
		p = new ArcNode;
		p->nextarc = G.vertices[j].firstarc;
		p->adjvex = i;
		G.vertices[j].firstarc = p;
	}
	return true;
}
