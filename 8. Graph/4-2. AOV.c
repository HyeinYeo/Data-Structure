// AOV
/* 
	- indeg 배열 => 헤드포인터의 count필드
	- 스택 자료구조 없이 구현하는 위상정렬 
*/
void aov(hnodes glist[] int n){
	int i, j, k;
	int x; // 스택에서 pop해서 출력할 정점 값 담는 변수
	GraphNode *ptr; // 정점 삭제 후 count(진입차수값) 조정하기 위한
	
	// 1. 시작: 진입차수 0인 것 스택에 넣기
	for (i = 0; i < n; i++)
		if (glist[i].count == 0){
			glist[i].count = top; // 이전의 top을 가리키게 함
			top = i; // i를 현재 top으로 바꿈 
		}
	
	// 2. 진입차수 0인 정점 x 출력하고, 삭제하면, x가 가리키던 정점들의 진입차수 감소
	//    (스택 빌 때까지, top = -1 될 때까지)
	for (i = 0; i < n; i++){
		if (top == -1) exit(1); // n개 정점 다 출력하기 전에 스택 다 비면 사이클 존재
		
		x = top; // 현재 top 값을 담음
		top = glist[top].count; // pop: top을 이전의 top값으로 변화시키면서 pop함
		printf("%d", x);
		
		// 삭제했으니, x가 가리키던 정점 진입차수 변경 & 진입차수 0인 정점 감지 
		for (ptr = glist[x].link; ptr; ptr = ptr->link){
			k = ptr->vertex;
			glist[k].count--;
			
			// 감소시켰는데 진입차수 0되면 스택에 push
			if (glist[k].count == 0){
				glist[k].count = top; // 이전의 top을 가리키게 함
				top = k; // k를 현재 top으로 바꿈 
			} 
		} 
	} 
}
