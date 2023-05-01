#define _CRT_SECURE_NO_WARNINGS 1


//该源文件中包含二叉树的构建（结构体定义）
//二叉树的前中后序递归遍历
//二叉树的中序遍历非递归算法(模拟递归利用栈)
//二叉树的层序遍历(利用队列)
//获取二叉树的深度的递归算法
//栈和队列的基本操作


#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 20

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
//进行结构体的定义

//定义队列 ,顺序循环队列 
typedef struct Queue {
    TreeNode* value[MAXSIZE];//该队列存树结点 
    int front, rear;//定义头尾指针 
}SqQueue;





//前序遍历，中序遍历和后序遍历都是DFS算法(深度优先) 
//二叉树的前序遍历
void preorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    cout << root->value << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//二叉树的中序遍历
void inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->value << endl;
    inorderTraversal(root->right);
}

//二叉树的后序遍历
void postorderTraversal(TreeNode* root) {
    //递归出口
    if (root == NULL)//当经过的结点为空,返回
        return;
    //递归遍历,访问结点在经过路径的最后访问；三种访问经过的路径相同
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << endl;
}

//这里使用顺序存储的循环队列,稍微容易点 
//初始化队列 
void InitQueue(SqQueue* p) {
    p->value[MAXSIZE] = { 0 };
    p->front = p->rear = 0;	//front==rear时队列为空;rear+1%MAXSIZE==front时队列满 
}

//入队 ;p队列指针，in树结点指针 
void enQueue(SqQueue* p, TreeNode* in) {
    if (p->rear + 1 % MAXSIZE == p->front)//队列满 
        return;
    p->value[p->rear] = in;
    p->rear = p->rear + 1 % MAXSIZE;//更新rear 
}

//出队，p队列指针，out树结构体指针用于出队的访问 
void deQueue(SqQueue* p, TreeNode** out) {
    if (p->front == p->rear)
        return;
    *out = p->value[p->front];
    p->front = (p->front + 1) % MAXSIZE;
}


int QueueEmpety(SqQueue* p) {
    if (p->front == p->rear)
        return true;//为空返回真值 
    return false;
}


//二叉树的层序遍历
void LeverTraversal(TreeNode* root) {
    TreeNode* p = root;
    SqQueue* qu = (SqQueue*)malloc(sizeof(SqQueue));
    InitQueue(qu);//初始化队列 
    //对每一层进行遍历，同时并不需要分哪一层 ;BFS算法进行路径访问 (广度优先),利用队列实现 
    if (root == NULL)//树为空，无法遍历 
        return;
    //利用已经创建的一个队列
    enQueue(qu, p);
    //当队列不为空时进行遍历 (说明未遍历完)
    while (!QueueEmpety(qu)) {
        //出队
        deQueue(qu, &p);//root赋值为出队的元素 
        cout << p->value << endl;//打印出队的元素进行层序遍历
        //如果有左孩子，则加入队列 
        if (p->left)
            enQueue(qu, p->left);
        if (p->right)
            enQueue(qu, p->right);
    }
}

//获取树的深度
int TreeDepth(TreeNode* const p) {
    if (p == NULL)
        return 0;
    //左右子树最大深度+1
    return max(TreeDepth(p->left), TreeDepth(p->right)) + 1;
}

typedef struct Stack {
    TreeNode* value[MAXSIZE];
    int top;
    int count;//栈元素数量
};

//const修饰s,无法更改s指向
void InitStack(Stack* const s) {
    s->value[MAXSIZE] = { 0 };
    s->top = 0;
    s->count = 0;
}

//由于使用TreeNode* 数组传入TreeNode*
void enStack(Stack* const s, TreeNode* p) {
    if (s->count == MAXSIZE)//栈满
        return;
    s->value[s->top++] = p;
    s->count++;
}

void deStack(Stack* const s, TreeNode** p) {
    if (!s->count)//栈空
        return;
    *p = s->value[--s->top];
    s->count--;
}

void inorderTraversalloop(TreeNode* const root)
{
    if (root == NULL)
        return;
    TreeNode* p = root;//用p来操作传入的指针，表明p要该变指向
    Stack* s = (Stack*)malloc(sizeof(Stack));
    InitStack(s);

    while (p || s->count != 0) {
        if (p) {
            enStack(s, p);
            p = p->left;
        }
        else {
            deStack(s, &p);
            cout << p->value << endl;
            p = p->right;
        }
    }
}

void BuildBTree(TreeNode** p) {
    char ch = 0;
    TreeNode* pr = *p;
    scanf("%c", &ch);
    if (ch == '#')
        *p = NULL;
    else {
        pr->value = ch;
        BuildBTree(&(pr->left));
        BuildBTree(&(pr->right));
    }
}

int main() {
    // 创建二叉树
    TreeNode* root = new TreeNode{ 1, NULL, NULL };
    root->left = new TreeNode{ 2, NULL, NULL };
    root->right = new TreeNode{ 3, NULL, NULL };
    root->left->left = new TreeNode{ 4, NULL, NULL };
    root->left->right = new TreeNode{ 5, NULL, NULL };
    root->right->left = new TreeNode{ 6, NULL, NULL };
    root->right->right = new TreeNode{ 7, NULL, NULL };

    TreeNode* newtree = new TreeNode;
    // 遍历二叉树
    cout << "Preorder traversal(前序遍历): \n";
    preorderTraversal(root);


    cout << "Inorder traversal(中序遍历): \n";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal(后序遍历): \n";
    postorderTraversal(root);
    cout << endl;

    cout << "Leveltraversal(层序遍历): \n";
    LeverTraversal(root);//借助队列，同样可以借助两个栈模拟队列实现
    cout << endl;

    cout << "Inorder traversal(中序遍历非递归算法):\n";
    inorderTraversalloop(root);
    cout << endl;

    cout << "The depth of the tree:\n";
    cout << TreeDepth(root) << endl;

    cout << "根据字符数组创建二叉树:\n";
    BuildBTree(&newtree);
    cout << endl;

    cout << "Preorder traversal(前序遍历): \n";
    preorderTraversal(newtree);
    //123##45#6##7###
    return 0;
}