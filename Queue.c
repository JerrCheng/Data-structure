#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

//队尾入数据
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

//队头出数据
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty);

	//一个节点
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}

	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

//取队头数据
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty);
	return pq->head->data;

}

//取队尾数据
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty);
	return pq->tail->data;

}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head = NULL;
}


int QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		++size;
		cur = cur->next;
	}
	return size;
}
