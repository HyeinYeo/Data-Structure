// �� ����
/*
	gap = (���� �ڷ� ����) / 2
		- ��, gap�� ¦���� ��� +1(Ȧ��ȭ) 
	�κ� ����Ʈ�� ���� ���� ����(�� ��°���� �����ؼ� �հ� ��) 
*/

const int n = 30;
int list[n];

void insertion_sort(int list[], int start, int n, int gap){
	int i, j, key;
	
	for (i = start+gap; i < n; i+=gap){
		key = list[i];
		for (j = i-gap; j >= start && list[j] > key; j-=gap)
			list[j+gap] = list[j];
		if ((j+gap) != i)
			list[j+gap] = key;
	}
}

void shell_sort(int list[], const int n){
	int i, gap;
	
	for (gap = n/2; gap > 0; gap /= 2){
		// gap�� ¦���� ��� +1(Ȧ��ȭ)
		if (gap % 2 == 0) gap++
		
		// �� �κи���Ʈ�� ���� ���� ����(�κи���Ʈ ���� == gap) 
		for (i = 0; i < gap; i++)
			insertion_sort(list, i, n, gap);
	}
} 
