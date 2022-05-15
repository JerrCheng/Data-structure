#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void TestList1()
{
	LTNode* plist = ListInit();
	ListPusahBack(plist, 1);
	ListPusahBack(plist, 2);
	ListPusahBack(plist, 3);
	ListPusahBack(plist, 4);
	ListPusahBack(plist, 5);

	ListPrint(plist);


}

int main()
{
	TestList1();
	return 0;
}

