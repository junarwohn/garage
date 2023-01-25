#include <stdio.h>
int nCk(int n, int k) {
		//printf("n %d k %d", n, k);
		int result = 1;
		for (int i = n; i > n - k; i--) {
				result *= i;
		}
		for (int i = 1; i <= k; i++) {
				result /= i;
		}
		return result;
}
int main(void) {
		int N = 0;
		scanf("%d", &N);
		if (N <= 2) {
				printf("1");
		} else {
				N -= 2;
				int k = (N/2 + N%2);
				int result = 0;
				for (int i = 0; i <= k; i++) {
						result += nCk(N + k - i, i);
				}
				printf("%d", result);
		}
		return 0;
}
