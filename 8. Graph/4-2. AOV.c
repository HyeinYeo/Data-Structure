// AOV
/* 
	- indeg �迭 => ����������� count�ʵ�
	- ���� �ڷᱸ�� ���� �����ϴ� �������� 
*/
void aov(hnodes glist[] int n){
	int i, j, k;
	int x; // ���ÿ��� pop�ؼ� ����� ���� �� ��� ����
	GraphNode *ptr; // ���� ���� �� count(����������) �����ϱ� ����
	
	// 1. ����: �������� 0�� �� ���ÿ� �ֱ�
	for (i = 0; i < n; i++)
		if (glist[i].count == 0){
			glist[i].count = top; // ������ top�� ����Ű�� ��
			top = i; // i�� ���� top���� �ٲ� 
		}
	
	// 2. �������� 0�� ���� x ����ϰ�, �����ϸ�, x�� ����Ű�� �������� �������� ����
	//    (���� �� ������, top = -1 �� ������)
	for (i = 0; i < n; i++){
		if (top == -1) exit(1); // n�� ���� �� ����ϱ� ���� ���� �� ��� ����Ŭ ����
		
		x = top; // ���� top ���� ����
		top = glist[top].count; // pop: top�� ������ top������ ��ȭ��Ű�鼭 pop��
		printf("%d", x);
		
		// ����������, x�� ����Ű�� ���� �������� ���� & �������� 0�� ���� ���� 
		for (ptr = glist[x].link; ptr; ptr = ptr->link){
			k = ptr->vertex;
			glist[k].count--;
			
			// ���ҽ��״µ� �������� 0�Ǹ� ���ÿ� push
			if (glist[k].count == 0){
				glist[k].count = top; // ������ top�� ����Ű�� ��
				top = k; // k�� ���� top���� �ٲ� 
			} 
		} 
	} 
}
