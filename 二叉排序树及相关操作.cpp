#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�������������(Balanced Search Tree)�Ľṹ�嶨��
typedef struct BiTNode {
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode,* BiTree;


 bool SearchBST(BiTree T, int key, BiTree f, BiTree*p) {//���ظ��ڵ���Ϊ���ҵ���չ����֮��Ĳ������
	if (!T)//û�ҵ�������Ϊ��
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
	if (!SearchBST((*T), key, NULL, &p)) {//���Ҳ��ɹ�,������(�������Ƿ�Ϊ��,����Ҫ����һ���µĽ��)
		s = (BiTree)malloc(sizeof(BiTNode));//(�������Ƿ�Ϊ��,����Ҫ����һ���µĽ��)
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)//pָ���ǰ�����Ϊ�գ�˵������Ϊ��
			(*T) = s;
		else if (key > p->data)//����Ϊ��,˵��pָ���ǰ�����Ϊ������ĸ����
			p->rchild = s;
		else
			p->lchild = s;
		return true;
	}
	else//���ҳɹ�������
		return false;
}

bool CreateBST(BiTree* T, int* keys, int n) {//�����е�key���뼴��
	for (int i = 0; i < n; i++)
	{
		InsertBST(T, keys[i]);
	}
	return true;
}


bool Delete(BiTree* p)//ɾ������,ǰ���Ѿ��ҵ��˶�ӦҪɾ���Ľ��p,��ʵ��ɾ���Ĵ���
{
	BiTree q, s;
	if (!(*p)->rchild)//������Ϊ����ֻ�ؽ�����������(����Ҷ�ӽ��)
	{
		q = *p; *p = (*p)->lchild; free(q);
	}
	else if (!(* p) ->lchild) {
		q = *p; *p = (* p) ->rchild; free(q);
	}
	else {//���߶���Ϊ��,������ֱ��ǰ��,q�����ڵ�,s�ӵ�һ����q��Ϊp
		q = *p; s = (*p)->lchild;
		while (s->rchild)//�������ҽ�㣬ͬʱ����q�����
		{
			q = s; s = s->rchild;
		}//�ҵ��˶�Ӧ�Ľ��
		(* p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return true;
}

bool DeleteBST(BiTree* T, int key)//������,ɾ��ʱ���øú���������ұȽ�����
{
	if (!*T)//��Ϊ�ջ�û�ҵ�
		return false;
	if (key == (*T)->data)
		return Delete(T);//�����ϲ�,Ŀ��Ϊɾ����Ӧ�Ľ��
	else if (key > (*T)->data)
		return DeleteBST(&(*T)->rchild, key);
	else
		return DeleteBST(&(*T)->lchild, key);//�ĸ�����ÿ��ֻѡ��һ��
}


//�������
void inorderTraversal(BiTree T) {
	if (T == NULL)
		return;
	inorderTraversal(T->lchild);
	printf("%d\n",T->data);
	inorderTraversal(T->rchild);
}


//�����������ṹ�ж���һ���������˵��������������ֵ��С�ڸ�����ֵ����������������ֵ�����ڸ�����ֵ
//��ز���:�����������Ĺ����������������Ĳ��ң�������������ɾ���������������Ĳ��룬�������������жϡ���������������������ת��
//��ȡ����Լ����ڵ�Ĳ������Լ̳��Զ�����
int main() {
	BiTree T = NULL;
	int keys[10] = { 1,2,3,4,5,6,7,8,9,10 };
	bool Ins, Cre, Del;
	Cre = CreateBST(&T, keys, 10);

	Ins = InsertBST(&T, 11);

	Del = DeleteBST(&T, 8);

	printf("CreateBST:%d, InsertBST:%d, DeleteBST:%d\n", Cre, Ins, Del);
	//��������������,����ʹ���������,����ȷ���˶����������Ƿ���ȷ
	inorderTraversal(T);

	//�ı�Ҫ����ָ��,���Ҫ��BiTree����Ҫ����BiTree��ָ��
	return 0;
}

