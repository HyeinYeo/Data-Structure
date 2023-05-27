// �ʺ�켱Ž��
#define MaxVertices 50
int visited[MaxVertices];

// 1. ������� O(n^2)
void bfsMat(GraghType *g, int v){
	QueueType q; // ť ���� 
	int x; // ���� ����
	
	init(&q); // ť �ʱ�ȭ
	
	// 1. ���� ���� �湮������ ǥ��
	visited[v] = TRUE;
	printf("%d ", v);
	
	// 2. ť�� ���� ���� ��� �ְ�, ť �� ������ ����
	enqueue(&q, v);
	while (!is_empty(&q)){
		v = dequeue(&q);
		for (x = 0; x < g->n; x++)
			if (!(visited[x]) && g->adjMat[v][x]){ // �湮���� �ʾҰ�, ���������� x���,
				visited[x] = TRUE;
				printf("%d ", x);
				enqueue(&q, x);
			}
	} 
} 


// 2. ��������Ʈ O(n + e)
void bfsList(GraphType *g, int v){
	QueueType q;
	GraphNode *x;
	
	init(&q);
	
	// 1. ���� ���� �湮������ ǥ��
	visited[v] = TRUE;
	printf("%d", v);
	
	// 2. ť�� ���� ���� ��� �ְ�, ť �� ������ ����
	enqueue(&q, v);
	while (!is_empty(&q)){
		v = dequeue(&q);
		for (x = g->adjList[v]; x; x = x->link)
			if (!visited[x->vertex]){
				visited[x->vertex] = TRUE;
				printf("%d", x->vertex);
				enqueue(&q, x->vertex);
			}
	}
}
