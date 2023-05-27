#pragma once
//图的邻接表表示法一般用于稀疏图
//时间复杂度为O(n+e) ,空间复杂度为O(n) 

typedef char VerTexType; //定义顶点的数据类型
typedef int ArcType;
typedef bool Status;

#define MVNum 100
typedef struct ArcNode { //边结点
	int adjvex; //该边所指向点的位置，弧头所指向的点
	struct ArcNode* nextarc; //指向下一条边的指针
	int info; //和边有关的信息
}ArcNode;


typedef struct VNode {
	VerTexType value;  //顶点信息
	ArcNode* firstarc; //指向第一个边结点的指针
}VNode;//定义顶点结构体,顶点结构体数组


struct AMGraph {
	int vexnum, arcnum; //定义顶点数和边数
	VNode* vertices; //定义了顶点结构体的数组;可以直接存结构体指针来动态规划实际需要的空间
	bool* visited;//动态规划数组长度 
};