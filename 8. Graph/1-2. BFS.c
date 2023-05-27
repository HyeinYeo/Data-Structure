// 너비우선탐색
#define MaxVertices 50
int visited[MaxVertices];

// 1. 인접행렬 O(n^2)
void bfsMat(GraghType *g, int v){
	QueueType q; // 큐 생성 
	int x; // 인접 정점
	
	init(&q); // 큐 초기화
	
	// 1. 시작 정점 방문했음을 표시
	visited[v] = TRUE;
	printf("%d ", v);
	
	// 2. 큐에 인접 정점 모두 넣고, 큐 빌 때까지 빼기
	enqueue(&q, v);
	while (!is_empty(&q)){
		v = dequeue(&q);
		for (x = 0; x < g->n; x++)
			if (!(visited[x]) && g->adjMat[v][x]){ // 방문하지 않았고, 인접정점인 x라면,
				visited[x] = TRUE;
				printf("%d ", x);
				enqueue(&q, x);
			}
	} 
} 


// 2. 인접리스트 O(n + e)
void bfsList(GraphType *g, int v){
	QueueType q;
	GraphNode *x;
	
	init(&q);
	
	// 1. 시작 정점 방문했음을 표시
	visited[v] = TRUE;
	printf("%d", v);
	
	// 2. 큐에 인접 정점 모두 넣고, 큐 빌 때까지 빼기
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
