#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

// ��ʼ������
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;

}

// ��β�����
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



// ��ͷ������
void QueuePop(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	//ֻ��һ���ڵ�
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


// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}


// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}


// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}


// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->head == NULL;
}




// ���ٶ���
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (pq)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}