#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"


void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}


void HeapPrint(HP* php)
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			HeapSwap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}



void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		int newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}

		php->a = tmp;
		php->capacity = newcapacity;
	}


	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size - 1);
}


void AdjustDown(HPDataType* a, int size, int parent)
{
	//左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		//比较左右孩子的大小
		if (child + 1 < size && a[child + 1] < a[child])
		{
			child++;
		}

		//父亲和小的孩子进行比较，并向下调整
		if (a[child] < a[parent])
		{
			HeapSwap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}



//删除
void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);
	HeapSwap(&(php->a[0]), &(php->a[php->size - 1]));
	php->size--;
	AdjustDown(php->a, php->size, 0);
}


HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->a);

	return php->a[0];
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}



int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}



void HeapDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = 0;
	php->capacity = php->size = 0;
}



void HeapSwap(HPDataType* n1, HPDataType* n2)
{
	HPDataType* tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}
