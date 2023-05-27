/* 인접행렬 이용 그래프*/
/*
	- 각 노드의 차수 계산하는 데 O(n)
	- 간선의 수 알고자 하거나, 그래프 G가 연결되어 있는가를 알고자 할 때 T(n^2 - n) = O(n^2) 
	- 무방향 그래프는 대칭행렬
	- 희소그래프보다 밀집그래프에 적합 

*/

#define MaxVertices 50

// 그래프 구조체 정의
typedef struct GraphType{
	int n;
	int adjMat[MaxVertices][MaxVertices];
} GraphType;

// 그래프 초기화
void graphInit(GraphType *g){
	int r, c; // row, column
	g->n = 0;
	for(r=0; r<MaxVertices; r++)
		for(c=0; c<MaxVertices; c++)
			g->adjMat[r][c] = 0;
}

// 노드 삽입
void insertVertex(GraphType *g, int v){ // v라는 노드 삽입 
	if ((g->n)+1 > MaxVertices) exit(1); // 최대 노드개수 넘지 않는지 검사
	g->n++; 
}

// 간선 삽입
void insertEdge(GraphType *g, int start, int end){ // start에서 end를 잇는 간선 
	if (start >= g->n || end >= g->n) exit(1); // 범위 오류 검사
	
	// 무방향 그래프는 대칭 행렬 
	g->adjMat[start][end] = 1;
	g->adjMat[end][start] = 1; 
}

// 임의의 정점 v의 진출차수 계산 -> O(n) 
int get_outdeg(GraghType *g, int v){
	int outdeg = 0, i;
	
	for(i = 0; i < g->n; i++)
		outdeg += g->adjMat[v][i];
		
	return outdeg;
} 

// 임의의 정점 v의 진입차수 계산 -> O(n)
int get_indeg(GraphType *g, int v){
	int indeg = 0, i;
	
	for (i = 0; i < g->n; i++)
		indeg += g->adjMat[i][v];
		
	return indeg;
} 
