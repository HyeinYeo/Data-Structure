// 순회
typedef struct TreeNode{
	int data;
	struct TreeNode *left, *right;
}TreeNode;

// 1. 전위순회
void preorder(TreeNode *root){
	if (root){ // 존재하는 트리면 
		printf("%d", root->data);
		preorder(root->left);
		preorder(root->right); 
	}
}

// 2. 중위순회
void inorder(TreeNode *root){
	if (root){
		inorder(root->left);
		printf("%d", root->data);
		inorder(root->right);
	}
}

// 3. 후위순회
void postorder(TreeNode *root){
	if (root){
		postorder(root->left);
		postorder(root->right);
		printf("%d", root->data);
	}
}

// 4. 레벨순회
//  - 큐를 이용! 
void level_order(TreeNode *ptr){
	QueueType q;
	init(&q);
	if (!ptr) return; // 없는 트리면 끝냄
	
	enqueue(&q, ptr);
	while (!is_empty(&q)){
		ptr = dequeue(&q);
		printf("%d", ptr->data);
		if (ptr->left) enqueue(&q, ptr->left); // 왼쪽 자식 존재하면 큐에 삽입
		if (ptr->right) enqueue(&q, ptr->right); 
	} 
	
} 
