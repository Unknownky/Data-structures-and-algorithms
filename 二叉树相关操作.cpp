#define _CRT_SECURE_NO_WARNINGS 1


//��Դ�ļ��а����������Ĺ������ṹ�嶨�壩
//��������ǰ�к���ݹ����
//����������������ǵݹ��㷨(ģ��ݹ�����ջ)
//�������Ĳ������(���ö���)
//��ȡ����������ȵĵݹ��㷨
//ջ�Ͷ��еĻ�������


#include<iostream>
#include<stdlib.h>
using namespace std;

#define MAXSIZE 20

typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
//���нṹ��Ķ���

//������� ,˳��ѭ������ 
typedef struct Queue {
    TreeNode* value[MAXSIZE];//�ö��д������ 
    int front, rear;//����ͷβָ�� 
}SqQueue;





//ǰ���������������ͺ����������DFS�㷨(�������) 
//��������ǰ�����
void preorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    cout << root->value << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//���������������
void inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->value << endl;
    inorderTraversal(root->right);
}

//�������ĺ������
void postorderTraversal(TreeNode* root) {
    //�ݹ����
    if (root == NULL)//�������Ľ��Ϊ��,����
        return;
    //�ݹ����,���ʽ���ھ���·���������ʣ����ַ��ʾ�����·����ͬ
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->value << endl;
}

//����ʹ��˳��洢��ѭ������,��΢���׵� 
//��ʼ������ 
void InitQueue(SqQueue* p) {
    p->value[MAXSIZE] = { 0 };
    p->front = p->rear = 0;	//front==rearʱ����Ϊ��;rear+1%MAXSIZE==frontʱ������ 
}

//��� ;p����ָ�룬in�����ָ�� 
void enQueue(SqQueue* p, TreeNode* in) {
    if (p->rear + 1 % MAXSIZE == p->front)//������ 
        return;
    p->value[p->rear] = in;
    p->rear = p->rear + 1 % MAXSIZE;//����rear 
}

//���ӣ�p����ָ�룬out���ṹ��ָ�����ڳ��ӵķ��� 
void deQueue(SqQueue* p, TreeNode** out) {
    if (p->front == p->rear)
        return;
    *out = p->value[p->front];
    p->front = (p->front + 1) % MAXSIZE;
}


int QueueEmpety(SqQueue* p) {
    if (p->front == p->rear)
        return true;//Ϊ�շ�����ֵ 
    return false;
}


//�������Ĳ������
void LeverTraversal(TreeNode* root) {
    TreeNode* p = root;
    SqQueue* qu = (SqQueue*)malloc(sizeof(SqQueue));
    InitQueue(qu);//��ʼ������ 
    //��ÿһ����б�����ͬʱ������Ҫ����һ�� ;BFS�㷨����·������ (�������),���ö���ʵ�� 
    if (root == NULL)//��Ϊ�գ��޷����� 
        return;
    //�����Ѿ�������һ������
    enQueue(qu, p);
    //�����в�Ϊ��ʱ���б��� (˵��δ������)
    while (!QueueEmpety(qu)) {
        //����
        deQueue(qu, &p);//root��ֵΪ���ӵ�Ԫ�� 
        cout << p->value << endl;//��ӡ���ӵ�Ԫ�ؽ��в������
        //��������ӣ��������� 
        if (p->left)
            enQueue(qu, p->left);
        if (p->right)
            enQueue(qu, p->right);
    }
}

//��ȡ�������
int TreeDepth(TreeNode* const p) {
    if (p == NULL)
        return 0;
    //��������������+1
    return max(TreeDepth(p->left), TreeDepth(p->right)) + 1;
}

typedef struct Stack {
    TreeNode* value[MAXSIZE];
    int top;
    int count;//ջԪ������
};

//const����s,�޷�����sָ��
void InitStack(Stack* const s) {
    s->value[MAXSIZE] = { 0 };
    s->top = 0;
    s->count = 0;
}

//����ʹ��TreeNode* ���鴫��TreeNode*
void enStack(Stack* const s, TreeNode* p) {
    if (s->count == MAXSIZE)//ջ��
        return;
    s->value[s->top++] = p;
    s->count++;
}

void deStack(Stack* const s, TreeNode** p) {
    if (!s->count)//ջ��
        return;
    *p = s->value[--s->top];
    s->count--;
}

void inorderTraversalloop(TreeNode* const root)
{
    if (root == NULL)
        return;
    TreeNode* p = root;//��p�����������ָ�룬����pҪ�ñ�ָ��
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
    // ����������
    TreeNode* root = new TreeNode{ 1, NULL, NULL };
    root->left = new TreeNode{ 2, NULL, NULL };
    root->right = new TreeNode{ 3, NULL, NULL };
    root->left->left = new TreeNode{ 4, NULL, NULL };
    root->left->right = new TreeNode{ 5, NULL, NULL };
    root->right->left = new TreeNode{ 6, NULL, NULL };
    root->right->right = new TreeNode{ 7, NULL, NULL };

    TreeNode* newtree = new TreeNode;
    // ����������
    cout << "Preorder traversal(ǰ�����): \n";
    preorderTraversal(root);


    cout << "Inorder traversal(�������): \n";
    inorderTraversal(root);
    cout << endl;

    cout << "Postorder traversal(�������): \n";
    postorderTraversal(root);
    cout << endl;

    cout << "Leveltraversal(�������): \n";
    LeverTraversal(root);//�������У�ͬ�����Խ�������ջģ�����ʵ��
    cout << endl;

    cout << "Inorder traversal(��������ǵݹ��㷨):\n";
    inorderTraversalloop(root);
    cout << endl;

    cout << "The depth of the tree:\n";
    cout << TreeDepth(root) << endl;

    cout << "�����ַ����鴴��������:\n";
    BuildBTree(&newtree);
    cout << endl;

    cout << "Preorder traversal(ǰ�����): \n";
    preorderTraversal(newtree);
    //123##45#6##7###
    return 0;
}