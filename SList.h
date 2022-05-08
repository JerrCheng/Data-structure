#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;

}SLTNode;

void SListPrint(SLTNode* phead);//遍历打印
SLTNode* BuySListNode(SLTDataType x);//创建新节点
void SListPushBack(SLTNode** pphead, SLTDataType x); //尾插
void SListPushFront(SLTNode** pphead, SLTDataType x); //头插
void SListPopBack(SLTNode** pphead);//尾删 
void SListPopFront(SLTNode** pphead);//头删
SLTNode* SListFind(SLTNode* phead, SLTDataType x);//查找+修改
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//在pos之前插入
void SListErase(SLTNode** pphead, SLTNode* pos);//在pos位置删除
void SListInsertAfter(SLTNode* pos, SLTDataType x);//在pos位置之后插入x
void SListEraseAfter(SLTNode* pos);//在pos位置之后删除x