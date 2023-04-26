#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h> 
#include<string.h>
using namespace std;

//ͼ���ڽӱ��ʾ��һ������ϡ��ͼ
//ʱ�临�Ӷ�ΪO(n+e) ,�ռ临�Ӷ�ΪO(n) 

typedef char VerTexType; //���嶥�����������
typedef int ArcType;
typedef bool Status;

#define MVNum 100
typedef struct ArcNode{ //�߽��
	int adjvex; //�ñ���ָ����λ�ã���ͷ��ָ��ĵ�
	struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
	int info; //�ͱ��йص���Ϣ
}ArcNode;


typedef struct VNode{
	VerTexType value;  //������Ϣ
	ArcNode* firstarc; //ָ���һ���߽���ָ��
}VNode;//���嶥��ṹ��,����ṹ������


struct AMGraph {
	int vexnum, arcnum; //���嶥�����ͱ���
	VNode* vertices; //�����˶���ṹ�������;����ֱ�Ӵ�ṹ��ָ������̬�滮ʵ����Ҫ�Ŀռ�
	bool* visited;//��̬�滮���鳤�� 
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
Status CreateAMGraph(AMGraph &G) {//���ﹹ������������.   ����ͼ������ͼ/���ʵ��䶯����
	VerTexType V1, V2;
	int w, i, j;
	cout<<"����ͼ�ı����Ͷ�������"<<endl;
	cin >> G.vexnum >> G.arcnum;//����ͼ�ı����Ͷ�����
	G.vertices = (VNode*)malloc(sizeof(VNode) * G.vexnum);
	G.visited = (bool*)malloc(sizeof(bool)*G.vexnum);
	memset(G.visited, false, sizeof(bool)*G.vexnum);//ʹ��memset�Է���������г�ʼ�� 
	cout<<"�����ͼ��ȫ�����㣺"<<endl;
	for (int k = 0; k < G.vexnum; k++) {
		cin >> G.vertices[k].value;//�������������Ҫ�Ķ��������Ķ��㸳ֵ,ͬʱ��ʼ����ֵ�˵��ٱ߱�
		G.vertices[k].firstarc = NULL;
	}//������ʹ��ͷ�巨����ͼ
	for (int k = 0; k < G.arcnum; k++) {
		cout<<"������Ҫ�����Ķ��㣬����������ߵ�Ȩֵ:"<<endl;
		cin >> V1 >> V2 >> w;//������Ҫ�����Ķ��㣬����������ߵ�Ȩֵ
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);//��λ��Ϣ��Ӧ�����λ��
		if (i == -1 || j == -1) return false;
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));//����һ���µı߽������ͷ��
		p->nextarc = G.vertices[i].firstarc;
		p->adjvex = j;
		p->info = w;
		G.vertices[i].firstarc = p;
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->nextarc = G.vertices[j].firstarc;
		p->adjvex = i;
		p->info = w;
		G.vertices[j].firstarc = p;
	}
	return true;
}

//������������
void PrintAMGraph(const AMGraph* const G) {
	cout<<"ͼ��ӡ����:"<<endl;
	for (int i = 0; i < G->vexnum; i++)
	{
		ArcNode* p = G->vertices[i].firstarc;
		while (p)
		{
			cout << "����:" << G->vertices[i].value;
			cout << "�ڽӵ�" << G->vertices[p->adjvex].value<<endl;
			p = p->nextarc;
		}
	}
}

void DFS(AMGraph* u, int n){
	if(!u->visited[n])
		cout<<u->vertices[n].value;
	u->visited[n] = true;
	ArcNode* p = u->vertices[n].firstarc;
	while(p){//��ǰ��㲻Ϊ�� 
		if(!u->visited[p->adjvex])//��ǰ��㻹û�б����� 
			DFS(u, p->adjvex);//������ȱ��� 
		p = p->nextarc;
	}
}

int main() {
	AMGraph G;
	CreateAMGraph(G);
	PrintAMGraph(&G);
	printf("����������ȱ�����\n");
	DFS(&G, 0);//�ӵ�һ���������������ȱ��� 
	return 0;
}
