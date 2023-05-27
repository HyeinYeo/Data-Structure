// 위상정렬 
// o(e + n) 

void topSort(GraphType *g){
	// 0-1. 스택, 진입차수 기록할 배열 생성
	int i, x;
	GraphNode *node;
	StackType s;
	int *indeg = (int*)malloc(g->n * sizeof(int)); // 정점 개수의 배열크기 배열 생성
	
	// 0-2. 진입차수 배열 초기화
	for (i = 0; i < g->n; i++)
		indeg[i] = 0;
		
	// 1. 초기 진입차수 계산
	for (i = 0; i < g->n; i++){
		node = g->adjList[i];
		while (node != NULL){
			indeg[node->vertex]++; // 전체 인접리스트 돌면서 진입차수 증가 
			node = node->link;
		}
	}
	
	// 2. 진입차수 0인 정점 -> 스택에 담기
	init(&s);
	for (i = 0; i < g->n; i++)
		if (indeg[i] == 0)
			push(&s, i);
	
	// 3. 진입차수 0인 정점 x 출력하고, 삭제하면서, x가 가리키던 정점들의 진입차수 감소
	//    (스택 빌 때까지)
	while (!is_empty(&s)){
		x = pop(&s);
		printf("%d", x);
		node = g->adjList[x]; // x가 가리키던 정점들의 진입차수 감소시키기
		while (node != NULL){
			indeg[node->vertex]--;
			
			// 감소시켰는데 그 정점 진입차수가 0이 되면 스택에 포함
			if (indeg[node->vertex] == 0)
				push(&s, node->vertex);
			
			node = node->link; 
		} 
	}
	
	free(indeg);
}
