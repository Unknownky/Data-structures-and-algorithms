#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define OK 1
#define ERROR 0
#define MAXSIZE 20//�洢�ռ��ʼ������

typedef int Status;//Status�Ǻ������ͣ���ֵ�Ǻ������״̬���룬��OK�ȣ������Զ��������,���ڱ�ʾ״̬
typedef int ElemType;//typedef ���ڸ��Ի����壬��int����ͻ



typedef struct//����һ���ṹ�����������һ�����Ա����ص���Ϣ(�о�������߿ɶ���)
{
	ElemType data[MAXSIZE];//����������洢����Ԫ��
	int length;			//���Ա�ǰ���ȣ�ͨ���ṹ��洢��Ҫʹ�õ����Ա�������Ϣ(�Ҿ���Ӧ�������ݽṹ���Ͻ��ص�)
}SqList;






//˳��洢�ṹ���Ԫ�صĲ���
Status GetElem(SqList L, int i, ElemType* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];
	return OK;
}


//ʵ����(��i��)ĳ��λ�ò���Ԫ�صĲ���,�����ظ�ֵ
Status ListInsert(SqList* L, int i, ElemType e)//����ָ����ܽ����޸�
{//�����д�
	if (L->length == MAXSIZE)//���Ա�����
	{
		return ERROR;
	}
	if (i<1 || i>L->length+1)//��Ҫ�����λ�ñȵ�һ��λ�û�С�������һ��λ�ú�һ��λ�û���ʱ(���Ƕ��в���)
	{
		return ERROR;
	}
	//���ƶ�Ԫ��,�Ӻ��濪ʼ����,���ᶪʧ����
	for (int k = L->length; k >= i; k--)//��������λ��ͬ������
	{
		L->data[k] = L->data[k - 1];//��i = 3   3 <- 2  length <- length-1  �ܹ���ɵ�i�����Ժ����ݵĺ���
	}
	L->data[i - 1] = e;//��������
	L->length++;//���ȸ���
	return OK;
}


////
////ʵ��ɾ������
//Status ListDelete(SqList* L, int i, ElemType* e)//����
//{
//
//
//
//
//}

int main() //����һ��
{
	int ret = 0;
	int a = 0;
	SqList L = { {1,2,3,4,5}, 5 };//��ʼ��
	ret = ListInsert(&L, 3, 8);
	printf("%d\n", ret);
	for (int i = 0; i < L.length; i++)
	{
		printf("%d ", L.data[i]);
	}
	GetElem(L, 3, &a);
	printf("\n%d\n", a);
	return 0;
}