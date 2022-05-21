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
void QueuePush(Queue* pq, QDataType x); //队尾入数据
void QueuePop(Queue* pq);                //队头出数据
QDataType QueueFront(Queue* pq);        //取队头数据
QDataType QueueBack(Queue* pq);          //取队尾数据
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

