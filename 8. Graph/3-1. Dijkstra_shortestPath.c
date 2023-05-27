// ���ͽ�Ʈ�� �ִܰ�� �˰���
 
void shortestPath(int v, int n){ // v: ������, n: �׷��� ��� ���� 
	int i, x, y;
	// 1. ���� �� ��: �Ÿ� Ȯ���� ���� ǥ�� �迭(found), �Ÿ�(dist[]) �ʱ�ȭ
	for (i = 0; i < n; i++){
		found[i] = FALSE;
		dist[i] = weight[v][i]; // ���������� �� ������������ �Ÿ� 
	}
	
	// 2. ������ Ȯ��
	found[v] = TRUE;
	dist[v] = 0;
	
	// 3. ������ �����鿡 ���� �ִܰŸ� Ȯ��
	for (i = 0; i < n-2; i++){ // ���� ����, �� ������ �ڵ������� Ȯ���� => n-2���� �ϸ� �� 
		
		// 3-1. �ִܰŸ��� ���� x ã�� 
		x = choose(dist, n, found);
		found[x] = TRUE;
		
		// 3-2. dist�� ������: ���� �Ÿ� Ȯ�� �� �� ������ ��, 
		//                     ���� Ȯ���� x�� �����ؼ� ���� ��ΰ� �������� ª���� �Ǵ��ؼ� ����
		for (y = 0; y < n; y++){
			if (!found[y])
				if (dist[x] + weight[x][y] < dist[y])
					dist[y] = dist[x] + weight[x][y]
		} 
		 
	} 
}

// �ִܰŸ� ���� x ã�� �Լ� 
int choose(int dist[], int n, int found[]){
	int i;
	int min; // �ּ��� dist�� 
	int minv; // dist�� �ּ���(min) ����
	
	min = IntMax;
	minv = -1; 
	
	// ���� �Ÿ� Ȯ������ ���� ���� �� dist[]�� �ּ��� ���� ��ȯ 
	for (i = 0; i < n; i++)
		if ((!found[i]) && dist[i] < min){  
			min = dist[i];
			minv = i; 
		}
	return minv;
}
