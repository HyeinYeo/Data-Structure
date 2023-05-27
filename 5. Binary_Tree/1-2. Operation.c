// ����Ʈ�� ����

// 1. ��� �� ���ϱ�
//    - ���� ����Ʈ���� ��� �� + ������ ����Ʈ���� ��� �� => ���������
int get_node_num(TreeNode *node){
	int count = 0;
	if (node)
		count = 1 + get_node_num(node->left) + get_node_num(node->right);
	return count;
}

int get_node_num(TreeNode *node){
	if (!node) return 0;
	else return 1 + get_node_num(node->left) + get_node_num(node-right);
}

// 2. �ܸ���� �� ���ϱ�
//    - n0 = n2 + 1   => �ڽĳ�� 2�� ���� ��� ���� 1 ���ϸ� ��
//    - ���� �ڽ�, ������ �ڽ� ��� null�� ��쿡 ī��Ʈ �ϸ� �� 
int get_leaf_node(TreeNode *node){
	int count = 0;
	if (node){
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_node(node->left) + get_leaf_node(node->right);
	}
	return count;
}

int get_leaf_node(TreeNode *node){
	if (!node) return 0;
	else if (node->left == NULL && node->right == NULL) return 1;
	else
		return get_leaf_node(node->left) + get_leaf_node(node->right);
} 

// 3. ���� ���ϱ�
//    - ���� ����Ʈ���� ������ ����Ʈ�� �� ���� �ʿ��ٰ� +1(���� ����)
int get_height(TreeNode *node){
	int height = 0;
	if (node)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
} 

int get_height(TreeNode *node){
	if (!node) return 0;
	else return 1 + max(get_height(node->left), get_height(node->right));
}
