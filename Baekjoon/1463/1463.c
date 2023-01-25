#include <stdio.h>
int list[3000003];
int min(int a, int b) {
		return a > b ? b : a;
}
void find(int N) {
		list[3 * N] = min(list[N] + 1, list[3 * N]);
		list[2 * N] = min(list[N] + 1, list[2 * N]);
		list[N + 1] = min(list[N] + 1, list[N + 1]);
}
int main(void) {
		int N = 0;
		scanf("%d", &N);
		for (int i = 0; i <= N; i++) {
				list[i] = i - 1;
		}
		for (int i = 1; i <= N; i++) {
				find(i);
		}
		printf("%d", list[N]);
		return 0;
}

