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

void SListPrint(SLTNode* phead);//������ӡ
SLTNode* BuySListNode(SLTDataType x);//�����½ڵ�
void SListPushBack(SLTNode** pphead, SLTDataType x); //β��
void SListPushFront(SLTNode** pphead, SLTDataType x); //ͷ��
void SListPopBack(SLTNode** pphead);//βɾ 
void SListPopFront(SLTNode** pphead);//ͷɾ
SLTNode* SListFind(SLTNode* phead, SLTDataType x);//����+�޸�
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);//��pos֮ǰ����
void SListErase(SLTNode** pphead, SLTNode* pos);//��posλ��ɾ��
void SListInsertAfter(SLTNode* pos, SLTDataType x);//��posλ��֮�����x
void SListEraseAfter(SLTNode* pos);//��posλ��֮��ɾ��x