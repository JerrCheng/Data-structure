#include "Seqlist.h"
//void TestSeqList1()
//{
//	SL sl;
//	SLInt(&sl);
//	SLPushBack(&sl, 1);
//	SLPushBack(&sl, 2);
//	SLPushBack(&sl, 3);
//    SLPushBack(&sl, 4);
//	SLPushBack(&sl, 5);
//	SLPushBack(&sl, 6);
//	SLPushBack(&sl, 7);
//	SLPushBack(&sl, 8);
//	SLPrint(&sl);
//
//}
void TestSeqList2()
{
	SL sl;
	SLInt(&sl);

	SLPushFront(&sl, 1);
	SLPushFront(&sl, 2);
	SLPushFront(&sl, 3);
	SLPushFront(&sl, 4);
	SLPushFront(&sl, 5);
	SLPushFront(&sl, 6);
	SLPushFront(&sl, 7);
	SLPushFront(&sl, 8);
	SLPushFront(&sl, 9);
	SLPrint(&sl);

	int x = 0;
	printf("请输入你要删除的值：");
	scanf("%d", &x);
	int pos = SLFind(&sl, x);
	if (pos != -1)
	{
		SLErase(&sl, pos);
	}
	else
	{
		printf("没找到：%d\n",x);
	}
	SLPrint(&sl);


	int y, z;
     printf("请输入你要修改的值和修改后的值：");
	scanf("%d %d", &y,&z);
	 pos = SLFind(&sl, y);
	if (pos != -1)
	{
		SLModify(&sl, pos,z);
	}
	else
	{
		printf("没找到：%d\n",y);
	}
	SLPrint(&sl);

 


}

int main()
{
	TestSeqList2();
}