// ���� ���� => �� ��°���� ����, �� �ڷ��� ��, ���������� �б�
const int n = 30;
int list[n];

void insertion_sort(int list[], const int n){
	int i, j, key; 
	
	for (i = 1; i < n; i++){
		key = list[i];
		for (j = i-1; j >= 0 && list[j] > key; j--) // �� �ڷᰡ Ű���� �۾��� ����, �� �ڷ� �ٷ� ���� ������ Ű ���� 
			list[j+1] = list[j];

		if ((j+1)!= i)
			list[j+1] = key; 
	}
} 
