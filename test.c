#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"
void TestSList1()
{
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n1);
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n2);
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n3);
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n4);
	SLTNode* n5 = (SLTNode*)malloc(sizeof(SLTNode));
	assert(n5);

	//n1->data = 1;
	//n2->data = 2;
	//n3->data = 3;
	//n4->data = 4;
	//n5->data = 5;
 //   
	//n1->next = n2;
	//n2->next = n3;
	//n3->next = n4;
	//n4->next = n5;
	//n5->next = NULL;
	SLTNode* plist = NULL;
	/*SListPushBack(&plist, 6);
	SListPushBack(&plist, 7);
	SListPushBack(&plist, 8);
	SListPrint(plist);*/
	SListPushFront(&plist, 0);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPrint(plist);
	SLTNode* ret = SListFind(plist, 3);
	if (ret)
	{
		printf("ур╣╫ак\n");
		ret->data = 30;
	}

	SListPrint(plist);