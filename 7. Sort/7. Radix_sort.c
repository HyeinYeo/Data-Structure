// ��� ����(LSD)
#define BASE 10 // �� �ڸ����� ������ �� ����(ex. 10����: 0~9) 
#define DIGITS 5 // �ִ� �ڸ���

void radix_sort(int list[], int n){
	int i;
	int base; // ���� ��
	int digit; // �ڸ���
	int factor = 1; // �ڸ����� �ش��ϴ� �ڷ��� ���� ���ϱ� ���� ��
	
	// �ڸ��� ť �迭 ���� �� �ʱ�ȭ
	QueueType qd[BASE];
	for (base = 0; base < BASE; base++)
		init(&(qd[base]));
	
	
	for (digit = 0; digit < DIGITS; digit++){ // �ִ� 5�ڸ��� ����
		// 1. ����Ʈ�� �ִ� �ڷ�� ť�� �ֱ�
		for (i = 0; i < n; i++){ // ����Ʈ�� �ִ� ��ü ���ҿ� ���� 
			base = (list[i] / factor) % 10; // �ڸ����� �ش��ϴ� ������ ��
			enqueue(&(qd[base]), list[i]); // ť �迭 ��, �´� �ڸ����� ť�� �ֱ� 
		}
		
		// 2. ť�� �ִ� �ڷ�� �ٽ� ����Ʈ�� �ڸ��� �κ� ���ĵ� ���·� �ֱ�
		for (base=i=0; base < BASE; base++)
			while (!is_empty(&(qd[base]))){ // �ش� �ڸ����� ť�� �� �� ������ 
				list[i] = dequeue(&(qd[base]));
				i++;
			}
		
		// �ڸ��� up
		factor *= 10; 
	}
} 
 
