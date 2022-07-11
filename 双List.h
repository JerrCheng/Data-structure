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



//void LTInit(LTNode** pphead);                    //��ʼ���ö���ָ��

LTNode* LTInit();                                   //��ʼ������ַ

LTNode* BuyListNode(LTDataType x);                 //�����½ڵ�

void LTPrint(LTNode* phead);                        //��ӡ

void LTPushBack(LTNode* phead, LTDataType x);       //β��

void LTPushFront(LTNode* phead, LTDataType x);      //ͷ��

void LTPopBack(LTNode* phead);                      //βɾ

void LTPopFront(LTNode* phead);                      //ͷɾ

bool LTEmpty(LTNode* phead);                        //�п�

void LTInsert(LTNode* pos, LTDataType x);         //��pos֮ǰ����

void LTErase(LTNode* pos);                        //��posλ��ɾ��
