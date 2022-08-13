void LevelOrder(BTNode *root)
{
	Queue q;//创建队列
	QueueInit(&q);//初始化队列
	
	if (root)//如果根节点不为空
	{
		QueuePush(&q, root);//根节点放入队列
	}
 
	while (!QueueEmpty(&q))//如果队列不为空
	{
		BTNode* front = QueueFront(&q);//保存节点值
		printf("%c ", front->data);//打印
		QueuePop(&q);//出队列
 
		if (front->left)//如果不为空，左节点放入队列
		{
			QueuePush(&q, front->left);
		}
 
		if (front->right)//如果不为空，左节点放入队列
		{
			QueuePush(&q, front->right);
		}
 
	}
	printf("\n");
	QueueDestroy(&q);//销毁队列
}