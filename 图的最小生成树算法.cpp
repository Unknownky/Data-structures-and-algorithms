#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"ͼ���ڽӾ���ṹ.h"

//���Դ�������漰���ֻ�����ͼ����С�������㷨(��ʱ�����ڽӾ���),�Լ��߼������ʾͼ�ṹ��ʹ��,���Prim��Kruskal�㷨

typedef struct {
	int begin;
	int end;
	int weight;
}Edge;


AMGraph G;
//Prim�㷨���ɴ�ӡ����С������,����ʱû�����ض������ݽṹ��������
//prim�㷨������˼·������Dijkstra�㷨
void MiniSpanTree_Prim(int begin) {
	int min, min_index;//min�洢��Сȥ��Ȩֵ,min_index�洢��СȨֵ��Ӧ������ֵ
	//��Ӧ��������
	int lowcost[MVnum];//��Ӧdis����,ͨ�����ϸ������ҵ������Ѿ����ʵļ��ϵ���δ���ʼ��ϵ�֮����̵ı�(�����dis������Դ��Ϊ�����˼�벻ͬ)
	int adjvex[MVnum];//��Ӧpath����,������
	//����������visited����,��lowcost��ӦֵΪ0��ʾ�Ѿ�����
	//��ʼ��
	for (int i = 0; i < G.vexnum; i++)
	{
		lowcost[i] = G.arcs[begin][i];//��Դ��Ϊ�����г�ʼ�������ں���Ĳ���
		adjvex[i] = begin;//��ʼ����Ϊbegin���±�
	}
	//�����ѷ���
	lowcost[begin] = 0;
	adjvex[begin] = 0;

	//�ظ����в���
	for (int count = 1; count < G.vexnum; count++)
	{
		min = Maxint;
		min_index = -1;
		//�ҵ���С�����ڼ���(�ڽӾ���)
		for (int j = 0; j < G.vexnum; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{//lowcost�����д洢�Ķ��ǵ�ǰ�ѷ��ʼ������·��
				min = lowcost[j];
				min_index = j;//�洢����
			}
		}
		//���д�ӡ�ͷ���
		printf("%d %d %d", adjvex[min_index], min_index, min);//��ӡ��Ӧ�ı��Լ���СȨֵ
		lowcost[min_index] = 0;
		for (int k = 1; k < G.vexnum; k++)//�����¼���ĵ��Ƿ���������̵ı�������lowcost�����Լ�adjvex����;begin�Ѿ�����
		{
			if (lowcost != 0 && G.arcs[min_index][k] < lowcost[k]) {
				lowcost[k] = G.arcs[min_index][k];
				adjvex[k] = min_index;
			}
		}
	}
}

void TransToEdge(AMGraph* U, Edge* edges) {

}

int Find(int* parent , int f) {
	while (parent[f] > 0) {
		f = parent[f];//���鼯ԭ��֮����ѧϰ
	}
	return f;
}

//Kruskal�㷨�������Ǹ�������õı߼�����������鼯�����γɻ�·����ѡȡ�ߴӶ��õ���С������

//��С�������е�Kruskal�㷨;��ע��Ϊ����˲��ñ߼�������з���
void MiniSpanTree_Kruskal() {
	Edge edge[MaxEdge];//����߼������ʾ��ͼ�ṹ
	int parent[MVnum]; //����һ���������жϱ����֮���Ƿ��γɻ�·(ʹ�õ��˲��鼯��ԭ��)
	TransToEdge(&G, edge);//���ڽӾ���ת��Ϊ�߼������ʾ(���Ҹñ߼������Ѿ����ݱ�Ȩֵ�Ĵ�С����������)
	//��ʼ��parent����,�Ա߼���������
	for (int i = 0; i < G.vexnum; i++)
	{
		parent[i] = 0;
	}
	//���ݸ��������ν���ѡȡ(ǰ���ǲ������γɻ�·,first confirm)
	for (int j = 0; j < G.arcnum; j++)
	{
		int n, m;
		n = Find(parent, edge[j].begin);
		m = Find(parent, edge[j].end);//���ݲ��鼯��ԭ����в���,֮���ж��Ƿ��γɻ�·
		if (n != m) {//˵��û�γɻ�·
			parent[n] = m;
			printf("(%d, %d) %d\n", edge[j].begin, edge[j].end, edge[j].weight);//�ҵ��˸ı߲����д�ӡ
		}
	}
}



int main() {
	CreateUDN(G);
	MiniSpanTree_Prim(0);
	MiniSpanTree_Kruskal();
	return 0;
}