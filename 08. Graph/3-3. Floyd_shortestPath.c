// Floyd 최단경로 알고리즘
// O(n^3) 
#define MAXV 50

int A[MAXV][MAXV];

void allPaths(int n){
	int i, j, k;
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			A[i][j] = weight[i][j];
	
	for (k = 0; k < n; k++) // 경유할 정점
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
					A[i][j] = A[i][k] + A[k][j]; 
}
