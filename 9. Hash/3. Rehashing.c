// 재해싱

#define M 50 // 버킷당 슬롯 수는 1개라고 가정(1차원 배열)

int HashTable[M];
typedef struct element{
	int data;
	int key;
}element;

// 해시테이블에 데이터 넣는 함수
void Rehashing(element e){
	int hb, cb, rb, i;
	hb = h(e.key); // 주해시함수(h)로 계산한 최초의 해시값
	rb = rh(e.key); // 부해시함수(rh)로 계산한 값(충돌 시 더해줄 것)
	i = rb;
	
	for (cb = hb; HashTable[cb] && HashTable[cb].key != e.key; ){
		cb = (cb + i) % M; // rb += 1;
		if (cb == hb) return;
	}
	if (!HashTable[cb])
		HashTable[cb] = e;
} 
