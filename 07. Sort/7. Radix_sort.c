// 기수 정렬(LSD)
#define BASE 10 // 한 자릿수에 가능한 값 개수(ex. 10진수: 0~9) 
#define DIGITS 5 // 최대 자릿수

void radix_sort(int list[], int n){
	int i;
	int base; // 진수 값
	int digit; // 자릿수
	int factor = 1; // 자릿수에 해당하는 자료의 숫자 구하기 위한 값
	
	// 자릿수 큐 배열 생성 및 초기화
	QueueType qd[BASE];
	for (base = 0; base < BASE; base++)
		init(&(qd[base]));
	
	
	for (digit = 0; digit < DIGITS; digit++){ // 최대 5자리에 대해
		// 1. 리스트에 있는 자료들 큐에 넣기
		for (i = 0; i < n; i++){ // 리스트에 있는 전체 원소에 대해 
			base = (list[i] / factor) % 10; // 자릿수에 해당하는 원소의 값
			enqueue(&(qd[base]), list[i]); // 큐 배열 내, 맞는 자릿수값 큐에 넣기 
		}
		
		// 2. 큐에 있는 자료들 다시 리스트에 자릿수 부분 정렬된 상태로 넣기
		for (base=i=0; base < BASE; base++)
			while (!is_empty(&(qd[base]))){ // 해당 자릿수값 큐가 다 빌 때까지 
				list[i] = dequeue(&(qd[base]));
				i++;
			}
		
		// 자릿수 up
		factor *= 10; 
	}
} 
 
