void PrintTopK(int* a, int n, int k)
{
	// 1. 建堆--用a中前k个元素建堆
	int* KMinHeap = (int*)malloc(sizeof(int) * k);
	assert(KMinHeap);
	for (int i = 0; i < k; i++)
	{
		KMinHeap[i] = a[i];
	}

	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDwon(KMinHeap, k, i);
	}

	// 2. 将剩余n-k个元素依次与堆顶元素交换，不满则则替换
	for (int j = k; j < n; j++)
	{
		if (a[j] > KMinHeap[0])
		{
			KMinHeap[0] = a[j];
			AdjustDwon(KMinHeap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", KMinHeap[i]);
	}

	printf("\n");

}
void TestTopk()
{
	int n = 10000;
	int* a = (int*)malloc(sizeof(int) * n);
	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a[i] = rand() % 10000;
	}
	a[6] = 10000 + 1;
	a[12] = 10000 + 2;
	a[645] = 10000 + 3;
	a[3333] = 10000 + 4;
	a[1222] = 10000 + 5;
	a[459] = 10000 + 6;
	a[9999] = 10000 + 7;
	a[8778] = 10000 + 8;
	a[5897] = 10000 + 9;
	a[44] = 10000 + 10;
	PrintTopK(a, n, 10);
}