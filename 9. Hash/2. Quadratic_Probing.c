// 이차조사법
#define M 50 // 버킷당 슬롯 수는 1개라고 가정(1차원 배열)

int HashTable[M];
typedef struct element{
	int data;
	int key;
}element;

// 해시테이블에 데이터 넣는 함수
void QuadProbingHashing(element e){ // e => data, key로 이루어져 있음 
	int hb, cb, i = 1;
	
	// 1. 최초의 해시함수 계산
	hb = h(e.key);
	
	// 2. 충돌 발생 검사 -> 충돌 해결: 빈 버킷 찾기
	for (cb = hb; HashTable[cb] && HashTable[cb].key != e.key;){
		// 충돌 해결(이차조사법)
		cb = (cb + i) % M;
		i += 2;
		/*
		cb = (hb + i*i) % M;
		i++;
		*/
		// 버킷 꽉 찼는지 검사
		if (cb == hb) return; 
	} 
	if(!HashTable[cb]) // 빈 해시테이블이면, 데이터 삽입
		HashTable[cb] = e; 
} 
