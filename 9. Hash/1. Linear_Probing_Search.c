// 선형조사법
#define M 50 // 버킷당 슬롯 수는 1개라고 가정(1차원 배열)

int HashTable[M];

int LinearProbingSearch(int key){
	int hash_idx; // key에 대한 초기 해시테이블 인덱스(초기 해시함수값)
	int real_idx; // 충돌해결한 뒤의 실제 해시테이블 인덱스
	
	hash_idx = h(key);
	// 해당 인덱스의 버킷 찾아갔더니, 이미 다른 키 값 가진 데이터가 존재하면 for문 계속 실행 
	for (real_idx = hash_idx; HashTable[real_idx] && HashTable[real_idx].key != key;){
		real_idx = (real_idx + 1) % M; // 선형적으로 증가시킴 1->2->3->...
		
		if (real_idx == hash_idx) // 돌고 돌아 다시 원점 오면, 버킷이 이미 다 꽉 찬 상태(없어서 못 찾음) 
			return -1; 
	}
	if (HashTable[real_idx].key == key) // 탐색 성공 
		return real_idx;
	
	return -1; // 탐색 실패 
} 
