#include <stdio.h>
#include <stdlib.h>

long long int * arr;

int main(void) {
	int N = 0;
	scanf("%d", &N);
	if (N == 0) {
		printf("0");
	} else if (N == 1) {
		printf("1");
	} else {
		arr = (long long int *)malloc(sizeof(long long int) * (N + 1));
		arr[0] = 0; arr[1] = 1;
		for (int i = 2; i <= N; i++) {
			arr[i] = arr[i - 1] + arr[i - 2];
		}
		printf("%lld", arr[N]);
	}
	return 0; 
}
