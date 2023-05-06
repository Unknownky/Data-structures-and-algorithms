#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include"图的邻接矩阵结构.h"
#include"栈的链式存储结构.h"
using namespace std;

#define MAX_NUM 30   //定义最大顶点数为30

AMGraph G;
//Dijkstra算法
//总体算法:
//1.设置两个顶点的集合U和T，集合U中存放已找到最短路径的顶点，集合T中存放当前还未找到的最短路径的顶点
//2.初始状态是U中只包含源点，设为V0
//3.然后从集合T中选择到源点V0路径长度最短的顶点u加入到集合U中
//4.集合U中每加入一个新的顶点都要修改源点V0到集合T中各顶点的新的当前最短路径长度值[该值未原来的当前最短路径长度与从源点过顶点到达该顶点的带权路径长度中的较小者]
//5.回到3，此过程不断重复，直到集合T中的顶点全部加入到集合U中为止
void Dijkstra(int begin) {
	LinkStack* S = (LinkStack*)malloc(sizeof(LinkStack));
	int minpath = Maxint;//用来更新为最小的路径距离
	int path[MAX_NUM];//在数组中放该位置顶点路径的前驱顶点位置
	int dis[MAX_NUM];//该数组用于更新起始顶点到各个顶点的最短距离;如果没有则赋值为无穷大
	//初始化path路径和距离
	for (int i = 0; i < G.vexnum; i++) {
		if (G.arcs[begin][i] != Maxint) {//当前顶点与源点间有距离
			path[i] = begin;
			dis[i] = G.arcs[begin][i];
		}
		else { //当前顶点与源点不直接相连
			path[i] = -1;
			dis[i] = Maxint;
		}
	}
	//初始化未访问的顶点数组
	for (int i = 0; i < G.vexnum; i++)
		G.visited[i] = false;

	G.visited[begin] = true;//源点访问
	//进行重复更新操作
	for (int i = 0; i < G.vexnum - 1; i++)//重复将未访问的G.vexnum-1个顶点加入访问集合
	{
		//在这里需要保证找到最小的权值以及顶点(我觉得能够提高效率,借鉴于flord算法)
		int min_index = -1;
		int min_dis = Maxint;
		for (int j = 0; j < G.vexnum; j++) {
			if (G.visited[j] == false && min_dis > dis[j]) {
				min_dis = dis[j];
				min_index = j;
			}
		}//找到最小顶点边
		if (min_dis == Maxint)//不存在，更新下一个
			continue;


		//保证T集合顶点加入U集合
		G.visited[i] = true;
			//更新路径和距离数组(前提是不为begin并且到后面的顶点间有距离)
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
		//输出路径长度和信息
		cout << G.vexs[begin] + "->" + G.vexs[i];
		if (dis[i] == Maxint)//没有路径
		{
			cout << ": no path" << endl;
			continue;
		}
		//后面都是有路径的，使用栈来遍历整个路径;在这里因为定义的问题存入int
		push(S, i);//推入终点
		int p = path[i];
		while (p != -1) {//直到遍历到源点
			push(S, p);
			p = path[p];
		}
		//推入源点
		push(S, begin);
		//出栈遍历
		int num = 0;//存储栈顶值
		while (!Is_Empety(S)) {//完全出栈
			pop(S, &num);
			if (num == begin) cout << G.vexs[begin] << endl;
			cout << G.vexs[num]+"->";
		}
	}
}

//利用栈结构后进先出的特性打印从源点到各个点的最短路径
void Dijkstra_Print(int begin) {

}


int main() {
	CreateUDN(G);//创建一个邻接矩阵图
	Dijkstra(0); 
	return 0;
}
