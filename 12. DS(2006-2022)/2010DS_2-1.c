#include <stdio.h>

int a[8] = {13, 11, 12, 18, 15, 17, 16, 14};
int cnt = 1;
int partition(int p, int q){
	int pivot = a[p], x, y = p, tmp;
	for (x = p + 1; x <= q; x++){
		if (a[x] < pivot){
			y++;
			tmp = a[x]; a[x] = a[y]; a[y] = tmp;
		}
	}
	tmp = a[p]; a[p] = a[y]; a[y] = tmp;
	printf("partition 함수 %d : y - %d 리턴 \n", cnt, y);
	cnt++;
	return y;
}

void main(){
	int p = 0, q = sizeof(a)/sizeof(int) - 1, mid = (p+q)/2;
	int x = 0;
	while (1){
		x = partition(p, q);
		if (x == mid) break;
		else if(x < mid)
			p = x + 1;
		else
			q = x - 1;
	}
	printf("%d ", a[x]);
}
