// 체인법

#define M 10
typedef struct element{
	int data;
	int key;
}element;
typedef struct ListNode{
	element item;
	struct ListNode *link;
}ListNode;

// 해시 테이블 헤드 포인터 배열
ListNode *htp[M];

void chain(element e, ListNode* hpt[]){
	int hb;
	ListNode *ptr; // 새 노드 생성할 때 쓸 포인터
	ListNode *lnode; // 새 노드 연결할 때 이용할 이전 노드 가리킬 포인터
	ListNode *node; // 연결 위치 찾을 때 사용할 포인터
	 
	// 1. 키값으로 해시값 생성
	hb = h(e.key);

	// 2. 넣을 곳 찾기(충돌 시 체인 연결할 맨 끝 위치 찾기)
	for(node = hpt[hb]; node; lnode=node, node=node->link){ //lnode에는 이전노드 저장, node는 null만날 때까지 감 
		// 체인 따라가다가 이미 있는 키값 만나면 삽입 종료
		if (node->item.key == e.key)
			return;
	}
	
	// 3. 새 노드 생성
	ptr = (ListNode*)malloc(sizeof(ListNode));
	ptr->item = e;
	ptr->link = NULL;
	
	// 4. 새 노드 연결하기
	if (lnode != NULL)
		lnode->link = ptr;
		
	else // 아직 아무것도 체이닝 안 된 상태였으면 
		htp[hb] = ptr; // 해시테이블 포인터 맨 처음 삽입 
}
