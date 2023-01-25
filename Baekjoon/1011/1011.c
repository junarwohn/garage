#include <stdio.h>
int main(void) {
	int T = 0;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		long long n, m;
		scanf("%lld %lld", &n, &m);
		m -= n;
		long long minSq = 0;
		while (m >= (minSq + 1) * (minSq + 1)) {
			minSq++;
		}
		long long result = 2 * minSq - 1;
		m -= (minSq * minSq);
		while (m) {
			if (m / minSq) {
				result += (m / minSq);
				m %= minSq;
			} else {
				minSq--;
			}
		}
		printf("%lld\n", result);
	}
	return 0;
}

