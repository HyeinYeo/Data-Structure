// ���� ���� => ó�� ����, ���� ���� ���� ��ȯ
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))
const int n = 30;
int list[n];

void selection_sort(int list[], const int n){
	int i, j, k, temp; // k�� ���� ���� �ڷ� �ε��� ��� ���� 
	
	for (i = 0; i < n-1; i++){
		k = i // ����� �����ϴ� �ڷᰡ ���� �۴ٰ� ���� 
		for (j = i+1; j < n; j++)
			if (list[j] < list[k])
				k = j;
		if (k != i) // ������ �ڷᰡ ���� ���� ��찡 �ƴϸ� 
			SWAP(list[i], list[k], temp); // ��ȯ 
	}
}

