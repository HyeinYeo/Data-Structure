// �պ� ����
int list[10];
int temp[10];

// ���� & �պ� ���� �Լ�
void merge_sort(int list[], int temp[], int left, int right){ // left: �κи���Ʈ ���� ��, right: ������ �� 
	// 1. 1���� ���� ������ ��� �������� �ɰ���
	int mid = (left + right) / 2;
	if (left < right){ // left == right�� 1������ �ɰ��� ���� 
		merge_sort(list, temp, left, mid); // �ɰ� ���� �κ�
		merge_sort(list, temp, mid+1, right); // �ɰ� ������ �κ�
		
		// 2. �����ϸ鼭 ���ļ� �ö���� 
		merge(list, temp, left, mid, right);
		
		// 3. ��ġ�� (�κ�)����Ʈ temp�� �κ� ���ĵ� �ڷᰡ �����Ƿ� ���� ����Ʈ�� ����
		for (int i = left; i <= right; i++)
			list[i] = temp[i];
	}
	return; // 1������ �ɰ����ų�, �����ϸ� ����(���ư�) 
} 

void merge(int list[], int temp[], int left, int mid, int right){
	// ������ ������� �����ϸ鼭 merge 
	int i = left; // ���� �κи���Ʈ ������ 
	int j = mid + 1; // ������ �κи���Ʈ ������
	int k = left; // �ӽø���Ʈ�� �����ϱ� ���� �ε��� ���� 
	int t; // �ڷᰡ ���� �ִ� ����Ʈ�� ���� ���� ����ϴ� ���� 
	
	while (i <= mid && j <= right){
		if (list[i] < list[j]){ // ���� ����Ʈ �ڷᰡ ������ ����Ʈ �ڷẸ�� ���� ���
			temp[k] = list[i]; // �ӽ� ����Ʈ�� ���� �ڷ� �ֱ�
			i++;
			k++;
		}
		else{
			temp[k] = list[j];
			j++;
			k++;
		}
	}
	if (i > mid) // ���� ����Ʈ�� �� ����µ� ������ ����Ʈ���� �ڷ� ���� ���
		for (t = j; t <= right; t++){
			temp[k] = list[t];
			k++;	
		}
	else{ // ������ ����Ʈ�� �� ����µ� ���� ����Ʈ���� �ڷ� ���� ���
		for  (t = i; t <= mid; t++){
			temp[k] = list[t];
			k++;
		}
	}
}

// �պ��Լ� 2(��ȯ)
void iter_merge_sort(int list[], int n){
	// int temp[MAX_SIZE]; 
	int size = 1; // �κи���Ʈ ũ�� -> 2�辿 Ŀ���� �պ���
	
	while (size < n){ // 1���� �� �պ��� ������ 
		mergePass(list, temp, n, size); // list -> temp�� �����ؼ� ����
		size *= 2; // �κ� ����Ʈ ũ�� 2�辿
		mergePass(temp, list, n, size); // temp -> list�� �����ؼ� ����
		size *= 2; 
	}	
} 

void mergePass(int list[], int temp[], int n, int size){
	int i, j;
	// 1. list[n] �迭���� ���̰� size�� ������ �� ���� �κи���Ʈ�� �պ��Ͽ� temp�� ����
	for (i = 0; i + 2*size <= n; i += 2*size)
		merge(list, temp, i, i+size-1, i+2*size-1); // merge(list[], temp[], left, mid, right) 
	
	// 2. 2*size���� �ڷᰡ ���� ���� �ִ� �κ� ����Ʈ ���� 
	if (i+size < n)
		merge(list, temp, i, i+size-1, n-1);
	
	// 3. �ϳ��� �κ� ����Ʈ�� ������ ���
	else
		for (j = i; j < n; j++)
			temp[j] = list[j];
}











