// 다원 트라이 탐색
#define MAX 27 // 알파벳 개수 + 종료문자 개수 
typedef struct trieNode{
	int tag; // 1이면 데이터 노드, 0이면 내부(분기)노드 
	struct trieNode *child[MAX]; 
	char *key;
}trieNode; 

trieNode *trie_search(trieNode *node, char *key, int level){ // level: 트라이 레벨
	if (!node) return NULL; // 공백 트라이
	
	// 데이터(단말) 노드에 도착한 경우 -> 키 비교
	if (node->tag == 1){
		if (node->key == key) // 탐색 성공
			return node;
		else
			return NULL; // 탐색 실패 
	} 
	
	// 아직 분기노드일 경우
	/*
		- node->child[getIndex(key, level)]
			- 해당 알파벳의 다음 노드로 이동
			- getIndex(key, level): 현재 레벨에서의 키(level번째 알파벳)의 인덱스
		- level + 1
			- 다음 레벨로 이동(다음 순서 알파벳) 
	*/
	// 
	return trie_search(node->child[getIndex(key, level)], key, level+1); 
}
