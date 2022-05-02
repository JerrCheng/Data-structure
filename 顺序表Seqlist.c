#define _CRT_SECURE_NO_WARNINGS 1
#include "Seqlist.h"
void SLPrint(SL* ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d", ps->a[i]);
	}
	printf("\n");
}
//��ʼ��
void SLInt(SL* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SLCheckCapacity(SL* ps)
{
	assert(ps);

	//���ռ���������������
	if (ps->size == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;

	}
}
//β��
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);
	ps->a[ps->size] = x;
	ps->size++;
}

//ͷ��
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);

	SLCheckCapacity(ps);

	//Ų������
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[0] = x;
	ps->size++;
}
//βɾ
void SLPopBack(SL* ps)
{
	SLCheckCapacity(ps);

	assert(ps);

	assert(ps->size > 0);
	ps->size--;
}

//ͷɾ
void SLPopFront(SL* ps)
{
	SLCheckCapacity(ps);

	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	ps->size--;
}

//����λ�ò���
void SLInsert(SL* ps, int pos, SLDataType x)
{

	SLCheckCapacity(ps);
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	ps->a[pos] = x;
	ps->size++;
}

//������λ��ɾ��

void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size - 1);
	int begin = pos;
	while (begin < ps->size - 1)
	{
		ps->a[begin] = ps->a[begin + 1];
		++begin;
	}
	ps->size--;
}


//����
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
			return i;
	}

	return -1;

}

//�޸�
int SLModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);
	ps->a[pos] = x;
}