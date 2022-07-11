#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int LTDataType;
typedef struct ListNode
{
	struct ListNode* prev;
	struct ListNode* next;
	LTDataType data;

}LTNode;



//void LTInit(LTNode** pphead);                    //初始化用二级指针

LTNode* LTInit();                                   //初始化传地址

LTNode* BuyListNode(LTDataType x);                 //创建新节点

void LTPrint(LTNode* phead);                        //打印

void LTPushBack(LTNode* phead, LTDataType x);       //尾插

void LTPushFront(LTNode* phead, LTDataType x);      //头插

void LTPopBack(LTNode* phead);                      //尾删

void LTPopFront(LTNode* phead);                      //头删

bool LTEmpty(LTNode* phead);                        //判空

void LTInsert(LTNode* pos, LTDataType x);         //在pos之前插入

void LTErase(LTNode* pos);                        //在pos位置删除
