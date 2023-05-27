// 패트리샤 탐색 
typedef struct PatriciaNode{
	int bitNumber;
	int data;
	PatriciaNode *left, *right;
}PatriciaNode;

PatriciaNode *patricia_search(PatriciaNode *header, unsigned int k){
	PatriciaNode *next, *curr;
	if (!header) return NULL; // 빈 트리
	
	next = header->left;
	curr = header;
	
	// 다음 bitNumber가 현재 bitNumber보다 작거나 같아지면 탐색 종료 
	while (next->bitNumber > curr->bitNumber){
		curr = next;
		if (bit(k, next->bitNumber)) // k의 다음 bitNumber 위치에 해당하는 비트가 1이면
			next = next->right; // 오른쪽 자식으로 이동
		else
			next = next->left; 
	} 
	return next;	
}
