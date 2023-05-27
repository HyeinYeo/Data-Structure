// 깊이우선탐색

// 1. 인접행렬 O(n^2)
#define MaxVertices 50
int visited[MaxVertices];

void dfsMat(GraphType *g, int v){
	int x; // 인접 정점
	
	// 1. 시작 정점 방문했음을 표시
	visited[v] = TRUE;
	printf("%d", v);
	
	// 2. 인접 정점에 대해 다시 깊이우선탐색 수행
	for (x = 0; x < n; x++)
		if ((!visited[x]) && g->adjMat[v][x])
			dfsMat(g, x);  
}

// 2. 인접리스트 O(n + e)
void dfsList(GraphType *g, int v){
	GraphNode *x; // 인접정점 노드 가리킬 변수 
	
	// 1. 시작 정점 방문했음을 표시
	visited[v] = TRUE;
	printf("%d", v);
	
	// 2. 인접 정점에 대해 다시 깊이우선탐색 수행
	for (x = g->adjList[v]; x; x = x->link)
		if (!visited[x->vertex])
			dfsList(g, x->vertex);
} 
