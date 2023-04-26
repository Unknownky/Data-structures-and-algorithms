#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h> 
#include<string.h>
using namespace std;

//图的邻接表表示法一般用于稀疏图
//时间复杂度为O(n+e) ,空间复杂度为O(n) 

typedef char VerTexType; //定义顶点的数据类型
typedef int ArcType;
typedef bool Status;

#define MVNum 100
typedef struct ArcNode{ //边结点
	int adjvex; //该边所指向点的位置，弧头所指向的点
	struct ArcNode* nextarc; //指向下一条边的指针
	int info; //和边有关的信息
}ArcNode;


typedef struct VNode{
	VerTexType value;  //顶点信息
	ArcNode* firstarc; //指向第一个边结点的指针
}VNode;//定义顶点结构体,顶点结构体数组


struct AMGraph {
	int vexnum, arcnum; //定义顶点数和边数
	VNode* vertices; //定义了顶点结构体的数组;可以直接存结构体指针来动态规划实际需要的空间
	bool* visited;//动态规划数组长度 
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
Status CreateAMGraph(AMGraph &G) {//这里构建的是无向网.   无向图，有向图/网适当变动即可
	VerTexType V1, V2;
	int w, i, j;
	cout<<"输入图的边数和顶点数："<<endl;
	cin >> G.vexnum >> G.arcnum;//输入图的边数和顶点数
	G.vertices = (VNode*)malloc(sizeof(VNode) * G.vexnum);
	G.visited = (bool*)malloc(sizeof(bool)*G.vexnum);
	memset(G.visited, false, sizeof(bool)*G.vexnum);//使用memset对访问数组进行初始化 
	cout<<"请给出图的全部顶点："<<endl;
	for (int k = 0; k < G.vexnum; k++) {
		cin >> G.vertices[k].value;//构建顶点表，给需要的顶点数量的顶点赋值,同时初始化赋值了的临边表
		G.vertices[k].firstarc = NULL;
	}//接下来使用头插法构建图
	for (int k = 0; k < G.arcnum; k++) {
		cout<<"输入需要构建的顶点，依附于两点边的权值:"<<endl;
		cin >> V1 >> V2 >> w;//输入需要构建的顶点，依附于两点边的权值
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);//定位信息对应顶点的位置
		if (i == -1 || j == -1) return false;
		ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));//创建一个新的边结点用于头插
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

//这里是无向网
void PrintAMGraph(const AMGraph* const G) {
	cout<<"图打印如下:"<<endl;
	for (int i = 0; i < G->vexnum; i++)
	{
		ArcNode* p = G->vertices[i].firstarc;
		while (p)
		{
			cout << "顶点:" << G->vertices[i].value;
			cout << "邻接点" << G->vertices[p->adjvex].value<<endl;
			p = p->nextarc;
		}
	}
}

void DFS(AMGraph* u, int n){
	if(!u->visited[n])
		cout<<u->vertices[n].value;
	u->visited[n] = true;
	ArcNode* p = u->vertices[n].firstarc;
	while(p){//当前结点不为空 
		if(!u->visited[p->adjvex])//当前结点还没有被访问 
			DFS(u, p->adjvex);//进行深度遍历 
		p = p->nextarc;
	}
}

int main() {
	AMGraph G;
	CreateAMGraph(G);
	PrintAMGraph(&G);
	printf("进行深度优先遍历：\n");
	DFS(&G, 0);//从第一个顶点进行深度优先遍历 
	return 0;
}
