int TreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)//不为空，一直进数据
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else//为空就停止。
		{
			break;
		}
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front)//如果非空
		{
			QueueDestroy(&q);//销毁队列
			return false;//返回假
		}
	}

	QueueDestroy(&q);
	return true;//返回之前销毁队列。
}