// 스레드 이진트리 선행자 / 후속자 찾기
typedef struct TNode{
	int data;
	struct TNode *left, *right;
	short left_thread, right_thread; // True라면 선행자/후속자 가리키고 있음 
}TNode;

// 1. 중위 선행자 찾기: 왼쪽 자식 서브트리의 가장 오른쪽 노드 
TNode *find_predecessor(TNode *node){
	TNode *prec = node->left;
	
	if (node->left_thread)
		return prec;
	
	while (!(prec->right_thread))
		prec = prec->right;
	return prec; 
}

// 2. 중위 후속자 찾기: 오른쪽 자식 서브트리의 가장 왼쪽 노드 
//    - 중위순회 시, 이 노드 다음에 올 노드가 무엇인지? 
TNode *find_successor(TNode *node){
	// 1) 오른쪽 자식 조사
	TNode *succ = node->right;
	
	// 2) 오른쪽 자식이 스레드 링크라면 
	//    => 오른쪽 링크가 가리키는 노드가 중위 후속자 노드
	if (node->right_thread)
		return succ;
	
	// 3) 오른쪽 자식이 스레드 링크 아니라면
	//    => 오른쪽 자식의 가장 왼쪽 리프 노드 찾을 때까지 내려가기
	//    => 가장 왼쪽 리프노드는 왼쪽 링크가 스레드 링크! 
	while (!(succ->left_thread))
		succ = succ->left;
	return succ;
}

