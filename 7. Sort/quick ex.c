# include <stdio.h>
# define MAX_SIZE 12
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

// 1. �ǹ��� �������� 2���� �κ� ����Ʈ�� ������.
// 2. �ǹ����� ���� ���� ��� ���� �κ� ����Ʈ��, ū ���� ������ �κ� ����Ʈ�� �ű��.
/* 2���� ��յ� �迭 list[left...pivot-1]�� list[pivot+1...right]�� �պ� ���� */
/* (������ ���ڵ��� ���ĵǴ� ����) */

/*
int find_median(int list[], int left, int right){
	int temp;
	int mid = (left + right) / 2;
	int a = list[left], b = list[mid], c = list[right];
	if (((a >= b) && (b >= c)) || ((a <= b) && (b <= c)))
		SWAP(list[left], list[mid], temp);
	else if (((a >= c) && (c >= b)) || ((a <= c) && (c <= b)))
		SWAP(list[left], list[right], temp);
	
	return list[left];
}
*/

int partition(int list[], int left, int right){
  int p;
  int pivot, temp;
  int low, high;

  low = left;
  high = right + 1;
  
  //pivot = find_median(list, left, right); // ������ ����Ʈ�� ���� ���� �����͸� �ǹ����� ����(������ ���� �ǹ����� ����)
  pivot = list[left];
  printf("pivot: %d\t", list[left]);
  /* low�� high�� ������ ������ �ݺ�(low<high) */
  do{
    /* list[low]�� �ǹ����� ������ ��� low�� ���� */
    do {
      low++; // low�� left+1 ���� ����
    } while (low<=right && list[low]<pivot);

    /* list[high]�� �ǹ����� ũ�� ��� high�� ���� */
    do {
      high--; //high�� right ���� ����
    } while (high>=left && list[high]>pivot);

    // ���� low�� high�� �������� �ʾ����� list[low]�� list[high] ��ȯ
    if(low<high){
      SWAP(list[low], list[high], temp);
    }
  } while (low<high);

  // low�� high�� ���������� �ݺ����� �������� list[left]�� list[high]�� ��ȯ
  SWAP(list[left], list[high], temp);

  // �ǹ��� ��ġ�� high�� ��ȯ
  return high;
}

// �� ����
void quick_sort(int list[], int left, int right){
	int i;
  /* ������ ������ 2�� �̻��� �������̸�(����Ʈ�� ũ�Ⱑ 0�̳� 1�� �ƴϸ�) */
  if(left<right){
    // partition �Լ��� ȣ���Ͽ� �ǹ��� �������� ����Ʈ�� ��յ� ���� -����(Divide)
    int q = partition(list, left, right); // q: �ǹ��� ��ġ
    printf("�κ� ����: ");
	for (i = 0; i < MAX_SIZE; i++)
		printf("%d ", list[i]);
	printf("\n"); 
    // �ǹ��� ������ 2���� �κ� ����Ʈ�� ������� ��ȯ ȣ��
    quick_sort(list, left, q-1); // (left ~ �ǹ� �ٷ� ��) ���� �κ� ����Ʈ ���� -����(Conquer)
    quick_sort(list, q+1, right); // (�ǹ� �ٷ� �� ~ right) ���� �κ� ����Ʈ ���� -����(Conquer)
  }

}

void main(){
  int i;
  int n = MAX_SIZE;
  int list[MAX_SIZE] = {6, 2, 12, 11, 10, 3, 5, 4, 8, 1, 9, 7}; // 4, 2, 7, 3, 8, 0, 5, 1, 6

  // �� ���� ����(left: �迭�� ���� = 0, right: �迭�� �� = 8)
  quick_sort(list, 0, n-1);

  // ���� ��� ���
  for(i=0; i<n; i++){
    printf("%d\n", list[i]);
  }
}
