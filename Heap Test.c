#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//////升序打印——小堆
////void Test1()
////{
////	HP hp;
////	HeapInit(&hp);
////	int a[] = { 27, 45, 86, 32, 16, 84, 63, 70, 55, 12 };
////	for (int i = 0; i < sizeof(a) / sizeof(int); ++i)
////	{
////		HeapPush(&hp, a[i]);
////	}
////
////	while(!HeapEmpty(&hp))
////	{
////		printf("%d ", HeapTop(&hp));
////		HeapPop(&hp);
////	}
////
////	printf("\n");
////}
//
//堆排序
//升序——建大堆
//降序——建小堆
void HeapSort(int* a, int n)
{
	////建堆 1
	//for (int i = 0; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}

	//建堆 2
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)            //i是倒数第一个非叶子节点，-1求下标，再-1求父亲
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end > 0)
	{
		//将最大的放到最下面，然后将他排除堆外，循环
		HeapSwap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		printf("%d ", a[end]);
		end--;

	}
}


int main()
{
	int i = 0;
	int a[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
	int size = sizeof(a) / sizeof(int);


	HeapSort(a, size);
	return 0;
}


