#include <stdio.h>
long long nCk(int n, int k) {
	long long result = 1; 
	int diff = (n - k > k) ? k : n - k;
	for (int i = n; i > (n - diff); i--) {
	       result *= i;
	}
	for (int i = 1; i <= diff; i++) {
		result /= i;
	}
	return result;
}	
int main(void) {
	int N, M;
	int T = 0;
	scanf("%d", &T);
	for (int i = 0 ; i < T; i++) {
		scanf("%d %d", &N, &M);
		printf("%lld\n", nCk(M, N));
	}
	return 0;
}
