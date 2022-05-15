#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev; //ǰ
	LTDataType data;
}LTNode;

/*void ListInit(LTNode** pphead);  */
LTNode* ListInit();  //��ʼ��

void ListPusahBack(LTNode* phead, LTDataType x); //β��
void ListPushFront(LTNode* phead, LTDataType x);//ͷ��
void ListPopFront(LTNode* phead);//ͷɾ
void ListPopBack(LTNode* phead);//βɾ
void ListPrint(LTNode* phead);//��ӡ
bool ListEmpty(LTNode* phead);
void ListInsert(LTNode* pos, LTDataType x);//��pos֮ǰ����x
void ListErase(LTNode* pos);//ɾ��pos�ڵ�