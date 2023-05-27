// ����Ž�� O(n)

#define MAX 50
int list[MAX];

// 1. �տ������� ���ʷ� ��
int seq_search1(int key, int low, int high){
	int i;
	
	for (i = low; i <= high; i++)
		if (list[i] == key)
			return i;
			
	return -1; // Ž�� ���� 
}
        
// 2. �迭 ���� ������ ��, �տ������� ã��
int seq_search2(int key, int low, int high){
	int i;
	list[high+1] = key;
	for(i = low; list[i]!=key; i++);
	if (i == (high+1)) return -1; // ������ ���� Ž�� ����
	return i; 
}
        
// 3. ���ĵ� �迭�� ����
int sorted_seq_search3(int key, int low, int high){
	int i;
	for (i = low; i <= high; i++){
		if (list[i] > key) return -1; // Ž�� ����
		if (list[i] == key) return i; 
	}
}
