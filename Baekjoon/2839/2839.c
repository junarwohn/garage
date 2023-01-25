#include <stdio.h>
int main(void) {
		int N;
		scanf("%d", &N);
		int quota = N/5;
		int result  = -1;
		while (quota >= 0) {
				if ((N - quota * 5)%3 == 0) {
						result = quota + (N - quota * 5)/3;
						break;
				}
				quota--;
		}
		printf("%d", result);
		return 0;
}
