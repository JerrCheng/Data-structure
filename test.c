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



//ǰ�����
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


//�������
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



//�������
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



////������������1  ����
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



//������������2  ����
int TreeSize2(BTNode* root)
{
	return root == NULL ? 0 : TreeSize2(root->left) + TreeSize2(root->right) + 1;
}



//������Ҷ�ӽڵ�����
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


//k��ڵ����
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




//�����
int TreeDepth(BTNode* root)
{
	if (root == NULL)//��������0
	{
		return 0;
	}
	int Leftdepth = TreeDepth(root->left);//�����߸߶�
	int Rightdepth = TreeDepth(root->right);//����ұ߸߶�

	return Leftdepth > Rightdepth ? Leftdepth + 1 : Rightdepth + 1;//����ʱ����������
}



// ����������ֵΪx�Ľڵ�
BTNode* TreeFind(BTNode* root, BTDataType x)//���Ҷ�������ֵΪx�Ľڵ�
{
	if (root == NULL)//Ϊ�շ��ؿ�
	{
		return NULL;
	}

	if (root->data == x)//��Ⱦͷ��ؽڵ�
	{
		return root;
	}

	BTNode* RetLeft = TreeFind(root->left, x);//������ڵ�ֵ������ֱ�ӷ���
	if (RetLeft)
	{
		return RetLeft;
	}

	BTNode* RetRight = TreeFind(root->right, x);//�����ҽڵ�ֵ������ֱ�ӷ���
	if (RetRight)
	{
		return RetRight;
	}

	return NULL;//���Ҳ�������NULL
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

	//count = 0;   //ÿ�ε���ǰ���

	printf("TreeSize: %d\n", TreeSize2(root));


	printf("TreeLeafSize: %d\n", TreeLeafSize(root));


	printf("TreeKLevel: %d\n", TreeKLevel(root, 2));
	printf("TreeKLevel: %d\n", TreeKLevel(root, 3));
	printf("TreeKLevel: %d\n", TreeKLevel(root, 4));

	printf("TreeDepth: %d\n", TreeDepth(root));




	return 0;
}