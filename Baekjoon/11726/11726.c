#include <stdio.h>
int fac(int n) {
		int result = 1;
		for (int i = 1; i <= n; i++) {
				result *= i;
		}
		return result;
}

int main(void) {
		int n = 0;
		scanf("%d", &n);
		int k = n / 2;
		int result  = 0;
		for (int i = 0; i <= k; i++) {
				result += (fac(n - i) / fac(n - 2 * i)) /  fac(i);
		}
		printf("%d", result%10007);
		return 0;
}
