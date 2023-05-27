// 벨만포드 최단경로 알고리즘
void BellmanFord(int v, int n){ // v: 시작점 
	// 1. k=1일 때, 시작점에서 초기화
	for (int i = 0; i < n; i++) 
		dist[i] = weight[v][i];
		
	// 2. k=2부터 n-1까지 루프 돌면서 각 정점에 대한 최단거리 구하기
	for (int k = 2; k <= n-1; k++)
		for (<시작점 v가 아닌 정점 x> && <진입간선이 최소 1개 이상인 정점 x>)
			for (<그래프 내 간선 <y, x>에 대해>) // y에서 x로 향하는 간선 있음
				if (dist[x] > dist[y] + weight[y][x]) // y 정점 거쳐서 x로 가는 경로가 더 짧을 경우
					dist[x] = dist[y] + weight[y][x]; 
} 
