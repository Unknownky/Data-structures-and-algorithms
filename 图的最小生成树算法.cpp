#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"图的邻接矩阵结构.h"

//这个源代码中涉及两种基本的图的最小生成树算法(暂时基于邻接矩阵),以及边集数组表示图结构的使用,完成Prim和Kruskal算法

typedef struct {
	int begin;
	int end;
	int weight;
}Edge;


AMGraph G;
//Prim算法生成打印出最小生成树,我暂时没有用特定的数据结构保存下来
//prim算法的整体思路类似于Dijkstra算法
void MiniSpanTree_Prim(int begin) {
	int min, min_index;//min存储最小去拿权值,min_index存储最小权值对应的索引值
	//对应两个数组
	int lowcost[MVnum];//对应dis数组,通过不断更新来找到整个已经访问的集合点与未访问集合点之间最短的边(这点与dis数组以源点为主体的思想不同)
	int adjvex[MVnum];//对应path数组,这个差不多
	//不额外增加visited数组,用lowcost对应值为0表示已经访问
	//初始化
	for (int i = 0; i < G.vexnum; i++)
	{
		lowcost[i] = G.arcs[begin][i];//以源点为起点进行初始化，便于后面的操作
		adjvex[i] = begin;//初始化都为begin的下标
	}
	//顶点已访问
	lowcost[begin] = 0;
	adjvex[begin] = 0;

	//重复进行操作
	for (int count = 1; count < G.vexnum; count++)
	{
		min = Maxint;
		min_index = -1;
		//找到最小边用于加入(邻接矩阵)
		for (int j = 0; j < G.vexnum; j++)
		{
			if (lowcost[j] != 0 && lowcost[j] < min)
			{//lowcost数组中存储的都是当前已访问集的最短路径
				min = lowcost[j];
				min_index = j;//存储下来
			}
		}
		//进行打印和访问
		printf("%d %d %d", adjvex[min_index], min_index, min);//打印对应的边以及最小权值
		lowcost[min_index] = 0;
		for (int k = 1; k < G.vexnum; k++)//根据新加入的点是否能缩短最短的边来更新lowcost数组以及adjvex数组;begin已经访问
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
		f = parent[f];//并查集原理，之后再学习
	}
	return f;
}

//Kruskal算法基本就是根据排序好的边集数组借助并查集避免形成环路不断选取边从而得到最小生成树

//最小生成树中的Kruskal算法;关注点为边因此采用边集数组进行访问
void MiniSpanTree_Kruskal() {
	Edge edge[MaxEdge];//定义边集数组表示的图结构
	int parent[MVnum]; //定义一个数组来判断边与边之间是否形成环路(使用到了并查集的原理)
	TransToEdge(&G, edge);//将邻接矩阵转换为边集数组表示(并且该边集数组已经根据边权值的大小进行了排序)
	//初始化parent数组,对边集进行排序
	for (int i = 0; i < G.vexnum; i++)
	{
		parent[i] = 0;
	}
	//根据各个边依次进行选取(前提是并不会形成环路,first confirm)
	for (int j = 0; j < G.arcnum; j++)
	{
		int n, m;
		n = Find(parent, edge[j].begin);
		m = Find(parent, edge[j].end);//根据并查集的原理进行查找,之后判断是否形成环路
		if (n != m) {//说明没形成环路
			parent[n] = m;
			printf("(%d, %d) %d\n", edge[j].begin, edge[j].end, edge[j].weight);//找到了改边并进行打印
		}
	}
}



int main() {
	CreateUDN(G);
	MiniSpanTree_Prim(0);
	MiniSpanTree_Kruskal();
	return 0;
}