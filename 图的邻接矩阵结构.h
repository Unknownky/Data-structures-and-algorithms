#pragma once
#define MaxLen 15 //定义BFS的队列的最大长度
#define Maxint 32767  //表示极大值，即无穷;为赋值时即为正无穷
#define MVnum 100     //最大顶点数，方阵的行数
typedef char VerTexType;  //设顶点的数据类型为字符型
typedef int ArcType;  //假设边的权值类型为整型
typedef bool Status;   //定义返回类型


//定义图结构体
typedef struct AMGraph {
	VerTexType vexs[MVnum]; //定义顶点表
	ArcType arcs[MVnum][MVnum]; //定义邻接矩阵
	int vexnum, arcnum;
	int visited[MVnum];//定义访问顶点的数组
}AMGraph;//Adjacency Matrix Graph

Status CreateUDN(AMGraph& G);