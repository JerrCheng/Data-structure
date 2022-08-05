#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>


typedef int BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
	BTDataType data;
}BTNode;



BTNode* BuyNode(BTDataType* x)
{
	BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
	assert(NewNode);
	NewNode->data = x;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

BTNode* CreatBinaryTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	return node1;
}



//前序遍历
void PreoOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreoOrder(root->left);
	PreoOrder(root->right);
}


//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}



//后序遍历
void Postorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}



////二叉树的数量1  遍历
//int count = 0;
//void TreeSize1(BTNode* root)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	count++;
//	TreeSize1(root->left);
//	TreeSize1(root->right);
//
//}



//二叉树的数量2  分治
int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}



//二叉树叶子节点数量
int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);

}


//k层节点个数
int TreeKLevel(BTNode* root, int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		return 0;
	}

	if (k == 1)
	{
		return 1;
	}

	return TreeKLevel(root->left, k - 1) + TreeKLevel(root->right, k - 1);
}




//求深度
int TreeDepth(BTNode* root)
{
	if (root == NULL)//空树返回0
	{
		return 0;
	}
	int Leftdepth = TreeDepth(root->left);//求出左边高度
	int Rightdepth = TreeDepth(root->right);//求出右边高度

	return Leftdepth > Rightdepth ? Leftdepth + 1 : Rightdepth + 1;//返回时加上自身返回
}



// 二叉树查找值为x的节点
BTNode* TreeFind(BTNode* root, BTDataType x)//查找二叉树中值为x的节点
{
	if (root == NULL)//为空返回空
	{
		return NULL;
	}

	if (root->data == x)//相等就返回节点
	{
		return root;
	}

	BTNode* RetLeft = TreeFind(root->left, x);//保存左节点值，方便直接返回
	if (RetLeft)
	{
		return RetLeft;
	}

	BTNode* RetRight = TreeFind(root->right, x);//保存右节点值，方便直接返回
	if (RetRight)
	{
		return RetRight;
	}

	return NULL;//都找不到返回NULL
}





int main()
{
	BTNode* root = CreatBinaryTree();

	PreoOrder(root);
	printf("\n");

	InOrder(root);
	printf("\n");

	Postorder(root);
	printf("\n");

	//count = 0;   //每次调用前清空

	printf("TreeSize: %d\n", TreeSize2(root));


	printf("TreeLeafSize: %d\n", TreeLeafSize(root));


	printf("TreeKLevel: %d\n", TreeKLevel(root, 2));
	printf("TreeKLevel: %d\n", TreeKLevel(root, 3));
	printf("TreeKLevel: %d\n", TreeKLevel(root, 4));

	printf("TreeDepth: %d\n", TreeDepth(root));




	return 0;
}