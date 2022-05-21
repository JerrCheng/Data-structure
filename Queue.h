#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x); //��β������
void QueuePop(Queue* pq);                //��ͷ������
QDataType QueueFront(Queue* pq);        //ȡ��ͷ����
QDataType QueueBack(Queue* pq);          //ȡ��β����
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

