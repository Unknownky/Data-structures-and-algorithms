#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


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
}AMGraph;//Adjacency Matrix Graph

//算法思想：
//1.输入顶点数和边数
//2.构建顶点表
//3.初始化邻接矩阵
//4.构建邻接矩阵


int LocateVex(AMGraph G, VerTexType a) {
	int index = 0;
	for (index = 0; index < G.vexnum; index++)//找到该顶点在顶点表中的位置
		if (a == G.vexs[index]) return index;
	return -1;
}

//构建邻接矩阵的函数
Status CreateUDN(AMGraph& G) {//引用图结构
	VerTexType V1, V2;
	int w = Maxint;
	int i = 0, j = 0;
	cin >> G.vexnum >> G.arcnum;//输入顶点数和边数
	for (int i = 0; i < G.vexnum; i++)//构建顶点表
		cin >> G.vexs[i];
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = Maxint;
	//构建邻接矩阵
	for (int k = 0; k < G.arcnum; k++) {
		cin >> V1 >> V2 >> w; //输入一条边依附的顶点及边的权值
		i = LocateVex(G, V1);
		j = LocateVex(G, V2);
		if (i == -1 || j == -1) return false;
		G.arcs[i][j] = w;
		G.arcs[j][i] = w;
	}
	return true;
}

//打印无向图，不需要修改图
Status PrintUDN(AMGraph u) {
	//使用数组遍历
	for (int i = 0; i < u.vexnum; i++)
		for (int j = 0; j < u.vexnum; j++)
			if (u.arcs[i][j] != Maxint) cout << u.vexs[i] << "->" << u.vexs[j] << u.arcs[i][j] << endl;
}

//统计无向网某个顶点的度(=Out+in)
int CountDu(AMGraph G) {
	int count = 0, index = 0;
	VerTexType V;//声明顶点
	cin >> V;
	index = LocateVex(G, V);
	for (int i = 0; i < G.vexnum; i++)//检索入度
		if (G.arcs[i][index] != Maxint) count++;
	for (int j = 0; j < G.vexnum; j++)//检索出度
		if (G.arcs[index][j] != Maxint) count++;
	return count;
}



int main() {
	AMGraph G;
	CreateUDN(G);
	return 0;
}
