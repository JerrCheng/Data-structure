#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;

 typedef struct SeqList
{
	SLDataType *a;
	int size;
	int capacity;  //空间容量大小
}SL;

 //增删查改
void SLInt(SL *ps);

//头插/头删/尾插/尾删
void SLPushBack(SL* ps, SLDataType x);
void SLPopBack(SL* ps);
void SLPushFront(SL* ps, SLDataType x);
void SLPopFront(SL* ps);

//在任意位置插入/删除
void SLInsert(SL* ps, int pos, SLDataType x);
void SLErase(SL* ps, int pos);

//查找 / 修改
int SLFind(SL* ps, SLDataType x);
int SLModify(SL* ps, int pos, SLDataType x);