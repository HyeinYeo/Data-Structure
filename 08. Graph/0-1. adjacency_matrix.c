/* ������� �̿� �׷���*/
/*
	- �� ����� ���� ����ϴ� �� O(n)
	- ������ �� �˰��� �ϰų�, �׷��� G�� ����Ǿ� �ִ°��� �˰��� �� �� T(n^2 - n) = O(n^2) 
	- ������ �׷����� ��Ī���
	- ��ұ׷������� �����׷����� ���� 

*/

#define MaxVertices 50

// �׷��� ����ü ����
typedef struct GraphType{
	int n;
	int adjMat[MaxVertices][MaxVertices];
} GraphType;

// �׷��� �ʱ�ȭ
void graphInit(GraphType *g){
	int r, c; // row, column
	g->n = 0;
	for(r=0; r<MaxVertices; r++)
		for(c=0; c<MaxVertices; c++)
			g->adjMat[r][c] = 0;
}

// ��� ����
void insertVertex(GraphType *g, int v){ // v��� ��� ���� 
	if ((g->n)+1 > MaxVertices) exit(1); // �ִ� ��尳�� ���� �ʴ��� �˻�
	g->n++; 
}

// ���� ����
void insertEdge(GraphType *g, int start, int end){ // start���� end�� �մ� ���� 
	if (start >= g->n || end >= g->n) exit(1); // ���� ���� �˻�
	
	// ������ �׷����� ��Ī ��� 
	g->adjMat[start][end] = 1;
	g->adjMat[end][start] = 1; 
}

// ������ ���� v�� �������� ��� -> O(n) 
int get_outdeg(GraghType *g, int v){
	int outdeg = 0, i;
	
	for(i = 0; i < g->n; i++)
		outdeg += g->adjMat[v][i];
		
	return outdeg;
} 

// ������ ���� v�� �������� ��� -> O(n)
int get_indeg(GraphType *g, int v){
	int indeg = 0, i;
	
	for (i = 0; i < g->n; i++)
		indeg += g->adjMat[i][v];
		
	return indeg;
} 
