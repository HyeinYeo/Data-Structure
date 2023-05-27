// �������� 
// o(e + n) 

void topSort(GraphType *g){
	// 0-1. ����, �������� ����� �迭 ����
	int i, x;
	GraphNode *node;
	StackType s;
	int *indeg = (int*)malloc(g->n * sizeof(int)); // ���� ������ �迭ũ�� �迭 ����
	
	// 0-2. �������� �迭 �ʱ�ȭ
	for (i = 0; i < g->n; i++)
		indeg[i] = 0;
		
	// 1. �ʱ� �������� ���
	for (i = 0; i < g->n; i++){
		node = g->adjList[i];
		while (node != NULL){
			indeg[node->vertex]++; // ��ü ��������Ʈ ���鼭 �������� ���� 
			node = node->link;
		}
	}
	
	// 2. �������� 0�� ���� -> ���ÿ� ���
	init(&s);
	for (i = 0; i < g->n; i++)
		if (indeg[i] == 0)
			push(&s, i);
	
	// 3. �������� 0�� ���� x ����ϰ�, �����ϸ鼭, x�� ����Ű�� �������� �������� ����
	//    (���� �� ������)
	while (!is_empty(&s)){
		x = pop(&s);
		printf("%d", x);
		node = g->adjList[x]; // x�� ����Ű�� �������� �������� ���ҽ�Ű��
		while (node != NULL){
			indeg[node->vertex]--;
			
			// ���ҽ��״µ� �� ���� ���������� 0�� �Ǹ� ���ÿ� ����
			if (indeg[node->vertex] == 0)
				push(&s, node->vertex);
			
			node = node->link; 
		} 
	}
	
	free(indeg);
}
