/* 인접리스트 이용 그래프*/
/*
	- 각 정점의 차수 계산하는 데 O(e)
	- 정점 개수 n개, 간선 개수 e개일 때,
		- 무방향 그래프 
			n개의 헤드포인터 배열
			2e개 노드 
	- 밀집그래프보다 희소그래프에 적합 

*/

#define MaxVertices 50

// 그래프 노드 구조체 정의
typedef struct GraphNode{
	int vertex; // 정점 데이터
	struct GraphNode *link;
}GraphNode; 

// 그래프 구조체 정의
typedef struct GraphType{
	int n;
	GraphNode *adjList[MaxVertices]; // 헤드 포인터 배열 
} GraphType;

// 그래프 초기화
void graphInit(GraphType *g){
	int i;
	g->n = 0;
	for (i = 0; i < MaxVertices; i++)
		g->adjList[i] = NULL; 
}

// 정점 삽입
void insertVertex(GraphType *g, int v){ // v라는 노드 삽입 
	if ((g->n)+1 > MaxVertices) exit(1); // 최대 노드개수 넘지 않는지 검사
	g->n++; 
}

// 간선 삽입
void insertEdge(GraphType *g, int x, int y){ // x에서 y를 잇는 간선 
	if (x >= g->n || y >= g->n) exit(1); // 범위 오류 검사
	
	// 1. 인접리스트 노드 생성
	GraphNode *n1, *n2;
	n1 = (GraphNode*)malloc(sizeof(GraphNode));
	n2 = (GraphNode*)malloc(sizeof(GraphNode));
	
	// 2. 노드에 데이터 삽입
	n1->vertex = x;
	n2->vertex = y; 
	
	// 3. 헤더 포인터에 노드 링킹
	n1->link = g->adjList[y];
	g->adjList[y] = n1;
	
	n2->link = g->adjList[x];
	g->adjList[x] = n2;
} 

// 임의의 정점 v의 진출차수 계산 -> O(e) 
int get_outdeg(GraphType *g, int v){
	int outdeg = 0;
	GraphNode *node;
	
	for (node = g->adjList[v]; node; node = node->link)
		outdeg++;
		
	return outdeg;
}

//  임의의 정점 v의 진입차수 계산 -> O(n + e) 
int get_indeg(GraphType *g, int v){
	int indeg = 0, i;
	GraphNode *node;
	
	for (i = 0; i < g->n; i++) // n번 
		for (node = g->adjList[i]; node; node = node->link)
			if (node->vertex == v)
				indeg++;
	
	return indeg;
} 
