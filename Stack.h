#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;             //ջ��λ��,��ʾ�����һ�����ݵ���һ��λ��
	int capacity;
}ST;

void StackInit(ST* ps);              //��ʼ��
void StackDestory(ST* ps);            //����
void StackPush(ST* ps, STDataType x);  //��������
void StackPop(ST* ps);                //ɾ������
STDataType StackTop(ST* ps);         //ȡջ����Ԫ��
bool StackEmpty(ST* ps);            //�ж�ջ�Ƿ�Ϊ��
int StackSize(ST* ps);             //��ȡջ�ж�������