#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev; //前
	LTDataType data;
}LTNode;

/*void ListInit(LTNode** pphead);  */
LTNode* ListInit();  //初始化

void ListPusahBack(LTNode* phead, LTDataType x); //尾插
void ListPushFront(LTNode* phead, LTDataType x);//头插
void ListPopFront(LTNode* phead);//头删
void ListPopBack(LTNode* phead);//尾删
void ListPrint(LTNode* phead);//打印
bool ListEmpty(LTNode* phead);
void ListInsert(LTNode* pos, LTDataType x);//在pos之前插入x
void ListErase(LTNode* pos);//删除pos节点