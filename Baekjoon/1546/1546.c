#include <stdio.h>
#include <stdlib.h>
int main(void) {
		int max = 0;
		int N = 0;
		scanf("%d", &N);
		int * arr = (int *)malloc(sizeof(int) * N);
		for (int i = 0; i < N; i++) {
				scanf("%d", arr + i);
		}
		max = arr[0];
		for (int i = 0; i < N; i++) {
				if (max < arr[i]) {
						max = arr[i];
				}
		}
		double sum = 0;
		for (int i = 0; i < N; i++) {
				sum += (double) arr[i] / max * 100; 
		}
		sum /= N;
		if (((int) sum * 1000) % 10 >= 5) {
				sum += 0.01;
		}
		printf("%0.2f", sum);
		return 0;
}
