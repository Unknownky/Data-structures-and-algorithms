#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

typedef char VerTexType; //定义顶点的数据类型
typedef int ArcType;
typedef bool Status;

#define MVNum 100

typedef struct VNode{
	VerTexType value;  //顶点信息
	ArcNode* firstarc; //指向第一个边结点的指针
}VNode;//定义顶点结构体,顶点结构体数组

typedef struct ArcNode{ //边结点
	int adjvex; //该边所指向点的位置，弧头所指向的点
	struct ArcNode* nextarc; //指向下一条边的指针
	int info; //和边有关的信息
}ArcNode;

typedef struct AMGraph {
	VNode* vertices; //定义了顶点结构体的数组;可以直接存结构体指针来动态规划实际需要的空间
	int vexnum, arcnum; //定义顶点数和边数
};

//定位顶点信息对应的顶点
int LocateVex(AMGraph &G, VerTexType u) {
	for (int i = 0; i < G.vexnum; i++)
		if (G.vertices[i].value == u) return i;
	return -1;
}

//创建邻接表表示图数据结构的函数
//算法思想：
//1.输入顶点数和边数
//2.构建顶点表
//3.初始化顶点临边链表
//4.构建邻接表
Status CreateAMGraph(AMGraph &G) {//这里构建的是无向网,无向图，有向图/网适当变动即可
	VerTexType V1, V2;
	int w, i, j;
	cin >> G.arcnum >> G.vexnum;//输入图的边数和顶点数
	G.vertices = (VNode*)malloc(sizeof(VNode*) * G.vexnum);
	for (int k = 0; k < G.vexnum; k++) {
		cin >> G.vertices[k].value;//构建顶点表，给需要的顶点数量的顶点赋值,同时初始化赋值了的临边表
		G.vertices[k].firstarc = NULL;
	}//接下来使用头插法构建图
	for (int k = 0; k < G.arcnum; k++) {
		cin >> V1 >> V2 >> w;//输入需要构建的顶点，依附于两点边的权值
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);//定位信息对应顶点的位置
		if (i == -1 || j == -1) return false;
		ArcNode* p = new ArcNode;//创建一个新的边结点用于头插
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
