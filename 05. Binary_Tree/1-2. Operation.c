// 이진트리 연산

// 1. 노드 수 구하기
//    - 왼쪽 서브트리의 노드 수 + 오른쪽 서브트리의 노드 수 => 재귀적으로
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

// 2. 단말노드 수 구하기
//    - n0 = n2 + 1   => 자식노드 2개 가진 노드 수에 1 더하면 됨
//    - 왼쪽 자식, 오른쪽 자식 모두 null인 경우에 카운트 하면 됨 
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

// 3. 높이 구하기
//    - 왼쪽 서브트리와 오른쪽 서브트리 중 높은 쪽에다가 +1(본인 레벨)
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
