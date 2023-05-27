/* ��������Ʈ �̿� �׷���*/
/*
	- �� ������ ���� ����ϴ� �� O(e)
	- ���� ���� n��, ���� ���� e���� ��,
		- ������ �׷��� 
			n���� ��������� �迭
			2e�� ��� 
	- �����׷������� ��ұ׷����� ���� 

*/

#define MaxVertices 50

// �׷��� ��� ����ü ����
typedef struct GraphNode{
	int vertex; // ���� ������
	struct GraphNode *link;
}GraphNode; 

// �׷��� ����ü ����
typedef struct GraphType{
	int n;
	GraphNode *adjList[MaxVertices]; // ��� ������ �迭 
} GraphType;

// �׷��� �ʱ�ȭ
void graphInit(GraphType *g){
	int i;
	g->n = 0;
	for (i = 0; i < MaxVertices; i++)
		g->adjList[i] = NULL; 
}

// ���� ����
void insertVertex(GraphType *g, int v){ // v��� ��� ���� 
	if ((g->n)+1 > MaxVertices) exit(1); // �ִ� ��尳�� ���� �ʴ��� �˻�
	g->n++; 
}

// ���� ����
void insertEdge(GraphType *g, int x, int y){ // x���� y�� �մ� ���� 
	if (x >= g->n || y >= g->n) exit(1); // ���� ���� �˻�
	
	// 1. ��������Ʈ ��� ����
	GraphNode *n1, *n2;
	n1 = (GraphNode*)malloc(sizeof(GraphNode));
	n2 = (GraphNode*)malloc(sizeof(GraphNode));
	
	// 2. ��忡 ������ ����
	n1->vertex = x;
	n2->vertex = y; 
	
	// 3. ��� �����Ϳ� ��� ��ŷ
	n1->link = g->adjList[y];
	g->adjList[y] = n1;
	
	n2->link = g->adjList[x];
	g->adjList[x] = n2;
} 

// ������ ���� v�� �������� ��� -> O(e) 
int get_outdeg(GraphType *g, int v){
	int outdeg = 0;
	GraphNode *node;
	
	for (node = g->adjList[v]; node; node = node->link)
		outdeg++;
		
	return outdeg;
}

//  ������ ���� v�� �������� ��� -> O(n + e) 
int get_indeg(GraphType *g, int v){
	int indeg = 0, i;
	GraphNode *node;
	
	for (i = 0; i < g->n; i++) // n�� 
		for (node = g->adjList[i]; node; node = node->link)
			if (node->vertex == v)
				indeg++;
	
	return indeg;
} 
