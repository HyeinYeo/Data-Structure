// 버블 정렬 => 인접자료 교환, 뒤에서부터 정렬
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))
const int n = 30;
int list[n];

void bubble_sort(int list, const int n){
	int i, j, temp;
	
	for (i = n-1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (list[j] > list[j+1])
				SWAP(list[j], list[j+1], temp);
} 
