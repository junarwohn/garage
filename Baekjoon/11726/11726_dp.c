#include <stdio.h>
int dp[10001];
int main(void) {
		dp[1] = 1;
		dp[2] = 2;
		int n = 0;
		scanf("%d", &n);
		for (int i = 3; i <= n; i++) {
				dp[i] = (dp[i -1] + dp[i - 2])%10007;
		}
		printf("%d", dp[n]);
		return 0;
}
