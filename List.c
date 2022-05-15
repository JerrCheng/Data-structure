#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

LTNode* BuyListNode(LTDataType x)
{
	LTNode* node = (LTNode*)malloc(sizeof(LTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->next = NULL;
	node->prev = NULL;
	return node;
}

//void ListInit(LTNode** pphead)
//{
//	*pphead = BuyListNode(-1);
//	(*pphead)->next = *pphead;
//	(*pphead)->prev = *pphead;
//}

LTNode* ListInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}

//β��
void ListPusahBack(LTNode* phead, LTDataType x)
{
	/*assert(phead);
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	assert(phead);
	ListInsert(phead, x);
}


//ͷ��
void ListPushFront(LTNode* phead, LTDataType x)
{
	/*LTNode* newnode = BuyListNode(x);
	LTNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;*/
	assert(phead);
	ListInsert(phead->next, x);
}


//βɾ
void ListPopBack(LTNode* phead)
{
	assert(phead);
	assert(ListEmpty(phead));
	//LTNode* tail = phead->prev;  //��β
	//LTNode* tailPrev = tail->prev; //��β����ǰһ��
	//free(tail);
	//tailPrev->next = phead;
	//phead->prev = tailPrev;
	ListErase(phead->prev);

}



void ListPrint(LTNode* phead)
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

bool ListEmpty(LTNode* phead)
{
	assert(phead);
	return phead->next = phead;
}


//ͷɾ
void ListPopFront(LTNode* phead)
{
	assert(phead);
	ListErase(phead->next);
}


//��posǰ����
void ListInsert(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}


//ɾ��pos�ڵ�
void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* next = pos->next;
	prev->next = prev;
	next->prev = next;
	free(pos);
}