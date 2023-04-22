#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


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
}AMGraph;//Adjacency Matrix Graph

//�㷨˼�룺
//1.���붥�����ͱ���
//2.���������
//3.��ʼ���ڽӾ���
//4.�����ڽӾ���


int LocateVex(AMGraph G, VerTexType a) {
	int index = 0;
	for (index = 0; index < G.vexnum; index++)//�ҵ��ö����ڶ�����е�λ��
		if (a == G.vexs[index]) return index;
	return -1;
}

//�����ڽӾ���ĺ���
Status CreateUDN(AMGraph& G) {//����ͼ�ṹ
	VerTexType V1, V2;
	int w = Maxint;
	int i = 0, j = 0;
	cin >> G.vexnum >> G.arcnum;//���붥�����ͱ���
	for (int i = 0; i < G.vexnum; i++)//���������
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = Maxint;
	//�����ڽӾ���
	for (int k = 0; k < G.arcnum; k++) {
		cin >> V1 >> V2 >> w; //����һ���������Ķ��㼰�ߵ�Ȩֵ
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);
		if (i == -1 || j == -1) return false;
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
	return true;
}

//��ӡ����ͼ������Ҫ�޸�ͼ
Status PrintUDN(AMGraph u) {
	//ʹ���������
	for (int i = 0; i < u.vexnum; i++)
		for (int j = 0; j < u.vexnum; j++)
			if (u.arcs[i][j] != Maxint) cout << u.vexs[i] << "->" << u.vexs[j] << u.arcs[i][j] << endl;
}

//ͳ��������ĳ������Ķ�(=Out+in)
int CountDu(AMGraph G) {
	int count = 0, index = 0;
	VerTexType V;//��������
	cin >> V;
	index = LocateVex(G, V);
	for (int i = 0; i < G.vexnum; i++)//�������
		if (G.arcs[i][index] != Maxint) count++;
	for (int j = 0; j < G.vexnum; j++)//��������
		if (G.arcs[index][j] != Maxint) count++;
	return count;
}



int main() {
	AMGraph G;
	CreateUDN(G);
	return 0;
}
