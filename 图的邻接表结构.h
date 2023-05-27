#pragma once
//ͼ���ڽӱ��ʾ��һ������ϡ��ͼ
//ʱ�临�Ӷ�ΪO(n+e) ,�ռ临�Ӷ�ΪO(n) 

typedef char VerTexType; //���嶥�����������
typedef int ArcType;
typedef bool Status;

#define MVNum 100
typedef struct ArcNode { //�߽��
	int adjvex; //�ñ���ָ����λ�ã���ͷ��ָ��ĵ�
	struct ArcNode* nextarc; //ָ����һ���ߵ�ָ��
	int info; //�ͱ��йص���Ϣ
}ArcNode;


typedef struct VNode {
	VerTexType value;  //������Ϣ
	ArcNode* firstarc; //ָ���һ���߽���ָ��
}VNode;//���嶥��ṹ��,����ṹ������


struct AMGraph {
	int vexnum, arcnum; //���嶥�����ͱ���
	VNode* vertices; //�����˶���ṹ�������;����ֱ�Ӵ�ṹ��ָ������̬�滮ʵ����Ҫ�Ŀռ�
	bool* visited;//��̬�滮���鳤�� 
};