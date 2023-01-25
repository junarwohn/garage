#include <stdio.h>
int coord[4000040];
int min(int a, int b) {
		return a > b ? b : a;
}
int main(void) {
		int N, K;
		scanf("%d %d", &N, &K);
		if (N >= K) {
				printf("%d", N - K);
		} else {
			for (int i = 0; i < N; i++) {
					coord[i] = N - i;
			}
			for (int i = N; i <= 2 * K; i++) {
					coord[i] = i - N;
			}
			for (int i = 0; i <= 2 * K; i++) {
					coord[i + 1] = min(coord[i] + 1, coord[i + 1]);
					coord[2 * i] = min(coord[i] + 1, coord[2 * i]);
					coord[i - 1] = min(coord[i] + 1, coord[i - 1]);
			}
			//for (int i = 0; i <= K; i++) {
			//		printf("%d ", coord[i]);
			//}
			printf("%d", coord[K]);
		}
		return 0;
}
