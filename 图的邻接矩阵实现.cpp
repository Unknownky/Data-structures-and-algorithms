#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;


//实现无向网和有向网差别不大，只需要减少相反的赋值就行了；实现有向图只需要用1/0表示状态就行了，无向图也差不多

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
	cout<<"请输入对应的顶点数和边数:" <<endl;
	cin >> G.vexnum >> G.arcnum;//输入顶点数和边数
	//G.visited = (int*)malloc(sizeof(int)*G.vexnum);
	for (int i = 0; i < G.vexnum; i++)//构建顶点表
	{
		cout<<"请输入所有顶点:"<<endl; 
		cin >> G.vexs[i];
	}

	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			G.arcs[i][j] = Maxint;			
	for(int i = 0; i<G.vexnum; i++)
		G.visited[i] = false;
	//构建邻接矩阵
	for (int k = 0; k < G.arcnum; k++) {
		cout<<"请依次输入顶点及边的权值"<<endl;
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
	return true;
}

//统计无向网某个顶点的度(=Out+in)
int CountDu(AMGraph G) {
	int count = 0, index = 0;
	VerTexType V;//声明顶点
	cin >> V;
	index = LocateVex(G, V);
	for (int i = 0; i < G.vexnum; i++)//检索入度
		if (G.arcs[i][index] != Maxint) count++;
//	for (int j = 0; j < G.vexnum; j++)//检索出度
//		if (G.arcs[index][j] != Maxint) count++;
	return count;
}

//引用了对应矩阵实现的代码
//算法思路为使用DFS（Depth-First-Search）深度优先遍历

void DFS(AMGraph* G, int v) {
	cout << v;//访问第v个顶点
	if(G->visited[v]==false)
		cout << G->vexs[v] << endl;//打印该结点
	G->visited[v] = true;
	for (int i = 0; i < G->vexnum; i++)
		if (!G->visited[i] && G->arcs[v][i]!=Maxint)//i是v的邻接点，如果i未访问，则递归调用DFS
			DFS(G, i);
}

//图的邻接矩阵的广度优先遍历,非递归算法，利用队列实现
//void BFS(AMGraph* G, int v) {
//
//
//
//}

int main() {
	int count;
	AMGraph G;
	CreateUDN(G);//键盘输入创建图
	//PrintUDN(G);//打印图
	//cout<<CountDu(G)<<endl;//统计某个顶点的度
	DFS(&G, 0);
	return 0;
}
