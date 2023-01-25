#include <stdio.h>
#include <stdlib.h>
int main(void) {
	int n, x;
	scanf("%d %d", &n, &x);
	int * arr = (int *) malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
			scanf("%d", arr + i);
	}
	for(int i = 0; i < n; i++) {
			if (arr[i] < x) {
					printf("%d ", arr[i]);
			}
	}
	return 0;
}
