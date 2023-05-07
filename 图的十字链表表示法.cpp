#define _CRT_SECURE_NO_WARNINGS 1

//该代码用于用十字链表法实现图结构,该方法便于统计有向图的度，同时减少无向图的存储空间

//十字链表更多关注顶点，容易找到有向图中的弧头和弧尾，便于统计有向图的度
#include<iostream>
#include<stdlib.h>
using namespace std;

#define MVNum 100
typedef char VerTexType;
typedef int ArcType;
typedef bool Status;

typedef struct ArcNode {
	ArcType tailvex,headvex; //tailvex弧尾顶点，headvex弧头顶点
	struct ArcNode* tlink,* hlink;//tlink同一弧尾的下一条出弧；hlink同一弧头的下一条入弧
}ArcNode;



typedef struct VNode {
	VerTexType value;
	ArcNode* firstin;//第一个入弧
	ArcNode* firstout;//第一个出弧
}VNode;


typedef struct OrthoList {
	VNode* vertexlist;//顶点表
	int vexnum;//顶点数
	int arcnum;//边数
}OrthoList;

int LocateVex(OrthoList* u, VerTexType c) {
	for (int i = 0; i < u->vexnum; i++)
		if (u->vertexlist[i].value == c) return i;
	return -1;
}




Status CreateOrthoList(OrthoList* G) {
	int i, j;
	cout << "请分别输入顶点数和边数:";
	cin >> G->vexnum >> G->arcnum;//输入顶点数和边数
	G->vertexlist = (VNode*)malloc(sizeof(VNode*) * G->vexnum);//动态分配空间
	cout << "Please give the total data of the vex:";
	for (int k = 0; k < G->vexnum; k++) {//初始化顶点表
		cin >> G->vertexlist[k].value;
		G->vertexlist[k].firstin = NULL;
		G->vertexlist[k].firstout = NULL;
	}
	for (int k = 0; k < G->vexnum; k++) {
		VerTexType V1, V2;
		printf("请输入第%d条弧的起点和终点（用空格隔开）：\n", k + 1) ;
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

void DestoryOrthoList(const OrthoList* const u) {//销毁十字链表
	for (int i = 0; i < u->vexnum; i++)//遍历每个顶点销毁出弧
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
	cout << "十字链表的信息如下:";
	for (int i = 0; i < u->vexnum; i++) {
		cout << "当前顶点为" << u->vertexlist[i].value<<endl;
		ArcNode* p = u->vertexlist[i].firstout;//访问出度
		while (p) {
			cout << u->vertexlist[p->tailvex].value<<"-->"<<u->vertexlist[p->headvex].value<<endl;
			p = p->tlink;
		}
	}
}

int main() {
	OrthoList* G = new OrthoList;
	CreateOrthoList(G);//创建十字链表
	PrintOrthoList(G);//打印当前十字链表
	DestoryOrthoList(G);//销毁当前十字链表
	cout << "当前十字链表操作完成";
	return 0;
}
