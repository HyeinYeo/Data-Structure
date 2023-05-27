// 다익스트라 최단경로 알고리즘
 
void shortestPath(int v, int n){ // v: 시작점, n: 그래프 노드 개수 
	int i, x, y;
	// 1. 시작 할 때: 거리 확정된 정점 표시 배열(found), 거리(dist[]) 초기화
	for (i = 0; i < n; i++){
		found[i] = FALSE;
		dist[i] = weight[v][i]; // 시작점에서 각 정점까지들의 거리 
	}
	
	// 2. 시작점 확정
	found[v] = TRUE;
	dist[v] = 0;
	
	// 3. 나머지 정점들에 대해 최단거리 확정
	for (i = 0; i < n-2; i++){ // 시작 정점, 끝 정점은 자동적으로 확정됨 => n-2번만 하면 됨 
		
		// 3-1. 최단거리인 정점 x 찾기 
		x = choose(dist, n, found);
		found[x] = TRUE;
		
		// 3-2. dist값 재조정: 아직 거리 확정 안 된 정점들 중, 
		//                     새로 확정된 x를 경유해서 가는 경로가 기존보다 짧은지 판단해서 갱신
		for (y = 0; y < n; y++){
			if (!found[y])
				if (dist[x] + weight[x][y] < dist[y])
					dist[y] = dist[x] + weight[x][y]
		} 
		 
	} 
}

// 최단거리 정점 x 찾는 함수 
int choose(int dist[], int n, int found[]){
	int i;
	int min; // 최소인 dist값 
	int minv; // dist값 최소인(min) 정점
	
	min = IntMax;
	minv = -1; 
	
	// 아직 거리 확정되지 않은 정점 중 dist[]값 최소인 정점 반환 
	for (i = 0; i < n; i++)
		if ((!found[i]) && dist[i] < min){  
			min = dist[i];
			minv = i; 
		}
	return minv;
}
