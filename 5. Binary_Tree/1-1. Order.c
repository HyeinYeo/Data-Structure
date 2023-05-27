// ��ȸ
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

// 1. ������ȸ
void preorder(TreeNode *root){
	if (root){ // �����ϴ� Ʈ���� 
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right); 
	}
}

// 2. ������ȸ
void inorder(TreeNode *root){
	if (root){
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

// 3. ������ȸ
void postorder(TreeNode *root){
	if (root){
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}

// 4. ������ȸ
//  - ť�� �̿�! 
void level_order(TreeNode *ptr){
	QueueType q;
	init(&q);
	if (!ptr) return; // ���� Ʈ���� ����
	
	enqueue(&q, ptr);
	while (!is_empty(&q)){
		ptr = dequeue(&q);
		printf("%d", ptr->data);
		if (ptr->left) enqueue(&q, ptr->left); // ���� �ڽ� �����ϸ� ť�� ����
		if (ptr->right) enqueue(&q, ptr->right); 
	} 
	
} 
