#include <stdio.h>
int main(void) {
		int N;
		char input[101];
		int result = 0;
		scanf("%d", &N);
		scanf("%s", input);
		for (int i = 0 ; i < N; i++) {
			result += (input[i] - 48);
		}
		printf("%d", result);
		return 0;
}
