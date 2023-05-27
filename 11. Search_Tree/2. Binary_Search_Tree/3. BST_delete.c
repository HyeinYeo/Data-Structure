// 이진탐색트리 삭제
/*
	1. 단말노드 삭제 ⇒ 그냥 삭제
	2. 자식 노드 1개 있는 경우 ⇒ 자식노드를 부모노드로 붙임
	3. 자식 노드 2개 있는 경우 ⇒ 오른쪽 자식노드의 가장 왼쪽 노드를 후계자로 선정함
*/

typedef struct BSTNode{
	int key;
	int value;
	struct BSTNode *left, *right;
}BSTNode;

void delete_bst(BSTNode **root, int key){
	BSTNode *parent = NULL; // 삭제할 노드의 부모노드
	BSTNode *child; // 삭제할 노드의 자식노드(case 2), 후계자 노드의 오른쪽 자식노드(case 3)
	BSTNode *target = *root; // 삭제할 노드 
	
	// 0. 삭제노드 탐색 -> 탐색 실패하면 트리에 삭제할 노드 없음
	while (target != NULL && target->key != key){
		parent = target;
		if (key < target->key) target = target->left;
		else target = target->right;
	}
	if (target == NULL) return; // 탐색 실패한 경우 종료
	
	// 1. 단말노드 삭제
	if (target->left == NULL && target->right == NULL){
		if (parent != NULL){ // 루트 삭제가 아닌 경우 
			if (parent->left == target) // 삭제 노드가 부모노드의 왼쪽 자식이면
				parent->left = NULL;
			else // 삭제 노드가 부모노드의 오른쪽 자식이면
				parent->right = NULL;
		}
		else // 루트 삭제인 경우 => 공백트리 됨
			*root = NULL; 
	}
	
	// 2. 자식 노드 1개 있는 경우
	else if (target->left == NULL || target->right == NULL){
		if (target->left != NULL) // 자식 노드가 왼쪽 자식인 경우
			child = target->left;
		else // 자식 노드가 오른쪽 자식인 경우
			child = target->right;
		
		// 자식 노드를 부모노드에 연결
		if (parent != NULL){
			if (parent->left == target)
				parent->left = child;
			else
				parent->right = child; 
		}
		else // 루트 삭제인 경우 => child가 루트가 됨 
			*root = child;
	}
	
	// 3. 자식 노드 2개 있는 경우
	else{
		// 1) 후계자 선정: 삭제노드의 오른쪽 자식노드의 가장 왼쪽 노드
		parent = target; // 나중에 후계자의 오른쪽 서브트리를 붙이기 위한 후계자의 부모 
		child = target->right; // 삭제노드의 오른쪽 자식노드
		while (child->left != NULL){ // 가장 왼쪽 노드(=후계자) 찾을 때까지 
			parent = child;
			child = child->left;
		}
		
		// 2) 후계자의 자식 노드를 후계자의 부모 노드의 자식노드로 편입 
		if (parent->left == child) // 후계자가 부모의 왼쪽 자식노드인 경우 
			parent->left = child->right; // 후계자의 오른쪽 서브트리를 갖다 붙임
		else // 후계자가 부모의 오른쪽 자식노드인 경우
			parent->right = child->right;
		
		// 3) 삭제 노드를 후계자로 교체 
		target->key = child->key;
		target = child; 
	}
	free(target); // 삭제 
}
 
