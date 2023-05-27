// �� ����
#define SWAP(x, y, z) ((temp)=(x), (x)=(y), (y)=(temp))

void quick_sort(int list[], int left, int right){
	if (left < right){ // left == right�� ���Ұ� �ϳ��̹Ƿ� ����, ���� �ʿ� X 
		int pivot = partition(list, left, right);
		quick_sort(list, left, pivot-1); // �ǹ� ���� �κ� ����Ʈ�� ���� �ٽ� �� ����
		quick_sort(list, pivot+1, right); // �ǹ� ������ �κ� ����Ʈ�� ���� �ٽ� �� �� 
	}
	return; 
}

int partition(int list[], int left, int right){ // �ǹ� �ε��� ��ȯ�ϴ� �Լ�
	int pivot_value = list[left]; // ���� ���ʰ��� �ǹ����� ����
	int start = left;
	int end = right + 1; // do-while ���� ���� start, end ������ ���� ��ġ ������ ���
	int temp;
	// start �����Ϳ� end �����Ͱ� ��ġ�ų� �����ϱ� ������ 
	do{
		// start �����ʹ� �ǹ����� ���� ���� �����ϰ� ���������� ��� �̵� 
		do {start++;} while (list[start] < pivot_value && start <= right);
		
		// end �����ʹ� �ǹ����� ū ���� �����ϰ� �������� ��� �̵�
		do { end--; } while (list[end] > pivot_value && end >= left); 
		
		// start, end ������ ��� ������ ��, �� �� ��ȯ
		if (start < end)
			SWAP(list[start], list[end], temp); 
	} while (start < end);
	
	// ������ ���� end ������ ��ġ�� �ǹ� ���� ��ġ
	SWAP(list[left], list[end], temp);
	
	// end ������ ��ġ�� �ǹ��� �ε����̹Ƿ� ����
	return end; 
}
