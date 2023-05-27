#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//二叉排序查找树(Balanced Search Tree)的结构体定义
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,* BiTree;


 bool SearchBST(BiTree T, int key, BiTree f, BiTree*p) {//带回父节点作为查找的拓展便于之后的插入操作
	if (!T)//没找到或者树为空
	{
		(*p) = f;
		return false;
	}

	if (key == T->data) {
		(*p) = T;
		return true;
	}
	else if (key > T->data) {
		return SearchBST(T->rchild, key, T, p);
	}
	else {
		return SearchBST(T->lchild, key, T, p);
	}
}

bool InsertBST(BiTree* T, int key) {
	BiTree p, s;
	if (!SearchBST((*T), key, NULL, &p)) {//查找不成功,插入结点(无论树是否为空,都需要创建一个新的结点)
		s = (BiTree)malloc(sizeof(BiTNode));//(无论树是否为空,都需要创建一个新的结点)
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)//p指向的前驱结点为空，说民整树为空
			(*T) = s;
		else if (key > p->data)//树不为空,说明p指向的前驱结点为待插入的父结点
			p->rchild = s;
		else
			p->lchild = s;
		return true;
	}
	else//查找成功不插入
		return false;
}

bool CreateBST(BiTree* T, int* keys, int n) {//将所有的key插入即可
	for (int i = 0; i < n; i++)
	{
		InsertBST(T, keys[i]);
	}
	return true;
}


bool Delete(BiTree* p)//删除操作,前提已经找到了对应要删除的结点p,是实际删除的代码
{
	BiTree q, s;
	if (!(*p)->rchild)//右子树为空则只重接它的左子树(包含叶子结点)
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if (!(* p) ->lchild) {
		q = *p; *p = (* p) ->rchild; free(q);
	}
	else {//两边都不为空,这里找直接前驱,q做父节点,s从第一个找q则为p
		q = *p; s = (*p)->lchild;
		while (s->rchild)//不断找右结点，同时更新q父结点
		{
			q = s; s = s->rchild;
		}//找到了对应的结点
		(* p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return true;
}

bool DeleteBST(BiTree* T, int key)//代码简洁,删除时调用该函数，与查找比较类似
{
	if (!*T)//树为空或没找到
		return false;
	if (key == (*T)->data)
		return Delete(T);//两步合并,目的为删除对应的结点
	else if (key > (*T)->data)
		return DeleteBST(&(*T)->rchild, key);
	else
		return DeleteBST(&(*T)->lchild, key);//四个步骤每次只选择一个
}


//中序遍历
void inorderTraversal(BiTree T) {
	if (T == NULL)
		return;
	inorderTraversal(T->lchild);
	printf("%d\n",T->data);
	inorderTraversal(T->rchild);
}


//二叉排序树结构中对于一个根结点来说它的左子树结点的值都小于根结点的值，它的右子树结点的值都大于根结点的值
//相关操作:二叉排序树的构建，二叉排序树的查找，二叉排序树的删除，二叉排序树的插入，二叉排序树的判断。【二叉树的左右字数逆转】
//获取深度以及父节点的操作可以继承自二叉树
int main() {
	BiTree T = NULL;
	int keys[10] = { 1,2,3,4,5,6,7,8,9,10 };
	bool Ins, Cre, Del;
	Cre = CreateBST(&T, keys, 10);

	Ins = InsertBST(&T, 11);

	Del = DeleteBST(&T, 8);

	printf("CreateBST:%d, InsertBST:%d, DeleteBST:%d\n", Cre, Ins, Del);
	//遍历二叉排序树,可以使用中序遍历,立即确定了二叉排序树是否正确
	inorderTraversal(T);

	//改变要传入指针,如果要对BiTree操作要传入BiTree的指针
	return 0;
}

