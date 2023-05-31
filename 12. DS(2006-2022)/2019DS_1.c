#include <stdio.h>

void numSubsets(int n, int k){
	int i, result = 1;
	for (i = n; i > n-k; i--)
		result *= i;
	for (i = k; i > 0; i--)
		result /= i;
	printf("numSubsets(%d, %d): %d\n", n, k, result);
	//return result;
}

void numEdges(int n){
	int i, j, total = 0, subset;
	
	for (i = n; i > 0; i--){
		subset = 1;
		for (j = n; j > n-i; j--)
			subset *= j;
		for (j = i; j > 0; j--)
			subset /= j;
		
		total += i * subset;
	}
	printf("numEdges(%d): %d\n", n, total);
	//return total;
}

int main(){
	numSubsets(3, 3); // 1
	numSubsets(3, 2); // 3
	numSubsets(3, 1); // 3
	numSubsets(3, 0); // 1
	numEdges(3); // 12
	
	
	numSubsets(4, 4); // 1
	numSubsets(4, 3); // 4
	numSubsets(4, 2); // 6
	numSubsets(4, 1); // 4
	numSubsets(4, 0); // 1
	numEdges(4); // 32
}
