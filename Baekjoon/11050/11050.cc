#include <iostream>
using namespace std;
int main(void) {
	int N, K;
	int result = 1;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		result *= (N - i);
	}
	for (int i = 1; i <= K; i++) {
		result /= i;
	}
	printf("%d", result);
	return 0;
}
