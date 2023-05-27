#include <stdio.h>
int max(int arr[], int from, int to) {
    if(from > to) return -1;
    
    int mid = (from + to) / 2;
    int m = max(arr, mid + 1, to);
    
    return (arr[mid] > m) ? arr[mid] : m;
}

int main(){
	int arr[6] = {5, 0, 1, 2, 3, 4};
	printf("%d", max(arr, 0, 5));
}
