// ���̿켱Ž��

// 1. ������� O(n^2)
#define MaxVertices 50
int visited[MaxVertices];

void dfsMat(GraphType *g, int v){
	int x; // ���� ����
	
	// 1. ���� ���� �湮������ ǥ��
	visited[v] = TRUE;
	printf("%d", v);
	
	// 2. ���� ������ ���� �ٽ� ���̿켱Ž�� ����
	for (x = 0; x < n; x++)
		if ((!visited[x]) && g->adjMat[v][x])
			dfsMat(g, x);  
}

// 2. ��������Ʈ O(n + e)
void dfsList(GraphType *g, int v){
	GraphNode *x; // �������� ��� ����ų ���� 
	
	// 1. ���� ���� �湮������ ǥ��
	visited[v] = TRUE;
	printf("%d", v);
	
	// 2. ���� ������ ���� �ٽ� ���̿켱Ž�� ����
	for (x = g->adjList[v]; x; x = x->link)
		if (!visited[x->vertex])
			dfsList(g, x->vertex);
} 
