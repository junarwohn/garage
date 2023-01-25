#include <stdio.h>
#include <stdlib.h>
int main(void) {
		int N = 0;
		scanf("%d", &N);
		int K = 1;
		int P = 0;
		while (K <= N) {
				K *= 2;
				P++;
		}
		K /= 2;
		char * pnum = malloc(sizeof(char) * P);
		for (int i = 0; i < P; i++) {
				if (N - K >= 0) {
						pnum[i] = 1;
						N -= K;
				} else {
						pnum[i] = 0;
				}
				K /= 2;
		}
		for (int  i = 0; i < P; i++)
				printf("%d", pnum[i]);
		return 0;
}
