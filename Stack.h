#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;             //栈顶位置,表示着最后一个数据的下一个位置
	int capacity;
}ST;

void StackInit(ST* ps);              //初始化
void StackDestory(ST* ps);            //销毁
void StackPush(ST* ps, STDataType x);  //插入数据
void StackPop(ST* ps);                //删除数据
STDataType StackTop(ST* ps);         //取栈顶的元素
bool StackEmpty(ST* ps);            //判断栈是否为空
int StackSize(ST* ps);             //获取栈有多少数据