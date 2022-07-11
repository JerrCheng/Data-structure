#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"



//�����½ڵ�
LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}


	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}


////�ö���ָ���ʼ��
//void LTInit(LTNode** pphead)
//{
//	*pphead = BuyListNode(-1);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}


//����ַ��ʼ��
LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	(phead)->next = phead;
	(phead)->prev = phead;
	return phead;
}


//�п�
bool LTEmpty(LTNode* phead)
{
	assert(phead);

	return phead->next == phead;
}




//��ӡ
void LTPrint(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;

	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}




//β��
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	LTInsert(phead, x);
}



//ͷ��
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);
	//LTNode* newnode = BuyListNode(x);
	//LTNode* next = phead->next;

	////phead   newnode   next
	//phead->next = newnode;
	//newnode->prev = phead;
	//next->prev = newnode;
	//newnode->next = next;

	LTInsert(phead->next, x);    //����LTInsert
}


//βɾ
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	////assert(phead->next != phead);
	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;

	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	LTErase(phead->prev);
}




//ͷɾ
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(!LTEmpty(phead));
	//LTNode* tail = phead->next;

	////phead  tail  tail->next
	//phead->next = tail->next;
	//tail->next->prev = phead;
	//free(tail);
	//tail = NULL;
	LTErase(phead->next);
}


//��pos֮ǰ����
void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);

	//prev  newnode  pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}


//��posλ��ɾ��
void LTErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;

	//prev pos next
	prev->next = next;
	next->prev = prev;
	free(pos);
}
