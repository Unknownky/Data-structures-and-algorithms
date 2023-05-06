#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"ͼ���ڽӾ���ṹ.h"
#include"ջ����ʽ�洢�ṹ.h"
using namespace std;

#define MAX_NUM 30   //������󶥵���Ϊ30

AMGraph G;
//Dijkstra�㷨
//�����㷨:
//1.������������ļ���U��T������U�д�����ҵ����·���Ķ��㣬����T�д�ŵ�ǰ��δ�ҵ������·���Ķ���
//2.��ʼ״̬��U��ֻ����Դ�㣬��ΪV0
//3.Ȼ��Ӽ���T��ѡ��Դ��V0·��������̵Ķ���u���뵽����U��
//4.����U��ÿ����һ���µĶ��㶼Ҫ�޸�Դ��V0������T�и�������µĵ�ǰ���·������ֵ[��ֵδԭ���ĵ�ǰ���·���������Դ������㵽��ö���Ĵ�Ȩ·�������еĽ�С��]
//5.�ص�3���˹��̲����ظ���ֱ������T�еĶ���ȫ�����뵽����U��Ϊֹ
void Dijkstra(int begin) {
	LinkStack* S = (LinkStack*)malloc(sizeof(LinkStack));
	int minpath = Maxint;//��������Ϊ��С��·������
	int path[MAX_NUM];//�������зŸ�λ�ö���·����ǰ������λ��
	int dis[MAX_NUM];//���������ڸ�����ʼ���㵽�����������̾���;���û����ֵΪ�����
	//��ʼ��path·���;���
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[begin][i] != Maxint) {//��ǰ������Դ����о���
			path[i] = begin;
			dis[i] = G.arcs[begin][i];
		}
		else { //��ǰ������Դ�㲻ֱ������
			path[i] = -1;
			dis[i] = Maxint;
		}
	}
	//��ʼ��δ���ʵĶ�������
	for (int i = 0; i < G.vexnum; i++)
		G.visited[i] = false;

	G.visited[begin] = true;//Դ�����
	//�����ظ����²���
	for (int i = 0; i < G.vexnum - 1; i++)//�ظ���δ���ʵ�G.vexnum-1�����������ʼ���
	{
		//��������Ҫ��֤�ҵ���С��Ȩֵ�Լ�����(�Ҿ����ܹ����Ч��,�����flord�㷨)
		int min_index = -1;
		int min_dis = Maxint;
		for (int j = 0; j < G.vexnum; j++) {
			if (G.visited[j] == false && min_dis > dis[j]) {
				min_dis = dis[j];
				min_index = j;
			}
		}//�ҵ���С�����
		if (min_dis == Maxint)//�����ڣ�������һ��
			continue;


		//��֤T���϶������U����
		G.visited[i] = true;
			//����·���;�������(ǰ���ǲ�Ϊbegin���ҵ�����Ķ�����о���)
		for (int j = 0; j < G.vexnum; j++) {
			if (dis[j]>dis[min_index]+G.arcs[min_index][j] && G.arcs[i][j] != Maxint) {
				dis[j] = dis[min_index] + G.arcs[min_index][j];
				path[j] = min_index;
			}
		}
	}
	for (int i = 0; i < G.vexnum; i++)
	{
		if (i == begin) continue;
		//���·�����Ⱥ���Ϣ
		cout << G.vexs[begin] + "->" + G.vexs[i];
		if (dis[i] == Maxint)//û��·��
		{
			cout << ": no path" << endl;
			continue;
		}
		//���涼����·���ģ�ʹ��ջ����������·��;��������Ϊ������������int
		push(S, i);//�����յ�
		int p = path[i];
		while (p != -1) {//ֱ��������Դ��
			push(S, p);
			p = path[p];
		}
		//����Դ��
		push(S, begin);
		//��ջ����
		int num = 0;//�洢ջ��ֵ
		while (!Is_Empety(S)) {//��ȫ��ջ
			pop(S, &num);
			if (num == begin) cout << G.vexs[begin] << endl;
			cout << G.vexs[num]+"->";
		}
	}
}

//����ջ�ṹ����ȳ������Դ�ӡ��Դ�㵽����������·��
void Dijkstra_Print(int begin) {

}


int main() {
	CreateUDN(G);//����һ���ڽӾ���ͼ
	Dijkstra(0); 
	return 0;
}
